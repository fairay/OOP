#ifndef ACTION_INTERFACE_H
#define ACTION_INTERFACE_H

#include "defines.h"
#include "transform.h"
#include "proj_params.h"

typedef enum
{
    LOAD_FILE,
    SET_VIEW,
    MOVE,
    SCALE,
    ROTATE,
    DRAW,
    CLEAR
} act_type_t;

typedef struct
{
    act_type_t type;

    file_arg_t file_name;
    proj_params_t view_par;
    transform_t transform;
    draw_t draw;
} act_data_t;

act_data_t load_file_act(file_arg_t name);
act_data_t set_view_act(proj_params_t &view_par);
act_data_t move_act(transform_t &trans);
act_data_t scale_act(transform_t &trans);
act_data_t rotate_act(transform_t &trans);
act_data_t draw_act(draw_t &draw);
act_data_t clear_act(void);

#endif // ACTION_INTERFACE_H
