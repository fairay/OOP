#ifndef POINT_C_H
#define POINT_C_H

#include <stdio.h>
#include "defines.h"
#include "draw_module.h"

#include "transform_params.h"
typedef struct
{
    double x, y, z;
} point_t;

point_t create_point(double x, double y, double z);

double pget_x(const point_t &p);
double pget_y(const point_t &p);
double pget_z(const point_t &p);

err_t project_point(point_t &p, const point_t &view);
err_t plot_point(point_t &p, double xy_min, double xy_max);
err_t canvas_point(point_t &p, unsigned int canv_x, unsigned int canv_y);

void move_point(point_t &p, const point_t &move_vec);
void scale_point(point_t &p, const point_t &cen, const scale_t &scale);
void rotate_point(point_t &p, const point_t &cen, const angle_t &angels);

err_t draw_point(draw_t &draw, const point_t &p);
err_t draw_axis_line(draw_t &draw, const point_t &p1, const point_t &p2);
err_t draw_line(draw_t &draw, const point_t &p1, const point_t &p2);

err_t fscan_point(FILE *f, point_t &p);
#endif // POINT_C_H
