#include "model.h"

/// Model CDIO
model_t init_model(void)
{
    model_t model;
    model.points = init_pdata();
    model.edges = init_edata();
    return  model;
}

err_t delete_model(model_t &model)
{
    delete_pdata(model.points);
    delete_edata(model.edges);
    return CORRECT_WORK;
}


/// Model functions
unsigned int mget_pn(const model_t &model)
{
    return get_points_n(model.points);
}
unsigned int mget_en(const model_t &model)
{
    return get_edges_n(model.edges);
}

err_t mget_pedge(pedge_t &pedge, const model_t &model, unsigned int i)
{
    err_t code;
    edge_t edge;

    code = get_edges_i(edge, model.edges, i);
    if (!code)  pedge = get_points_pedge(model.points, edge);
    return code;
}


/// Model transformations
err_t move_model(model_t &model, const transform_t &trans)
{
    return move_points(model.points, trans);
}
err_t scale_model(model_t &model, const transform_t &trans)
{
    return scale_points(model.points, trans);
}
err_t rotate_model(model_t &model, const transform_t &trans)
{
    return rotate_points(model.points, trans);
}


/// Model draw
err_t draw_model_points(draw_t &draw, const model_t &model, const proj_params_t &view_par)
{
    return draw_points(draw, model.points, view_par);
}
err_t draw_model_edges(draw_t &draw, const model_t &model, const proj_params_t &view_par)
{
    pedge_t pedge;
    err_t code = CORRECT_WORK;

    for (unsigned int i = 0; (!code) && i < mget_en(model); i++)
    {
        code = mget_pedge(pedge, model, i);
        if (!code)  pedge = trans_pedge(code, pedge, view_par);
        if (!code)  code = draw_pedge(draw, pedge);
    }
    return code;
}

err_t draw_model(draw_t &draw, const model_t &model, const proj_params_t &view_par)
{
    err_t code;

    code = clear_draw(draw);
    if (code)  return code;

    code = draw_axis(draw, view_par);
    if (code)  return code;

    code = draw_model_edges(draw, model, view_par);
    if (code)  return code;

    code = draw_model_points(draw, model, view_par);
    code = draw_points(draw, model.points, view_par);
    return code;
}


/// Model file scaning
err_t fscan_model(model_t &old_model, file_arg_t f_name)
{
    FILE *f = fopen(f_name, "r");
    if (!f)         return UNREAD_FILE;

    model_t model = init_model();
    err_t code = fscan_pdata(f, model.points);
    if (!code)
    {
        code = fscan_edata(f, model.edges);
        if (code)
            delete_pdata(model.points);
    }

    fclose(f);

    if (!code)
    {
        delete_model(old_model);
        old_model = model;
    }

    return code;
}
