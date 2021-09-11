#include "transform.h"

/// Transformation data
transform_t create_move_trans(const point_t &move_vec)
{
    transform_t trans;
    trans.point = move_vec;
    trans.scale = create_scale(1,1,1);
    trans.angels = create_angle_deg(0,0,0);
    return trans;
}

transform_t create_scale_trans(const point_t &center, const scale_t &scale)
{
    transform_t trans;
    trans.point = center;
    trans.scale = scale;
    trans.angels = create_angle_deg(0,0,0);
    return trans;
}

transform_t create_rotate_trans(const point_t &center, const angle_t &angels)
{
    transform_t trans;
    trans.point = center;
    trans.scale = create_scale(1,1,1);
    trans.angels = angels;
    return trans;
}
