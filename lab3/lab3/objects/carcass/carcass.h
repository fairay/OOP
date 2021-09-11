#ifndef CARCASS_H
#define CARCASS_H

#include "base_carcass.h"
#include "objects/visitor/object_visitor.h"

class Carcass: public BaseCarcass
{
public:
    Carcass();
    explicit Carcass(const Carcass& other);
    virtual ~Carcass();

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual SceneObject* clone();
};

#endif // CARCASS_H
