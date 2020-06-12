#include "base_carcass.h"

BaseCarcass::BaseCarcass() {};
BaseCarcass::BaseCarcass(const BaseCarcass& other):
    CompositeObject (other) {}

BaseCarcass::~BaseCarcass() {}

bool BaseCarcass::is_drawable()
{
    return true;
}
bool BaseCarcass::is_observer()
{
    return false;
}
