#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene/base_scene.h"
#include "transform/transformator.h"
#include "visualiser/visualizer.h"
#include "objects/visitor/transform_visitor.h"
#include "objects/visitor/draw_visitor.h"
#include "objects/creator/object_creator.h"
#include "builder/builder.h"

#include "errors/managers_errors.h"

class SceneManageer
{
public:
    SceneManageer(weak_ptr<BaseScene> scene_ptr);
    virtual ~SceneManageer() = 0;

    virtual void execute() = 0;

protected:
    weak_ptr<BaseScene> _scene;
    Iterator<SceneObject> _find_i(size_t index);
};

class TransformManager: public SceneManageer
{
public:
    TransformManager(weak_ptr<BaseScene> scene_ptr,
                     weak_ptr<Transformator> trans, size_t index);
    virtual ~TransformManager();

    virtual void execute();
private:
    weak_ptr<Transformator> _trans;
    size_t _index;
};

class DrawManager: public SceneManageer
{
public:
    DrawManager(weak_ptr<BaseScene> scene_ptr,
                weak_ptr<BaseDrawerFactory> draw_factory);
    virtual ~DrawManager();

    virtual void execute();
private:
    weak_ptr<BaseDrawerFactory> _draw;
};

class CameraManager: public SceneManageer
{
public:
    CameraManager(weak_ptr<BaseScene> scene_ptr,
                  size_t index);
    virtual ~CameraManager();

    virtual void execute();
private:
    size_t _index;
};

class AddManager: public SceneManageer
{
public:
    AddManager(weak_ptr<BaseScene> scene_ptr,
               weak_ptr<ObjectCreator> creator);
    virtual ~AddManager();

    virtual void execute();
private:
    weak_ptr<ObjectCreator> _creator;
};

class RemoveManager: public SceneManageer
{
public:
    RemoveManager(weak_ptr<BaseScene> scene_ptr,
                  size_t index);
    virtual ~RemoveManager();

    virtual void execute();
private:
    size_t _index;
};

class LoadManager: public SceneManageer
{
public:
    LoadManager(weak_ptr<BaseScene> scene_ptr,
                weak_ptr<Builder> build);
    virtual ~LoadManager();

    virtual void execute();
private:
    weak_ptr<Builder> _build;
};

#endif // SCENE_MANAGER_H
