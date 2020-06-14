#include "scene.h"

Scene::Scene() {}
Scene::~Scene() {}

shared_ptr<BaseCamera> Scene::get_camera()
{
    cout << "Getting camera" << endl;
    BaseCamera *ptr = reinterpret_cast<BaseCamera*>((*_curr_cam)->clone());
    cout << "Ok" << endl;
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
    cout << "Serching for new camera: ";


    for (; iter; iter++)
        if ((*iter)->is_observer())
            break;
    cout << endl;
    if (iter.is_end()) cout << "CAMERA NOT FOUND" << endl;
    return iter;
}
