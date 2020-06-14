#include "composite_object.h"

CompositeObject::CompositeObject(): _obj_arr() {}

CompositeObject::CompositeObject(const CompositeObject& other)
{
    for (auto obj: other._obj_arr)
        _obj_arr.append(obj->clone());
}

bool CompositeObject::is_observer() const
{
    for (auto obj : *this)
        if (obj->is_observer())
            return true;
    return false;
}
bool CompositeObject::is_drawable() const
{
    for (auto obj : *this)
        if (obj->is_drawable())
            return true;
    return false;
}

size_t CompositeObject::get_size() const
{
    return _obj_arr.get_size();
}

void CompositeObject::add_object(SceneObject* obj)
{
    _obj_arr.append(obj);
}
void CompositeObject::remove_object(Iterator<SceneObject*> &rem_iter)
{
    SceneObject* del_obj = *rem_iter;
    delete del_obj;
    _obj_arr.remove(rem_iter);
}
