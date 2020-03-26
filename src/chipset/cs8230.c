/*
 * 86Box	A hypervisor and IBM PC system emulator that specializes in
 *		running old operating systems and software designed for IBM
 *		PC systems and compatibles from 1981 through fairly recent
 *		system designs based on the PCI bus.
 *
 *		This file is part of the 86Box distribution.
 *
 *		Emulation of C&T CS8230 ("386/AT") chipset.
 *
 *
 *
 * Authors:	Sarah Walker, <http://pcem-emulator.co.uk/>
 *
 *		Copyright 2020 Sarah Walker.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "86box.h"
#include "cpu.h"
#include "timer.h"
#include "86box_io.h"
#include "device.h"
#include "mem.h"
#include "fdd.h"
#include "fdc.h"
#include "chipset.h"


static struct
{
        int idx;
        uint8_t regs[256];
} cs8230;

static void shadow_control(uint32_t addr, uint32_t size, int state)
{
//        pclog("shadow_control: addr=%08x size=%04x state=%02x\n", addr, size, state);
        switch (state)
        {
                case 0x00:
                mem_set_mem_state(addr, size, MEM_READ_INTERNAL | MEM_WRITE_INTERNAL);
                break;
                case 0x01:
                mem_set_mem_state(addr, size, MEM_READ_EXTANY | MEM_WRITE_INTERNAL);
                break;
                case 0x10:
                mem_set_mem_state(addr, size, MEM_READ_INTERNAL | MEM_WRITE_EXTANY);
                break;
                case 0x11:
                mem_set_mem_state(addr, size, MEM_READ_EXTANY | MEM_WRITE_EXTANY);
                break;
        }
        flushmmucache_nopc();
}


static void rethink_shadow_mappings(void)
{
        int c;
        
        for (c = 0; c < 4*8; c++) /*Addresses 40000-bffff in 16k blocks*/
        {
                if (cs8230.regs[0xa + (c >> 3)] & (1 << (c & 7)))
                        mem_set_mem_state(0x40000 + c*0x4000, 0x4000, MEM_READ_EXTANY | MEM_WRITE_EXTANY); /*IO channel*/
                else
                        mem_set_mem_state(0x40000 + c*0x4000, 0x4000, MEM_READ_INTERNAL | MEM_WRITE_INTERNAL); /*System board*/
        }
        for (c = 0; c < 2*8; c++) /*Addresses c0000-fffff in 16k blocks. System board ROM can be mapped here*/
        {
                if (cs8230.regs[0xe + (c >> 3)] & (1 << (c & 7)))
                        mem_set_mem_state(0xc0000 + c*0x4000, 0x4000, MEM_READ_EXTANY | MEM_WRITE_EXTANY); /*IO channel*/
                else
                        shadow_control(0xc0000 + c*0x4000, 0x4000, (cs8230.regs[9] >> (3-(c >> 2))) & 0x11);
        }
}

static uint8_t cs8230_read(uint16_t port, void *p)
{
        uint8_t ret = 0xff;
        
        if (port & 1)
        {
                switch (cs8230.idx)
                {
                        case 0x04: /*82C301 ID/version*/
                        ret = cs8230.regs[cs8230.idx] & ~0xe3;
                        break;

                        case 0x08: /*82C302 ID/Version*/
                        ret = cs8230.regs[cs8230.idx] & ~0xe0;
                        break;
                        
                        case 0x05: case 0x06: /*82C301 registers*/
                        case 0x09: case 0x0a: case 0x0b: case 0x0c: /*82C302 registers*/
                        case 0x0d: case 0x0e: case 0x0f: 
                        case 0x10: case 0x11: case 0x12: case 0x13:
                        case 0x28: case 0x29: case 0x2a:
                        ret = cs8230.regs[cs8230.idx];
                        break;
                }
        }
        
        return ret;
}

static void cs8230_write(uint16_t port, uint8_t val, void *p)
{
        if (!(port & 1))
                cs8230.idx = val;
        else
        {
//                pclog("cs8230_write: reg=%02x val=%02x\n", cs8230.idx, val);
                cs8230.regs[cs8230.idx] = val;
                switch (cs8230.idx)
                {
                        case 0x09: /*RAM/ROM Configuration in boot area*/
                        case 0x0a: case 0x0b: case 0x0c: case 0x0d: case 0x0e: case 0x0f: /*Address maps*/
//                        rethink_shadow_mappings();
                        break;
                }
        }
}

static void * cs8230_init(const device_t *info)
{
        memset(&cs8230, 0, sizeof(cs8230));
        
        io_sethandler(0x0022, 0x0002,
                        cs8230_read, NULL, NULL,
                        cs8230_write, NULL, NULL,
                        NULL);
}

const device_t cs8230_device = {
    "C&T CS8230 (386/AT)",
    0,
    0,
    cs8230_init, NULL, NULL,
    NULL, NULL, NULL,
    NULL
};