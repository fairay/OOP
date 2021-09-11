#include <math.h>
#include <stdio.h>

#include "point.h"

// Point CDIO
point_t create_point(double x, double y, double z)
{
    point_t p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

double pget_x(const point_t &p)
{
    return p.x;
}
double pget_y(const point_t &p)
{
    return p.y;
}
double pget_z(const point_t &p)
{
    return p.z;
}

/// Display functions
err_t project_point(point_t &p, const point_t &view)
{
    double k;
    err_t code;

    if (fabs(view.z - p.z) < EPS)
        return INVISIBLE_POINT;
    else if (view.z < p.z)
    {
        code = INVISIBLE_POINT;
        k = view.z / (view.z - p.z);
    }
    else
    {
        code = CORRECT_WORK;
        k = view.z / (view.z - p.z);
    }

    p.z = 0;
    p.x = view.x + (p.x - view.x)*k;
    p.y = view.y + (p.y - view.y)*k;
    return code;
}
err_t plot_point(point_t &p, double xy_min, double xy_max)
{
    if (xy_min > xy_max)        return INCORRECT_VIEW;
    p.x = p.x / (xy_max - xy_min);
    p.y = -p.y / (xy_max - xy_min);
    return CORRECT_WORK;
}
err_t canvas_point(point_t &p, unsigned int canv_x, unsigned int canv_y)
{
    if (!(canv_x && canv_y))     return INCORRECT_VIEW;
    p.x *= canv_x;
    p.y *= canv_y;
    return CORRECT_WORK;
}


/// Transformation functions
void move_point(point_t &p, const point_t &move_vec)
{
    p.x = p.x + move_vec.x;
    p.y = p.y + move_vec.y;
    p.z = p.z + move_vec.z;
}

void scale_point(point_t &p, const point_t &cen, const scale_t &scale)
{
    p.x = cen.x + scale.kx*(p.x - cen.x);
    p.y = cen.y + scale.ky*(p.y - cen.y);
    p.z = cen.z + scale.kz*(p.z - cen.z);
}

void rotate_pointx(point_t &p, const point_t &cen, double alpha)
{
    double y, z;
    y = cen.y + (p.y - cen.y)*cos(alpha) + (p.z - cen.z)*sin(alpha);
    z = cen.z - (p.y - cen.y)*sin(alpha) + (p.z - cen.z)*cos(alpha);

    p.y = y;
    p.z = z;
}
void rotate_pointy(point_t &p, const point_t &cen, double alpha)
{
    double x, z;

    x = cen.x + (p.x - cen.x)*cos(alpha) - (p.z - cen.z)*sin(alpha);
    z = cen.z + (p.x - cen.x)*sin(alpha) + (p.z - cen.z)*cos(alpha);
    p.x = x;
    p.z = z;
}
void rotate_pointz(point_t &p, const point_t &cen, double alpha)
{
    double x, y;

    x = cen.x + (p.x - cen.x)*cos(alpha) + (p.y - cen.y)*sin(alpha);
    y = cen.y - (p.x - cen.x)*sin(alpha) + (p.y - cen.y)*cos(alpha);
    p.x = x;
    p.y = y;
}

void rotate_point(point_t &p, const point_t &cen, const angle_t &angels)
{
    rotate_pointx(p, cen, angels.ax);
    rotate_pointy(p, cen, angels.ay);
    rotate_pointz(p, cen, angels.az);
}


/// Point draw
err_t draw_point(draw_t &draw, const point_t &p)
{
    return add_point(draw, p.x, p.y);
}
err_t draw_axis_line(draw_t &draw, const point_t &p1, const point_t &p2)
{
    return add_axis_line(draw, p1.x, p1.y, p2.x, p2.y);
}
err_t draw_line(draw_t &draw, const point_t &p1, const point_t &p2)
{
    return add_line(draw, p1.x, p1.y, p2.x, p2.y);
}

/// Point scan file
err_t fscan_point(point_t &p, FILE *f)
{
    int sc;
    double x, y, z;

    if (!f)         return INCORRECT_FILE;

    sc = fscanf(f, "%lf%lf%lf", &x, &y, &z);
    if (sc != 3)    return INCORRECT_FILE;

    p = create_point(x, y, z);
    return CORRECT_WORK;
}
