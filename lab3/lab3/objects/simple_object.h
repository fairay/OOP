#ifndef SIMPLE_OBJECT_H
#define SIMPLE_OBJECT_H

#include "scene_object.h"

class SimpleObject: public SceneObject
{
public:
    SimpleObject() = default;
    virtual ~SimpleObject() = default;

    virtual bool is_complex() const final {return false;}
};

class VisibleObject: public SimpleObject
{
public:
    VisibleObject() = default;
    virtual ~VisibleObject() = default;

    virtual bool is_drawable() const final {return true;}
};

class InvisibleObject: public SimpleObject
{
public:
    InvisibleObject() = default;
    virtual ~InvisibleObject() = default;

    virtual bool is_drawable() const final {return false;}
};

#endif // SIMPLE_OBJECT_H
