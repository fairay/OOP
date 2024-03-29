#include "scene_manager.h"

SceneManager::SceneManager(weak_ptr<BaseScene> scene_ptr):
    _scene(scene_ptr) {}
SceneManager::~SceneManager() {}
Iterator<shared_ptr<SceneObject>> SceneManager::_find_i(size_t index)
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "SceneManageer");

    Iterator<shared_ptr<SceneObject>> iter = _scene.lock()->begin();
    size_t count = index;
    for (;iter && count; count--, iter++) {}
    if (count || iter.is_end())
        throw err::IOutOfScene(__FILE__, __LINE__-1, "SceneManageer", index);
    return iter;
}



TransformManager::TransformManager(weak_ptr<BaseScene> scene_ptr,
                                   weak_ptr<Transformator> trans, size_t index):
    SceneManager(scene_ptr), _trans(trans), _index(index) {}
TransformManager::~TransformManager() {}
void TransformManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "TransformManager");
    Iterator<shared_ptr<SceneObject>> iter = _find_i(_index);
    shared_ptr<ObjectVisitor> visitor(new TransformVisitor(_trans));
    visitor->set_ptr(visitor);
    (*iter)->accept(visitor);
}


DrawManager::DrawManager(weak_ptr<BaseScene> scene_ptr,
                         weak_ptr<BaseDrawerFactory> draw_factory):
    SceneManager(scene_ptr), _draw(draw_factory) {}
DrawManager::~DrawManager() {}
void DrawManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "DrawManager");
    if (_draw.expired())
        throw err::AttributePtrExpired(__FILE__, __LINE__-1, "DrawManager");

    shared_ptr<Visualizer> visual(new Visualizer());
    visual->set_draw(*_draw.lock());
    visual->set_camera(_scene.lock()->get_camera());

    shared_ptr<ObjectVisitor> visitor(new DrawVisitor(visual));
    visitor->set_ptr(visitor);
    visual->clear();
    for (auto obj: *_scene.lock())
        obj->accept(visitor);
}


CameraManager::CameraManager(weak_ptr<BaseScene> scene_ptr,
                             size_t index):
    SceneManager(scene_ptr), _index(index) {}
CameraManager::~CameraManager() {}
void CameraManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "CameraManager");
    Iterator<shared_ptr<SceneObject>> iter = _find_i(_index);
    _scene.lock()->set_camera(iter);
}


AddManager::AddManager(weak_ptr<BaseScene> scene_ptr,
                       weak_ptr<ObjectCreator> creator):
    SceneManager(scene_ptr), _creator(creator) {}
AddManager::~AddManager() {}
void AddManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "AddManager");
    if (_creator.expired())
        throw err::AttributePtrExpired(__FILE__, __LINE__-1, "AddManager");

    _scene.lock()->add_object(_creator.lock()->create());
}


RemoveManager::RemoveManager(weak_ptr<BaseScene> scene_ptr,
                             size_t index):
    SceneManager(scene_ptr), _index(index) {}
RemoveManager::~RemoveManager() {}
void RemoveManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "RemoveManager");
    Iterator<shared_ptr<SceneObject>> iter = _find_i(_index);
    _scene.lock()->remove_object(iter);
}


LoadManager::LoadManager(weak_ptr<BaseScene> scene_ptr,
                         weak_ptr<BuildDirector> dir):
    SceneManager(scene_ptr), _director(dir) {}
LoadManager::~LoadManager() {}
void LoadManager::execute()
{
    if (_scene.expired())
        throw err::ScenePtrExpired(__FILE__, __LINE__-1, "LoadManager");
    if (_director.expired())
        throw err::AttributePtrExpired(__FILE__, __LINE__-1, "LoadManager");

    _scene.lock()->add_object(_director.lock()->create());
}
