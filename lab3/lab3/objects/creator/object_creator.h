#ifndef OBJECT_CREATOR_H
#define OBJECT_CREATOR_H

#include "objects/scene_object.h"
#include <memory>

class ObjectCreator
{
public:
    ObjectCreator();
    virtual ~ObjectCreator() = default;

    virtual unique_ptr<SceneObject> create() = 0;
};

#endif // OBJECT_CREATOR_H
