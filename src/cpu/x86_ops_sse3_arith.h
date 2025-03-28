/* SPDX-License-Identifier: GPL-2.0-or-later */
static int
opHADDPS_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_16(fetchdat);
    SSE_GETSRC();

    tmp.f2[0] = src.f2[0] + src.f2[1];
    tmp.f2[1] = src.f2[2] + src.f2[3];
    tmp.f2[2] = cpu_state.XMM[cpu_reg].f2[0] + cpu_state.XMM[cpu_reg].f2[1];
    tmp.f2[3] = cpu_state.XMM[cpu_reg].f2[2] + cpu_state.XMM[cpu_reg].f2[3];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}

static int
opHADDPS_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_32(fetchdat);
    SSE_GETSRC();

    tmp.f2[0] = src.f2[0] + src.f2[1];
    tmp.f2[1] = src.f2[2] + src.f2[3];
    tmp.f2[2] = cpu_state.XMM[cpu_reg].f2[0] + cpu_state.XMM[cpu_reg].f2[1];
    tmp.f2[3] = cpu_state.XMM[cpu_reg].f2[2] + cpu_state.XMM[cpu_reg].f2[3];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}

static int
opHADDPD_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_16(fetchdat);
    SSE_GETSRC();

    tmp.d2[0] = src.d2[0] + src.d2[1];
    tmp.d2[1] = cpu_state.XMM[cpu_reg].d2[0] + cpu_state.XMM[cpu_reg].d2[1];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}

static int
opHADDPD_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_32(fetchdat);
    SSE_GETSRC();

    tmp.d2[0] = src.d2[0] + src.d2[1];
    tmp.d2[1] = cpu_state.XMM[cpu_reg].d2[0] + cpu_state.XMM[cpu_reg].d2[1];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}

static int
opHSUBPS_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_16(fetchdat);
    SSE_GETSRC();

    tmp.f2[0] = src.f2[0] - src.f2[1];
    tmp.f2[1] = src.f2[2] - src.f2[3];
    tmp.f2[2] = cpu_state.XMM[cpu_reg].f2[0] - cpu_state.XMM[cpu_reg].f2[1];
    tmp.f2[3] = cpu_state.XMM[cpu_reg].f2[2] - cpu_state.XMM[cpu_reg].f2[3];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}

static int
opHSUBPS_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_32(fetchdat);
    SSE_GETSRC();

    tmp.f2[0] = src.f2[0] - src.f2[1];
    tmp.f2[1] = src.f2[2] - src.f2[3];
    tmp.f2[2] = cpu_state.XMM[cpu_reg].f2[0] - cpu_state.XMM[cpu_reg].f2[1];
    tmp.f2[3] = cpu_state.XMM[cpu_reg].f2[2] - cpu_state.XMM[cpu_reg].f2[3];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}

static int
opHSUBPD_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_16(fetchdat);
    SSE_GETSRC();

    tmp.d2[0] = src.d2[0] - src.d2[1];
    tmp.d2[1] = cpu_state.XMM[cpu_reg].d2[0] - cpu_state.XMM[cpu_reg].d2[1];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}

static int
opHSUBPD_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_32(fetchdat);
    SSE_GETSRC();

    tmp.d2[0] = src.d2[0] - src.d2[1];
    tmp.d2[1] = cpu_state.XMM[cpu_reg].d2[0] - cpu_state.XMM[cpu_reg].d2[1];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}

static int
opADDSUBPS_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_16(fetchdat);
    SSE_GETSRC();

    tmp.f2[0] = cpu_state.XMM[cpu_reg].f2[0] - src.f2[0];
    tmp.f2[1] = cpu_state.XMM[cpu_reg].f2[1] + src.f2[1];
    tmp.f2[2] = cpu_state.XMM[cpu_reg].f2[2] - src.f2[2];
    tmp.f2[3] = cpu_state.XMM[cpu_reg].f2[3] + src.f2[3];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}

static int
opADDSUBPS_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_32(fetchdat);
    SSE_GETSRC();

    tmp.f2[0] = cpu_state.XMM[cpu_reg].f2[0] - src.f2[0];
    tmp.f2[1] = cpu_state.XMM[cpu_reg].f2[1] + src.f2[1];
    tmp.f2[2] = cpu_state.XMM[cpu_reg].f2[2] - src.f2[2];
    tmp.f2[3] = cpu_state.XMM[cpu_reg].f2[3] + src.f2[3];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}

static int
opADDSUBPD_a16(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_16(fetchdat);
    SSE_GETSRC();

    tmp.d2[0] = cpu_state.XMM[cpu_reg].d2[0] - src.d2[0];
    tmp.d2[1] = cpu_state.XMM[cpu_reg].d2[1] + src.d2[1];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}

static int
opADDSUBPD_a32(uint32_t fetchdat)
{
    SSE_ENTER();
    SSE_REG src, tmp;

    fetch_ea_32(fetchdat);
    SSE_GETSRC();

    tmp.d2[0] = cpu_state.XMM[cpu_reg].d2[0] - src.d2[0];
    tmp.d2[1] = cpu_state.XMM[cpu_reg].d2[1] + src.d2[1];
    cpu_state.XMM[cpu_reg].q[0] = tmp.q[0];
    cpu_state.XMM[cpu_reg].q[1] = tmp.q[1];
    return 0;
}