#include "model_interface.h"

err_t model_action(act_data_t &act_data)
{
    static proj_params_t view_par = create_params();
    static model_t model = init_model();

    err_t err = CORRECT_WORK;

    switch (act_data.type)
    {
        case LOAD_FILE:
            err = fscan_model(model, act_data.file_name);
            break;

        case SET_VIEW:
            err = set_params(view_par, act_data.view_par);
            break;

        case MOVE:
            err = move_model(model, act_data.transform);
            break;
        case ROTATE:
            err = rotate_model(model, act_data.transform);
            break;
        case SCALE:
            err = scale_model(model, act_data.transform);
            break;

        case DRAW:
            err = draw_model(act_data.draw, model, view_par);
            break;

        case CLEAR:
            err = delete_model(model);
            break;

        default:
            err = WRONG_ACTION;
            break;
    }
    return err;
}
