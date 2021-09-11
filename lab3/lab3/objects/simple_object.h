#ifndef SIMPLE_OBJECT_H
#define SIMPLE_OBJECT_H

#include "scene_object.h"

class SimpleObject: public SceneObject
{
public:
    SimpleObject();
    virtual ~SimpleObject() = 0;

    virtual bool is_complex() const final {return false;}
};

class VisibleObject: public SimpleObject
{
public:
    VisibleObject();
    virtual ~VisibleObject() = 0;

    virtual bool is_drawable() const final {return true;}
};

class InvisibleObject: public SimpleObject
{
public:
    InvisibleObject();
    virtual ~InvisibleObject() = 0;

    virtual bool is_drawable() const final {return false;}
};

#endif // SIMPLE_OBJECT_H
