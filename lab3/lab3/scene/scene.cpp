#include "scene.h"

Scene::Scene() {}
Scene::~Scene() {}

shared_ptr<BaseCamera> Scene::get_camera()
{
    BaseCamera *ptr;
    if (_curr_cam.is_end())
        ptr = nullptr;
    else
        ptr = reinterpret_cast<BaseCamera*>((*_curr_cam)->clone());
    return shared_ptr<BaseCamera>(ptr);
}
void Scene::set_camera(Iterator<SceneObject*>& iter)
{
    if ((*iter)->is_observer() && !iter.is_end())
        _curr_cam = iter;
}

void Scene::add_object(SceneObject* obj)
{
    _arr.append(obj);
    _curr_cam = _find_camera();
}
void Scene::remove_object(Iterator<SceneObject*>& iter)
{
    SceneObject* del_obj = *iter;
    delete del_obj;
    _arr.remove(iter);
    _curr_cam = _find_camera();
}

Iterator<SceneObject*> Scene::_find_camera()
{
    Iterator<SceneObject*> iter = begin();
    for (; iter; iter++)
        if ((*iter)->is_observer())
            break;
    return iter;
}
