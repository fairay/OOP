#ifndef OBJECT_CREATOR_H
#define OBJECT_CREATOR_H

#include "objects/scene_object.h"
#include <memory>

class ObjectCreator
{
public:
    ObjectCreator();
    virtual ~ObjectCreator() = 0;

    virtual SceneObject* create() = 0;
};

#endif // OBJECT_CREATOR_H
