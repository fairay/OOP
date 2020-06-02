#ifndef SIMPLE_OBJECT_H
#define SIMPLE_OBJECT_H

#include "scene_object.h"

class SimpleObject: public SceneObject
{
public:
    SimpleObject();
    virtual bool is_complex() final {return false;}
};

class VisibleObject: public SimpleObject
{
public:
    VisibleObject();
    virtual bool is_visible() final {return true;}
};

class InvisibleObject: public SimpleObject
{
public:
    InvisibleObject();
    virtual bool is_visible() final {return false;}
};

#endif // SIMPLE_OBJECT_H
