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
    if (!_curr_cam->is_observer())
        _curr_cam = end();
}
void Scene::remove_object(Iterator<SceneObject>& iter)
{
    if (iter == _curr_cam)
    {
        _arr.remove(iter);
        _curr_cam = _find_camera();
    }
    else
    {
        _arr.remove(iter);
    }
}


Iterator<SceneObject> Scene::_find_camera()
{
    Iterator<SceneObject> iter = begin();
    for (;iter;iter++)
        if (iter->is_observer())
            break;
    return iter;
}
