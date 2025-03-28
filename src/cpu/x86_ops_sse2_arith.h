/* SPDX-License-Identifier: GPL-2.0-or-later */
#include <stdlib.h>
#include <math.h>

static int
opSQRTPD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] = sqrt(cpu_state.XMM[cpu_rm].d2[0]);
        cpu_state.XMM[cpu_reg].d2[1] = sqrt(cpu_state.XMM[cpu_rm].d2[1]);
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src[2];

        SEG_CHECK_READ(cpu_state.ea_seg);
        src[0] = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        src[1] = readmemq(easeg, cpu_state.eaaddr + 8);
        if (cpu_state.abrt)
            return 1;
        double src_real[2];
        src_real[0]       = *(double *) &src[0];
        src_real[1]       = *(double *) &src[1];
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] = sqrt(src_real[0]);
        cpu_state.XMM[cpu_reg].d2[1] = sqrt(src_real[1]);
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(2);
    }
    return 0;
}

static int
opSQRTPD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] = sqrt(cpu_state.XMM[cpu_rm].d2[0]);
        cpu_state.XMM[cpu_reg].d2[1] = sqrt(cpu_state.XMM[cpu_rm].d2[1]);
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src[2];

        SEG_CHECK_READ(cpu_state.ea_seg);
        src[0] = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        src[1] = readmemq(easeg, cpu_state.eaaddr + 8);
        if (cpu_state.abrt)
            return 1;
        double src_real[2];
        src_real[0]       = *(double *) &src[0];
        src_real[1]       = *(double *) &src[1];
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] = sqrt(src_real[0]);
        cpu_state.XMM[cpu_reg].d2[1] = sqrt(src_real[1]);
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(2);
    }
    return 0;
}

static int
opSQRTSD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] = sqrt(cpu_state.XMM[cpu_rm].d2[0]);
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real          = *(double *) &src;
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] = sqrt(src_real);
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(2);
    }
    return 0;
}

static int
opSQRTSD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] = sqrt(cpu_state.XMM[cpu_rm].d2[0]);
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real          = *(double *) &src;
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] = sqrt(src_real);
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(2);
    }
    return 0;
}

static int
opADDPD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] += cpu_state.XMM[cpu_rm].d2[0];
        cpu_state.XMM[cpu_reg].d2[1] += cpu_state.XMM[cpu_rm].d2[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src[2];

        SEG_CHECK_READ(cpu_state.ea_seg);
        src[0] = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        src[1] = readmemq(easeg, cpu_state.eaaddr + 8);
        if (cpu_state.abrt)
            return 1;
        double src_real[2];
        src_real[0] = *(double *) &src[0];
        src_real[1] = *(double *) &src[1];
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] += src_real[0];
        cpu_state.XMM[cpu_reg].d2[1] += src_real[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
    }
    return 0;
}

static int
opADDPD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] += cpu_state.XMM[cpu_rm].d2[0];
        cpu_state.XMM[cpu_reg].d2[1] += cpu_state.XMM[cpu_rm].d2[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src[2];

        SEG_CHECK_READ(cpu_state.ea_seg);
        src[0] = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        src[1] = readmemq(easeg, cpu_state.eaaddr + 8);
        if (cpu_state.abrt)
            return 1;
        double src_real[2];
        src_real[0] = *(double *) &src[0];
        src_real[1] = *(double *) &src[1];
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] += src_real[0];
        cpu_state.XMM[cpu_reg].d2[1] += src_real[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
    }
    return 0;
}

static int
opADDSD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] += cpu_state.XMM[cpu_rm].d2[0];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real = *(double *) &src;
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] += src_real;
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
    }
    return 0;
}

static int
opADDSD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] += cpu_state.XMM[cpu_rm].d2[0];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real = *(double *) &src;
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] += src_real;
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
    }
    return 0;
}

static int
opMULPD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] *= cpu_state.XMM[cpu_rm].d2[0];
        cpu_state.XMM[cpu_reg].d2[1] *= cpu_state.XMM[cpu_rm].d2[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src[2];

        SEG_CHECK_READ(cpu_state.ea_seg);
        src[0] = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        src[1] = readmemq(easeg, cpu_state.eaaddr + 8);
        if (cpu_state.abrt)
            return 1;
        double src_real[2];
        src_real[0] = *(double *) &src[0];
        src_real[1] = *(double *) &src[1];
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] *= src_real[0];
        cpu_state.XMM[cpu_reg].d2[1] *= src_real[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
    }
    return 0;
}

