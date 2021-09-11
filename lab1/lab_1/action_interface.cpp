#include "action_interface.h"

act_data_t load_file_act(file_arg_t name)
{
    act_data_t act;
    act.type = LOAD_FILE;
    act.file_name = name;
    return act;
}


act_data_t set_view_act(proj_params_t &view_par)
{
    act_data_t act;
    act.type = SET_VIEW;
    act.view_par = view_par;
    return act;
}


act_data_t move_act(transform_t &trans)
{
    act_data_t act;
    act.type = MOVE;
    act.transform = trans;
    return act;
}

act_data_t scale_act(transform_t &trans)
{
    act_data_t act;
    act.type = SCALE;
    act.transform = trans;
    return act;
}

act_data_t rotate_act(transform_t &trans)
{
    act_data_t act;
    act.type = ROTATE;
    act.transform = trans;
    return act;
}


act_data_t draw_act(draw_t &draw)
{
    act_data_t act;
    act.type = DRAW;
    act.draw = draw;
    return act;
}


act_data_t clear_act(void)
{
    act_data_t act;
    act.type = CLEAR;
    return act;
}
