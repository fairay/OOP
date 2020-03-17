#ifndef APPLY_FUNC_H
#define APPLY_FUNC_H

#include "point.h"
#include "transform_params.h"

typedef struct
{
    point_t point;
    scale_t scale;
    angle_t angels;
} transform_t;

transform_t create_move_trans(const point_t &move_vec);
transform_t create_scale_trans(const point_t &center, const scale_t &scale);
transform_t create_rotate_trans(const point_t &center, const angle_t &angels);

#endif // APPLY_FUNC_H
