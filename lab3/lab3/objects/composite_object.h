#ifndef COMPOSITE_OBJECT_H
#define COMPOSITE_OBJECT_H

#include "scene_object.h"
#include "array/array.h"

class CompositeObject: public SceneObject
{
public:
    CompositeObject();
    explicit CompositeObject(const CompositeObject& other);
    virtual ~CompositeObject();

    virtual bool is_complex() const final {return true;}
    virtual bool is_observer() const;
    virtual bool is_drawable() const;

    Iterator<shared_ptr<SceneObject>> begin() {return _obj_arr.begin();}
    Iterator<shared_ptr<SceneObject>> end() {return _obj_arr.end();}
    ConstIterator<shared_ptr<SceneObject>> begin() const {return _obj_arr.begin();}
    ConstIterator<shared_ptr<SceneObject>> end() const {return _obj_arr.end();}
    ConstIterator<shared_ptr<SceneObject>> cbegin() {return _obj_arr.cbegin();}
    ConstIterator<shared_ptr<SceneObject>> cend() {return _obj_arr.cend();}

    size_t get_size() const;

    void add_object(SceneObject* obj);
    void add_object(shared_ptr<SceneObject> obj);
    void remove_object(Iterator<shared_ptr<SceneObject>>& iter);

protected:
    Array<shared_ptr<SceneObject>> _obj_arr;
};

#endif // COMPOSITE_OBJECT_H
