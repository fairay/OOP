#ifndef TRANSFORM_PARAMS_H
#define TRANSFORM_PARAMS_H

#include "defines.h"

typedef struct
{
    double kx, ky, kz;
} scale_t;

typedef struct
{
    double ax, ay, az;
} angle_t;

scale_t create_scale(double kx, double ky, double kz);
angle_t create_angle_deg(double ax, double ay, double az);

#endif // TRANSFORM_PARAMS_H
