#ifndef COMPOSITE_OBJECT_H
#define COMPOSITE_OBJECT_H

#include "scene_object.h"
#include "array/array.h"

class CompositeObject: public SceneObject
{
public:
    CompositeObject();
    explicit CompositeObject(const CompositeObject& other);

    virtual bool is_complex() final {return true;}
    virtual bool is_observer();
    virtual bool is_drawable();

    Iterator<SceneObject> begin() {return _obj_arr.begin();}
    Iterator<SceneObject> end() {return _obj_arr.end();}
    ConstIterator<SceneObject> begin() const {return _obj_arr.begin();}
    ConstIterator<SceneObject> end() const {return _obj_arr.end();}
    ConstIterator<SceneObject> cbegin() {return _obj_arr.cbegin();}
    ConstIterator<SceneObject> cend() {return _obj_arr.cend();}

    size_t get_size() const;

    void add_object(const SceneObject&);
    void remove_object(const Iterator<SceneObject>&);

private:
    Array<SceneObject> _obj_arr;
};

#endif // COMPOSITE_OBJECT_H
