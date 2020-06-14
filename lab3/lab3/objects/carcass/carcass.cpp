#include "carcass.h"

Carcass::Carcass() {}
Carcass::Carcass(const Carcass& other): BaseCarcass (other) {}

Carcass::~Carcass() {}

void Carcass::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

SceneObject *Carcass::clone()
{
    return (new Carcass(*this));
}
