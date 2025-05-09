/*
 * 86Box    A hypervisor and IBM PC system emulator that specializes in
 *          running old operating systems and software designed for IBM
 *          PC systems and compatibles from 1981 through fairly recent
 *          system designs based on the PCI bus.
 *
 *          This file is part of the 86Box distribution.
 *
 *          Emulation of the EEPROM on select ATI cards.
 *
 *
 *
 * Authors: Sarah Walker, <https://pcem-emulator.co.uk/>
 *          Miran Grca, <mgrca8@gmail.com>
 *
 *          Copyright 2008-2020 Sarah Walker.
 *          Copyright 2016-2020 Miran Grca.
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>
#include <86box/86box.h>
#include <86box/device.h>
#include <86box/mem.h>
#include <86box/timer.h>
#include <86box/nvr.h>
#include <86box/vid_ati_eeprom.h>
#include <86box/plat_fallthrough.h>

void
ati_eeprom_load(ati_eeprom_t *eeprom, char *fn, int type)
{
    FILE *fp;
    int   size;
    eeprom->type = type;
    strncpy(eeprom->fn, fn, sizeof(eeprom->fn) - 1);
    fp   = nvr_fopen(eeprom->fn, "rb");
    size = eeprom->type ? 512 : 128;
    if (!fp) {
        memset(eeprom->data, 0xff, size);
        return;
    }
    if (fread(eeprom->data, 1, size, fp) != size)
        memset(eeprom->data, 0, size);

    fclose(fp);
}

void
ati_eeprom_load_mach8(ati_eeprom_t *eeprom, char *fn, int mca)
{
    FILE *fp;
    int   size;
    eeprom->type = 0;
    strncpy(eeprom->fn, fn, sizeof(eeprom->fn) - 1);
    fp   = nvr_fopen(eeprom->fn, "rb");
    size = 128;
    if (!fp) {
        if (mca) {
            (void) fseek(fp, 2L, SEEK_SET);
            memset(eeprom->data + 2, 0xff, size - 2);
            fp = nvr_fopen(eeprom->fn, "wb");
            fwrite(eeprom->data, 1, size, fp);
            fclose(fp);
        } else
            memset(eeprom->data, 0xff, size);
        return;
    }
    if (fread(eeprom->data, 1, size, fp) != size)
        memset(eeprom->data, 0, size);

    fclose(fp);
}

void
ati_eeprom_load_mach8_vga(ati_eeprom_t *eeprom, char *fn)
{
    FILE *fp;
    int   size;
    eeprom->type = 0;
    strncpy(eeprom->fn, fn, sizeof(eeprom->fn) - 1);
    fp   = nvr_fopen(eeprom->fn, "rb");
    size = 128;
    if (!fp) { /*The ATI Graphics Ultra bios expects a fresh nvram zero'ed at boot time otherwise
            it would hang the machine.*/
        memset(eeprom->data, 0, size);
        fp = nvr_fopen(eeprom->fn, "wb");
        fwrite(eeprom->data, 1, size, fp);
        fclose(fp);
        return;
    }
    if (fread(eeprom->data, 1, size, fp) != size)
        memset(eeprom->data, 0, size);

    fclose(fp);
}

void
ati_eeprom_save(ati_eeprom_t *eeprom)
{
    FILE *fp = nvr_fopen(eeprom->fn, "wb");
    if (!fp)
        return;
    fwrite(eeprom->data, 1, eeprom->type ? 512 : 128, fp);
    fclose(fp);
}

