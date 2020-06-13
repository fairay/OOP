#include "scene.h"

Scene::Scene() {}
Scene::~Scene() {}

shared_ptr<BaseCamera> Scene::get_camera()
{
    BaseCamera *ptr = reinterpret_cast<BaseCamera*>(&(*_curr_cam));
    return shared_ptr<BaseCamera>(ptr);
}
void Scene::set_camera(Iterator<SceneObject>& iter)
{
    if (iter->is_observer() && !iter.is_end())
        _curr_cam = iter;
}

void Scene::add_object(SceneObject& obj)
{
    _arr.append(obj);
}
void Scene::remove_object(Iterator<SceneObject>& iter)
{
    _arr.remove(iter);
}