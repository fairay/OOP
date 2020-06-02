#include "object_errors.h"

using namespace err;

ObjectError::ObjectError(const string file_, long line_n_): SceneError(file_, line_n_)
{
    type = "Object Error: ";
}
ObjectError::~ObjectError() = default;



NotDrawable::NotDrawable(const string file_, long line_n_): ObjectError(file_, line_n_)
{
    type += "NotDrawable";
    add_info = "object is not drawable";
    fill_msg();
}
NotDrawable::~NotDrawable() = default;

NotTransable::NotTransable(const string file_, long line_n_): ObjectError(file_, line_n_)
{
    type += "NotTransable";
    add_info = "object can't be transleeted";
    fill_msg();
}
NotTransable::~NotTransable() = default;

UndefindeClone::UndefindeClone(const string file_, long line_n_): ObjectError(file_, line_n_)
{
    type += "UndefindeClone";
    add_info = "operation of clone isn't defided for object";
    fill_msg();
}
UndefindeClone::~UndefindeClone() = default;
