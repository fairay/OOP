#include "proj_params.h"

typedef enum
{
    OX,
    OY,
    OZ
} axis_dir_t;


/// View parameters
proj_params_t create_params(void)
{
    proj_params_t e;
    e.xy_min = 0;
    e.xy_max = 0;
    e.canv_x = 0;
    e.canv_y = 0;
    e.view_p = create_point(0, 0, 0);
    return e;
}

void set_canvas_xy(proj_params_t &par, unsigned int canv_x, unsigned int canv_y)
{
    par.canv_x = canv_x;
    par.canv_y = canv_y;
}

void set_point_view(proj_params_t &par, const point_t &view_p)
{
    par.view_p = view_p;
}

void set_xy_range(proj_params_t &par, double xy_min, double xy_max)
{
    par.xy_min = xy_min;
    par.xy_max = xy_max;
}


double get_xy_max(const proj_params_t &par)
{
    return par.xy_max;
}
double get_xy_min(const proj_params_t &par)
{
    return par.xy_min;
}

unsigned int get_canv_x(const proj_params_t &par)
{
    return par.canv_x;
}
unsigned int get_canv_y(const proj_params_t &par)
{
    return par.canv_y;
}


err_t check_params_valid(const proj_params_t &par)
{
    err_t code = CORRECT_WORK;
    if (get_xy_min(par) >= get_xy_max(par))
        code = INVALID_VIEW;
    else if (get_canv_x(par) * get_canv_y(par) == 0)
        code = INVALID_VIEW;
    return code;
}

err_t set_params(proj_params_t &dest, const proj_params_t &source)
{
    err_t code = check_params_valid(source);
    if (!code)  dest = source;
    return code;
}


point_t trans_point(err_t &err, const point_t &p, const proj_params_t &pr_par)
{
    point_t p_proj = p;
    err = check_params_valid(pr_par);
    if (!err)   err = project_point(p_proj, pr_par.view_p);
    if (!err)   err = plot_point(p_proj, pr_par.xy_min, pr_par.xy_max);
    if (!err)   err = canvas_point(p_proj, pr_par.canv_x, pr_par.canv_y);
    return p_proj;
}

/// Draw axis
err_t draw_axis_oxyz(draw_t &draw, const proj_params_t &view_par, axis_dir_t dir)
{
    err_t code;
    point_t p1, p2;
    double max_xyz = get_xy_max(view_par);
    if (max_xyz <= 0) return INCORRECT_VIEW;

    p1 = create_point(0, 0, 0);
    p1 = trans_point(code, p1, view_par);
    if (code)  return code;

    switch (dir)
    {
    case OX:
        p2 = create_point(max_xyz, 0, 0);
        break;
    case OY:
        p2 = create_point(0, max_xyz, 0);
        break;
    case OZ:
        p2 = create_point(0, 0, max_xyz);
        break;
    }
    p2 = trans_point(code, p2, view_par);
    if (code)  return code;

    code = draw_axis_line(draw, p1, p2);
    return code;
}
err_t draw_axis(draw_t &draw, const proj_params_t &view_par)
{
    err_t code;

    code = draw_axis_oxyz(draw, view_par, OX);
    if (code)       return code;
    code = draw_axis_oxyz(draw, view_par, OY);
    if (code)       return code;
    code = draw_axis_oxyz(draw, view_par, OZ);
    return code;
}