static int
opMULPD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] *= cpu_state.XMM[cpu_rm].d2[0];
        cpu_state.XMM[cpu_reg].d2[1] *= cpu_state.XMM[cpu_rm].d2[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src[2];

        SEG_CHECK_READ(cpu_state.ea_seg);
        src[0] = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        src[1] = readmemq(easeg, cpu_state.eaaddr + 8);
        if (cpu_state.abrt)
            return 1;
        double src_real[2];
        src_real[0] = *(double *) &src[0];
        src_real[1] = *(double *) &src[1];
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] *= src_real[0];
        cpu_state.XMM[cpu_reg].d2[1] *= src_real[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
    }
    return 0;
}

static int
opMULSD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] *= cpu_state.XMM[cpu_rm].d2[0];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real = *(double *) &src;
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] *= src_real;
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
    }
    return 0;
}

static int
opMULSD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] *= cpu_state.XMM[cpu_rm].d2[0];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real = *(double *) &src;
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] *= src_real;
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
    }
    return 0;
}

static int
opSUBPD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] -= cpu_state.XMM[cpu_rm].d2[0];
        cpu_state.XMM[cpu_reg].d2[1] -= cpu_state.XMM[cpu_rm].d2[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src[2];

        SEG_CHECK_READ(cpu_state.ea_seg);
        src[0] = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        src[1] = readmemq(easeg, cpu_state.eaaddr + 8);
        if (cpu_state.abrt)
            return 1;
        double src_real[2];
        src_real[0] = *(double *) &src[0];
        src_real[1] = *(double *) &src[1];
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] -= src_real[0];
        cpu_state.XMM[cpu_reg].d2[1] -= src_real[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
    }
    return 0;
}

static int
opSUBPD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] -= cpu_state.XMM[cpu_rm].d2[0];
        cpu_state.XMM[cpu_reg].d2[1] -= cpu_state.XMM[cpu_rm].d2[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src[2];

        SEG_CHECK_READ(cpu_state.ea_seg);
        src[0] = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        src[1] = readmemq(easeg, cpu_state.eaaddr + 8);
        if (cpu_state.abrt)
            return 1;
        double src_real[2];
        src_real[0] = *(double *) &src[0];
        src_real[1] = *(double *) &src[1];
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] -= src_real[0];
        cpu_state.XMM[cpu_reg].d2[1] -= src_real[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
    }
    return 0;
}

static int
opSUBSD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] -= cpu_state.XMM[cpu_rm].d2[0];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real = *(double *) &src;
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] -= src_real;
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
    }
    return 0;
}

static int
opSUBSD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] -= cpu_state.XMM[cpu_rm].d2[0];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real = *(double *) &src;
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] -= src_real;
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
    }
    return 0;
}

static int
opMINPD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_16(fetchdat);
    SSE_REG src;
    struct softfloat_status_t status = mxcsr_to_softfloat_status_word();
    SSE_GETSRC();
    cpu_state.XMM[cpu_reg].d[0] = f64_min(cpu_state.XMM[cpu_reg].d[0], src.d[0], &status);
    cpu_state.XMM[cpu_reg].d[1] = f64_min(cpu_state.XMM[cpu_reg].d[1], src.d[1], &status);
    /*softfloat_status_word_to_mxcsr(status);
    int unmasked = (~cpu_state.mxcsr >> 7) & 0x3f;
    if ((cpu_state.mxcsr & 0x3f) & (unmasked & 0x3f)) {
        if (cr4 & CR4_OSXMMEXCPT)
            x86_int(0x13);
        //ILLEGAL_ON(!(cr4 & CR4_OSXMMEXCPT));
    }*/
    return 0;
}

static int
opMINPD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_32(fetchdat);
    SSE_REG src;
    struct softfloat_status_t status = mxcsr_to_softfloat_status_word();
    SSE_GETSRC();
    cpu_state.XMM[cpu_reg].d[0] = f64_min(cpu_state.XMM[cpu_reg].d[0], src.d[0], &status);
    cpu_state.XMM[cpu_reg].d[1] = f64_min(cpu_state.XMM[cpu_reg].d[1], src.d[1], &status);
    /*softfloat_status_word_to_mxcsr(status);
    int unmasked = (~cpu_state.mxcsr >> 7) & 0x3f;
    if ((cpu_state.mxcsr & 0x3f) & (unmasked & 0x3f)) {
        if (cr4 & CR4_OSXMMEXCPT)
            x86_int(0x13);
        //ILLEGAL_ON(!(cr4 & CR4_OSXMMEXCPT));
    }*/
    return 0;
}

