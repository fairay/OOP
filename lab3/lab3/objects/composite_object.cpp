#include "composite_object.h"

CompositeObject::CompositeObject(): _obj_arr() {}
CompositeObject::CompositeObject(const CompositeObject& other)
{
    for (auto obj: other._obj_arr)
        _obj_arr.append(shared_ptr<SceneObject>(obj->clone()));
}
CompositeObject::~CompositeObject()
{
    _obj_arr.clear();
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
    _obj_arr.append(shared_ptr<SceneObject>(obj));
}
void CompositeObject::add_object(shared_ptr<SceneObject> obj)
{
    _obj_arr.append(obj);
}
void CompositeObject::remove_object(Iterator<shared_ptr<SceneObject>> &rem_iter)
{
    _obj_arr.remove(rem_iter);
}
