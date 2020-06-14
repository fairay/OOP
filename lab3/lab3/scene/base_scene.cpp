#include "base_scene.h"

BaseScene::BaseScene():
    _arr(), _curr_cam(_arr.end()) {}
BaseScene::~BaseScene()
{
    for (auto ptr: _arr)
        delete ptr;
    _arr.clear();
}


size_t BaseScene::get_size()
{
    return _arr.get_size();
}

Iterator<SceneObject*> BaseScene::begin()
{
    return _arr.begin();
}
Iterator<SceneObject*> BaseScene::end()
{
    return _arr.end();
}

ConstIterator<SceneObject*> BaseScene:: begin() const
{
    return _arr.begin();
}
ConstIterator<SceneObject*> BaseScene::end() const
{
    return _arr.end();
}

ConstIterator<SceneObject*> BaseScene::cbegin() const
{
    return _arr.cbegin();
}
ConstIterator<SceneObject*> BaseScene::cend() const
{
    return _arr.cend();
}
