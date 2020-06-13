#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene/base_scene.h"
#include "transform/transformator.h"

class SceneManageer
{
public:
    SceneManageer(weak_ptr<BaseScene> scene_ptr);
    virtual ~SceneManageer() = 0;

    virtual void execute() = 0;

protected:
    weak_ptr<BaseScene> _scene;
};

class TransformManager: public SceneManageer
{
public:
    TransformManager(weak_ptr<BaseScene> scene_ptr,
                     weak_ptr<Transformator> trans, size_t index);
    virtual ~TransformManager();

private:
    weak_ptr<Transformator> _trans;
    size_t _index;
};

#endif // SCENE_MANAGER_H
