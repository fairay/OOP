#include "transform_params.h"


angle_t create_angle_deg(double ax, double ay, double az)
{
    angle_t a;
    a.ax = ax * PI / 180;
    a.ay = ay * PI / 180;
    a.az = az * PI / 180;
    return a;
}

scale_t create_scale(double kx, double ky, double kz)
{
    scale_t sc;
    sc.kx = kx;
    sc.ky = ky;
    sc.kz = kz;
    return sc;
}
