#ifndef SNENE_OBJECT_H
#define SNENE_OBJECT_H

#include "errors/object_errors.h"
#include "memory"

class ObjectVisitor;

using namespace std;
class SceneObject
{
public:
    SceneObject();
    virtual ~SceneObject() = 0;

    virtual bool is_drawable() const;
    virtual bool is_observer() const;
    virtual bool is_complex() const;

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual SceneObject* clone();
};

#endif // SNENE_OBJECT_H
