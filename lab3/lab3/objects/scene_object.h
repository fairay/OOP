#ifndef SNENE_OBJECT_H
#define SNENE_OBJECT_H

#include "errors/object_errors.h"
#include "memory"

class ObjectVisitor;

using namespace std;
class SceneObject
{
public:
    SceneObject() = default;
    virtual ~SceneObject() = default;

    virtual bool is_drawable() const {return false;}
    virtual bool is_observer() const {return false;}
    virtual bool is_complex() const {return false;}

    virtual void accept(shared_ptr<ObjectVisitor>)
    {throw err::UndefindeVisiter(__FILE__, __LINE__);}

    virtual unique_ptr<SceneObject> clone()
    { throw err::UndefindeClone(__FILE__, __LINE__);}
};

#endif // SNENE_OBJECT_H