static int
opMINSD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        cpu_state.XMM[cpu_reg].d2[0] = fmin(cpu_state.XMM[cpu_rm].d2[0], cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real          = *(double *) &src;
        cpu_state.XMM[cpu_reg].d2[0] = fmin(cpu_state.XMM[cpu_reg].d2[0], src_real);
    }
    return 0;
}

static int
opMINSD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        cpu_state.XMM[cpu_reg].d2[0] = fmin(cpu_state.XMM[cpu_rm].d2[0], cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real          = *(double *) &src;
        cpu_state.XMM[cpu_reg].d2[0] = fmin(cpu_state.XMM[cpu_reg].d2[0], src_real);
    }
    return 0;
}

static int
opDIVPD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] /= cpu_state.XMM[cpu_rm].d2[0];
        cpu_state.XMM[cpu_reg].d2[1] /= cpu_state.XMM[cpu_rm].d2[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src[2];

        SEG_CHECK_READ(cpu_state.ea_seg);
        src[0] = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        src[1] = readmemq(easeg, cpu_state.eaaddr + 8);
        if (cpu_state.abrt)
            return 1;
        double src_real[2];
        src_real[0] = *(double *) &src[0];
        src_real[1] = *(double *) &src[1];
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] /= src_real[0];
        cpu_state.XMM[cpu_reg].d2[1] /= src_real[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
    }
    return 0;
}

static int
opDIVPD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] /= cpu_state.XMM[cpu_rm].d2[0];
        cpu_state.XMM[cpu_reg].d2[1] /= cpu_state.XMM[cpu_rm].d2[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src[2];

        SEG_CHECK_READ(cpu_state.ea_seg);
        src[0] = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        src[1] = readmemq(easeg, cpu_state.eaaddr + 8);
        if (cpu_state.abrt)
            return 1;
        double src_real[2];
        src_real[0] = *(double *) &src[0];
        src_real[1] = *(double *) &src[1];
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] /= src_real[0];
        cpu_state.XMM[cpu_reg].d2[1] /= src_real[1];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[1]);
    }
    return 0;
}

static int
opDIVSD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] /= cpu_state.XMM[cpu_rm].d2[0];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real = *(double *) &src;
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] /= src_real;
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
    }
    return 0;
}

static int
opDIVSD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    feclearexcept(FE_ALL_EXCEPT);
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] /= cpu_state.XMM[cpu_rm].d2[0];
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real = *(double *) &src;
        fesetround(rounding_modes[(cpu_state.mxcsr >> 13) & 3]);
        cpu_state.XMM[cpu_reg].d2[0] /= src_real;
        fesetround(FE_TONEAREST);
        //check_sse_execeptions_double(&cpu_state.XMM[cpu_reg].d2[0]);
    }
    return 0;
}

static int
opMAXPD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_16(fetchdat);
    SSE_REG src;
    struct softfloat_status_t status = mxcsr_to_softfloat_status_word();
    SSE_GETSRC();
    cpu_state.XMM[cpu_reg].d[0] = f64_max(cpu_state.XMM[cpu_reg].d[0], src.d[0], &status);
    cpu_state.XMM[cpu_reg].d[1] = f64_max(cpu_state.XMM[cpu_reg].d[1], src.d[1], &status);
    /*softfloat_status_word_to_mxcsr(status);
    int unmasked = (~cpu_state.mxcsr >> 7) & 0x3f;
    if ((cpu_state.mxcsr & 0x3f) & (unmasked & 0x3f)) {
        if (cr4 & CR4_OSXMMEXCPT)
            x86_int(0x13);
        //ILLEGAL_ON(!(cr4 & CR4_OSXMMEXCPT));
    }*/
    return 0;
}

