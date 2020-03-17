#ifndef POINTS_DATA_H
#define POINTS_DATA_H

#include "point_arr.h"
#include "proj_params.h"
#include "pedge.h"

typedef struct
{
    point_arr_t arr;
    unsigned int n;
}pdata_t;

pdata_t init_pdata(void);
void delete_pdata(pdata_t &pdata);

unsigned int get_points_n(const pdata_t &pdata);
err_t get_points_i(point_t &p, const pdata_t &pdata, unsigned int i);
pedge_t get_points_pedge(const pdata_t &pdata, const edge_t &e);

err_t move_points(pdata_t &pdata, const transform_t &trans);
err_t scale_points(pdata_t &pdata, const transform_t &trans);
err_t rotate_points(pdata_t &pdata, const transform_t &trans);

err_t draw_points(draw_t &draw, const pdata_t &pdata, const proj_params_t &view_par);

err_t fscan_pdata(FILE *f, pdata_t &pdata);

#endif // POINTS_DATA_H
