#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scene/base_scene.h"
#include "transform/transformator.h"
#include "visualiser/visualizer.h"
#include "objects/visitor/transform_visitor.h"
#include "objects/visitor/draw_visitor.h"
#include "objects/creator/object_creator.h"
#include "builder/build_director.h"

#include "errors/managers_errors.h"

class SceneManager
{
public:
    SceneManager(weak_ptr<BaseScene> scene_ptr);
    virtual ~SceneManager() = 0;

    virtual void execute() = 0;

protected:
    weak_ptr<BaseScene> _scene;
    Iterator<shared_ptr<SceneObject> > _find_i(size_t index);
};

class TransformManager: public SceneManager
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

class DrawManager: public SceneManager
{
public:
    DrawManager(weak_ptr<BaseScene> scene_ptr,
                weak_ptr<BaseDrawerFactory> draw_factory);
    virtual ~DrawManager();

    virtual void execute();
private:
    weak_ptr<BaseDrawerFactory> _draw;
};

class CameraManager: public SceneManager
{
public:
    CameraManager(weak_ptr<BaseScene> scene_ptr,
                  size_t index);
    virtual ~CameraManager();

    virtual void execute();
private:
    size_t _index;
};

class AddManager: public SceneManager
{
public:
    AddManager(weak_ptr<BaseScene> scene_ptr,
               weak_ptr<ObjectCreator> creator);
    virtual ~AddManager();

    virtual void execute();
private:
    weak_ptr<ObjectCreator> _creator;
};

class RemoveManager: public SceneManager
{
public:
    RemoveManager(weak_ptr<BaseScene> scene_ptr,
                  size_t index);
    virtual ~RemoveManager();

    virtual void execute();
private:
    size_t _index;
};

class LoadManager: public SceneManager
{
public:
    LoadManager(weak_ptr<BaseScene> scene_ptr,
                weak_ptr<BuildDirector> director);
    virtual ~LoadManager();

    virtual void execute();
private:
    weak_ptr<BuildDirector> _director;
};

#endif // SCENE_MANAGER_H
