#ifndef SCENE_H
#define SCENE_H

#include "base_scene.h"

class Scene: public BaseScene
{
public:
    Scene();
    virtual ~Scene();

    virtual shared_ptr<BaseCamera> get_camera();
    virtual void set_camera(Iterator<SceneObject*>& iter);

    virtual void add_object(SceneObject* obj);
    virtual void remove_object(Iterator<SceneObject*>& iter);
private:
    Iterator<SceneObject*> _find_camera();
};

#endif // SCENE_H
