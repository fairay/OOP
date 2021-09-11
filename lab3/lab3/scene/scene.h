#ifndef SCENE_H
#define SCENE_H

#include "base_scene.h"

class Scene: public BaseScene
{
public:
    Scene();
    virtual ~Scene();

    virtual shared_ptr<BaseCamera> get_camera();
    virtual void set_camera(Iterator<shared_ptr<SceneObject>>& iter);

    virtual void add_object(SceneObject* obj);
    virtual void add_object(shared_ptr<SceneObject> obj);
    virtual void remove_object(Iterator<shared_ptr<SceneObject>>& iter);
private:
    Iterator<shared_ptr<SceneObject>> _find_camera();
};

#endif // SCENE_H
