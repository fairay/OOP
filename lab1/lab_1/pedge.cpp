#include "pedge.h"

// Edge by points functions
pedge_t create_pedge(point_t p1, point_t p2)
{
    pedge_t pedge;
    pedge.p1 = p1;
    pedge.p2 = p2;
    return pedge;
}

point_t pedge_get_p1(const pedge_t &pedge)
{
    return pedge.p1;
}
point_t pedge_get_p2(const pedge_t &pedge)
{
    return pedge.p2;
}

pedge_t trans_pedge(err_t &code, const pedge_t &pedge, const proj_params_t &pr_par)
{
    point_t p1 = pedge_get_p1(pedge);
    point_t p2 = pedge_get_p2(pedge);

    p1 = trans_point(code, p1, pr_par);
    if (!code)   p2 = trans_point(code, p2, pr_par);
    return create_pedge(p1, p2);
}

/// Draw point edge
err_t draw_pedge(draw_t &draw, const pedge_t &pedge)
{
    point_t p1, p2;
    p1 = pedge_get_p1(pedge);
    p2 = pedge_get_p2(pedge);
    return draw_line(draw, p1, p2);
}
