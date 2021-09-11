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

    Iterator<shared_ptr<SceneObject>> begin();
    Iterator<shared_ptr<SceneObject>> end();
    ConstIterator<shared_ptr<SceneObject>> begin() const;
    ConstIterator<shared_ptr<SceneObject>> end() const;
    ConstIterator<shared_ptr<SceneObject>> cbegin() const;
    ConstIterator<shared_ptr<SceneObject>> cend() const;

    virtual shared_ptr<BaseCamera> get_camera() = 0;
    virtual void set_camera(Iterator<shared_ptr<SceneObject>>& iter) = 0;

    virtual void add_object(SceneObject* obj) = 0;
    virtual void add_object(shared_ptr<SceneObject> obj) = 0;
    virtual void remove_object(Iterator<shared_ptr<SceneObject>>& iter) = 0;

protected:
    Array<shared_ptr<SceneObject>>  _arr;
    Iterator<shared_ptr<SceneObject>> _curr_cam;
};

#endif // BASE_SCENE_H
