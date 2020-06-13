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

    size_t get_size();

    Iterator<SceneObject> begin();
    Iterator<SceneObject> end();
    ConstIterator<SceneObject> begin() const;
    ConstIterator<SceneObject> end() const;
    ConstIterator<SceneObject> cbegin() const;
    ConstIterator<SceneObject> cend() const;

    virtual shared_ptr<BaseCamera> get_camera() = 0;
    virtual void set_camera(Iterator<SceneObject>& iter) = 0;

    virtual void add_object(SceneObject& obj) = 0;
    virtual void remove_object(Iterator<SceneObject>& iter) = 0;

protected:
    Array<SceneObject> _arr;
    Iterator<SceneObject> _curr_cam;
};

#endif // BASE_SCENE_H
