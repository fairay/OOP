#ifndef BASE_SCENE_H
#define BASE_SCENE_H

#include "array/array.h"
#include "objects/scene_object.h"
#include "objects/camera/base_camera.h"

class BaseScene
{
public:
    BaseScene();
    virtual ~BaseScene() = 0;

     size_t get_size() {return _arr.get_size();}

    Iterator<SceneObject> begin() {return _arr.begin();}
    Iterator<SceneObject> end() {return _arr.end();}
    ConstIterator<SceneObject> begin() const {return _arr.begin();}
    ConstIterator<SceneObject> end() const {return _arr.end();}
    ConstIterator<SceneObject> cbegin() const {return _arr.cbegin();}
    ConstIterator<SceneObject> cend() const {return _arr.cend();}

     virtual weak_ptr<BaseCamera> get_camera() const = 0;
     virtual void set_camera(Iterator<SceneObject>& iter) = 0;

     virtual void add_object(SceneObject& obj) = 0;
     virtual void remove_object(Iterator<SceneObject>& iter) = 0;
protected:
    Array<SceneObject> _arr;
    Iterator<SceneObject> _curr_cam;
};

#endif // BASE_SCENE_H
