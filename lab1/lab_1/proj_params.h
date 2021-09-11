#ifndef PROJ_PARAMS_CPP_H
#define PROJ_PARAMS_CPP_H

#include "defines.h"
#include "point.h"


typedef struct
{
    double xy_min;
    double xy_max;
    unsigned int canv_x, canv_y;
    point_t view_p;
} proj_params_t;

proj_params_t create_params(void);

void set_canvas_xy(proj_params_t &par, unsigned int canv_x, unsigned int canv_y);
void set_point_view(proj_params_t &par, const point_t &view_p);
void set_xy_range(proj_params_t &par, double xy_min, double xy_max);

double get_xy_max(const proj_params_t &par);
double get_xy_min(const proj_params_t &par);
unsigned int get_canv_x(const proj_params_t &par);
unsigned int get_canv_y(const proj_params_t &par);

err_t check_params_valid(const proj_params_t &par);
err_t set_params(proj_params_t &dest, const proj_params_t &source);

point_t trans_point(err_t &err, const point_t &p, const proj_params_t &pr_par);

err_t draw_axis(draw_t &draw, const proj_params_t &view_par);
#endif // PROJ_PARAMS_CPP_H
