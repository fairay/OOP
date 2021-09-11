#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "defines.h"
#include "points_data.h"
#include "edges_data.h"
#include "pedge.h"

typedef struct
{
    pdata_t points;
    edata_t edges;
} model_t;


model_t init_model(void);
err_t delete_model(model_t &model);

err_t move_model(model_t &model, const transform_t &trans);
err_t scale_model(model_t &model, const transform_t &trans);
err_t rotate_model(model_t &model, const transform_t &trans);

err_t draw_model(draw_t &draw, const model_t &model, const proj_params_t &view_par);

err_t fscan_model(model_t &old_model, file_arg_t f_name);

#endif // GEOMETRY_H