static int
opMAXPD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_32(fetchdat);
    SSE_REG src;
    struct softfloat_status_t status = mxcsr_to_softfloat_status_word();
    SSE_GETSRC();
    cpu_state.XMM[cpu_reg].d[0] = f64_max(cpu_state.XMM[cpu_reg].d[0], src.d[0], &status);
    cpu_state.XMM[cpu_reg].d[1] = f64_max(cpu_state.XMM[cpu_reg].d[1], src.d[1], &status);
    /*softfloat_status_word_to_mxcsr(status);
    int unmasked = (~cpu_state.mxcsr >> 7) & 0x3f;
    if ((cpu_state.mxcsr & 0x3f) & (unmasked & 0x3f)) {
        if (cr4 & CR4_OSXMMEXCPT)
            x86_int(0x13);
        //ILLEGAL_ON(!(cr4 & CR4_OSXMMEXCPT));
    }*/
    return 0;
}

static int
opMAXSD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_16(fetchdat);
    if (cpu_mod == 3) {
        cpu_state.XMM[cpu_reg].d2[0] = fmax(cpu_state.XMM[cpu_rm].d2[0], cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real          = *(double *) &src;
        cpu_state.XMM[cpu_reg].d2[0] = fmax(cpu_state.XMM[cpu_reg].d2[0], src_real);
    }
    return 0;
}

static int
opMAXSD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_32(fetchdat);
    if (cpu_mod == 3) {
        cpu_state.XMM[cpu_reg].d2[0] = fmax(cpu_state.XMM[cpu_rm].d2[0], cpu_state.XMM[cpu_reg].d2[0]);
        CLOCK_CYCLES(1);
    } else {
        uint64_t src;

        SEG_CHECK_READ(cpu_state.ea_seg);
        src = readmemq(easeg, cpu_state.eaaddr);
        if (cpu_state.abrt)
            return 1;
        double src_real;
        src_real          = *(double *) &src;
        cpu_state.XMM[cpu_reg].d2[0] = fmax(cpu_state.XMM[cpu_reg].d2[0], src_real);
    }
    return 0;
}

/* Comparison predicate for CMPSD/CMPPD instructions */
static float64_compare_method compare64[8] = {
  f64_eq_ordered_quiet,
  f64_lt_ordered_signalling,
  f64_le_ordered_signalling,
  f64_unordered_quiet,
  f64_neq_unordered_quiet,
  f64_nlt_unordered_signalling,
  f64_nle_unordered_signalling,
  f64_ordered_quiet
};

static int
opCMPPD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_16(fetchdat);
    SSE_REG src;
    struct softfloat_status_t status = mxcsr_to_softfloat_status_word();
    SSE_GETSRC();
    uint8_t  imm = getbyte();
    cpu_state.XMM[cpu_reg].q[0] = compare64[imm & 7](cpu_state.XMM[cpu_reg].d[0], src.d[0], &status) ? ~0ull : 0;
    cpu_state.XMM[cpu_reg].q[1] = compare64[imm & 7](cpu_state.XMM[cpu_reg].d[1], src.d[1], &status) ? ~0ull : 0;
    return 0;
}

static int
opCMPPD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_32(fetchdat);
    uint8_t  imm = getbyte();
    SSE_REG src;
    struct softfloat_status_t status = mxcsr_to_softfloat_status_word();
    SSE_GETSRC();
    cpu_state.XMM[cpu_reg].q[0] = compare64[imm & 7](cpu_state.XMM[cpu_reg].d[0], src.d[0], &status) ? ~0ull : 0;
    cpu_state.XMM[cpu_reg].q[1] = compare64[imm & 7](cpu_state.XMM[cpu_reg].d[1], src.d[1], &status) ? ~0ull : 0;
    return 0;
}

static int
opCMPSD_xmm_xmm_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_16(fetchdat);
    uint8_t  imm = getbyte();
    SSE_REG src;
    struct softfloat_status_t status = mxcsr_to_softfloat_status_word();
    SSE_GETSRC();
    cpu_state.XMM[cpu_reg].q[0] = compare64[imm & 7](cpu_state.XMM[cpu_reg].d[0], src.d[0], &status) ? ~0ull : 0;
    return 0;
}

static int
opCMPSD_xmm_xmm_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    fetch_ea_32(fetchdat);
    uint8_t  imm = getbyte();
    SSE_REG src;
    struct softfloat_status_t status = mxcsr_to_softfloat_status_word();
    SSE_GETSRC();
    cpu_state.XMM[cpu_reg].q[0] = compare64[imm & 7](cpu_state.XMM[cpu_reg].d[0], src.d[0], &status) ? ~0ull : 0;
    return 0;
}
