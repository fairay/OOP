#ifndef POINT_ARR_C_H
#define POINT_ARR_C_H

#include <stdio.h>
#include "point.h"
#include "transform.h"

typedef point_t* point_arr_t;

err_t alloc_point_arr(point_arr_t &ptr, size_t n);
void delete_point_arr(point_arr_t &ptr);
err_t arr_set_point(point_arr_t ptr, unsigned int i, const point_t &p);
err_t arr_get_point(point_t &p, const point_arr_t ptr, unsigned int i);

err_t move_point_arr(point_arr_t ptr, unsigned int n, const transform_t &trans);
err_t scale_point_arr(point_arr_t ptr, unsigned int n, const transform_t &trans);
err_t rotate_point_arr(point_arr_t ptr, unsigned int n, const transform_t &trans);

err_t fscan_point_arr(FILE *f, point_arr_t ptr, unsigned int n);
#endif // POINT_ARR_C_H
