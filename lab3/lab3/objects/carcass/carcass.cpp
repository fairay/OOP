#include "carcass.h"

Carcass::Carcass() {}
Carcass::Carcass(const Carcass& other): BaseCarcass (other) {}

Carcass::~Carcass() {}

void Carcass::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

unique_ptr<SceneObject> Carcass::clone()
{
    return unique_ptr<SceneObject>(new Carcass(*this));
}
