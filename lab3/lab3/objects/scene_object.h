#ifndef SNENE_OBJECT_H
#define SNENE_OBJECT_H

#include "errors/object_errors.h"

class Visualizer;
class Transformator;

class SceneObject
{
public:
    SceneObject();
    virtual ~SceneObject() = 0;

    virtual bool is_drawable() {return false;}
    virtual bool is_observer() {return false;}
    virtual bool is_complex() {return false;}
    virtual void transform(const Transformator&);
    virtual void draw(Visualizer&);
    virtual void clone();
};

void SceneObject::transform(const Transformator&)
{
    throw err::NotTransable(__FILE__, __LINE__);
}
void SceneObject::draw(Visualizer&)
{
    throw err::NotDrawable(__FILE__, __LINE__);
}
void SceneObject::clone()
{
    throw err::UndefindeClone(__FILE__, __LINE__);
}
#endif // SNENE_OBJECT_H
