#ifndef PEDGE_C_H
#define PEDGE_C_H

#include "edge.h"
#include "point.h"
#include "proj_params.h"

typedef struct
{
    point_t p1, p2;
} pedge_t;

pedge_t create_pedge(point_t p1, point_t p2);

point_t pedge_get_p1(const pedge_t &pedge);
point_t pedge_get_p2(const pedge_t &pedge);

pedge_t trans_pedge(err_t &err, const pedge_t &pedge, const proj_params_t &pr_par);

err_t draw_pedge(draw_t &draw, const pedge_t &pedge);
#endif // PEDGE_C_H
