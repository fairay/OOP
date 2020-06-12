#include "composite_object.h"

CompositeObject::CompositeObject(): _obj_arr() {}

CompositeObject::CompositeObject(const CompositeObject& other)
{
    _obj_arr = other._obj_arr;
}

bool CompositeObject::is_observer()
{
    for (auto obj : *this)
        if (obj.is_observer())
            return true;
    return false;
}
bool CompositeObject::is_drawable()
{
    for (auto obj : *this)
        if (obj.is_drawable())
            return true;
    return false;
}

size_t CompositeObject::get_size() const
{
    return _obj_arr.get_size();
}

void CompositeObject::add_object(const SceneObject& obj)
{
    _obj_arr.append(obj);
}

void CompositeObject::remove_object(const Iterator<SceneObject> &rem_iter)
{
    _obj_arr.remove(rem_iter);
}