void
ati_eeprom_write(ati_eeprom_t *eeprom, int ena, int clk, int dat)
{
    if (!ena)
        eeprom->out = 1;

    if (clk && !eeprom->oldclk) {
        if (ena && !eeprom->oldena) {
            eeprom->state  = EEPROM_WAIT;
            eeprom->opcode = 0;
            eeprom->count  = 3;
            eeprom->out    = 1;
        } else if (ena) {
            switch (eeprom->state) {
                case EEPROM_WAIT:
                    if (!dat)
                        break;
                    eeprom->state = EEPROM_OPCODE;
                    fallthrough;
                case EEPROM_OPCODE:
                    eeprom->opcode = (eeprom->opcode << 1) | (dat ? 1 : 0);
                    eeprom->count--;
                    if (!eeprom->count) {
                        switch (eeprom->opcode) {
                            case EEPROM_OP_WRITE:
                                eeprom->count = eeprom->type ? 24 : 22;
                                eeprom->state = EEPROM_INPUT;
                                eeprom->dat   = 0;
                                break;
                            case EEPROM_OP_READ:
                                eeprom->count = eeprom->type ? 8 : 6;
                                eeprom->state = EEPROM_INPUT;
                                eeprom->dat   = 0;
                                break;
                            case EEPROM_OP_EW:
                                eeprom->count = 2;
                                eeprom->state = EEPROM_INPUT;
                                eeprom->dat   = 0;
                                break;
                            case EEPROM_OP_ERASE:
                                eeprom->count = eeprom->type ? 8 : 6;
                                eeprom->state = EEPROM_INPUT;
                                eeprom->dat   = 0;
                                break;

                            default:
                                break;
                        }
                    }
                    break;

                case EEPROM_INPUT:
                    eeprom->dat = (eeprom->dat << 1) | (dat ? 1 : 0);
                    eeprom->count--;
                    if (!eeprom->count) {
                        switch (eeprom->opcode) {
                            case EEPROM_OP_WRITE:
                                if (!eeprom->wp) {
                                    eeprom->data[(eeprom->dat >> 16) & (eeprom->type ? 255 : 63)] = eeprom->dat & 0xffff;
                                    ati_eeprom_save(eeprom);
                                }
                                eeprom->state = EEPROM_IDLE;
                                eeprom->out   = 1;
                                break;

                            case EEPROM_OP_READ:
                                eeprom->count = 17;
                                eeprom->state = EEPROM_OUTPUT;
                                eeprom->dat   = eeprom->data[eeprom->dat];
                                break;
                            case EEPROM_OP_EW:
                                switch (eeprom->dat) {
                                    case EEPROM_OP_EWDS:
                                        eeprom->wp = 1;
                                        break;
                                    case EEPROM_OP_WRAL:
                                        eeprom->opcode = EEPROM_OP_WRALMAIN;
                                        eeprom->count  = 20;
                                        break;
                                    case EEPROM_OP_ERAL:
                                        if (!eeprom->wp) {
                                            memset(eeprom->data, 0xff, 128);
                                            ati_eeprom_save(eeprom);
                                        }
                                        break;
                                    case EEPROM_OP_EWEN:
                                        eeprom->wp = 0;
                                        break;

                                    default:
                                        break;
                                }
                                eeprom->state = EEPROM_IDLE;
                                eeprom->out   = 1;
                                break;

                            case EEPROM_OP_ERASE:
                                if (!eeprom->wp) {
                                    eeprom->data[eeprom->dat] = 0xffff;
                                    ati_eeprom_save(eeprom);
                                }
                                eeprom->state = EEPROM_IDLE;
                                eeprom->out   = 1;
                                break;

                            case EEPROM_OP_WRALMAIN:
                                if (!eeprom->wp) {
                                    for (uint16_t c = 0; c < 256; c++)
                                        eeprom->data[c] = eeprom->dat;
                                    ati_eeprom_save(eeprom);
                                }
                                eeprom->state = EEPROM_IDLE;
                                eeprom->out   = 1;
                                break;

                            default:
                                break;
                        }
                    }
                    break;

                default:
                    break;
            }
        }
        eeprom->oldena = ena;
    } else if (!clk && eeprom->oldclk) {
        if (ena) {
            switch (eeprom->state) {
                case EEPROM_OUTPUT:
                    eeprom->out = (eeprom->dat & 0x10000) ? 1 : 0;
                    eeprom->dat <<= 1;
                    eeprom->count--;
                    if (!eeprom->count) {
                        eeprom->state = EEPROM_IDLE;
                    }
                    break;

                default:
                    break;
            }
        }
    }
    eeprom->oldclk = clk;
}

int
ati_eeprom_read(ati_eeprom_t *eeprom)
{
    return eeprom->out;
}
