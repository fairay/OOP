#ifndef BASE_CARCASS_H
#define BASE_CARCASS_H

#include "objects/composite_object.h"

class BaseCarcass: public CompositeObject
{
public:
    BaseCarcass();
    explicit BaseCarcass(const BaseCarcass& other);
    virtual ~BaseCarcass() = 0;

    virtual bool is_drawable() const final;
    virtual bool is_observer() const final;
};

#endif // BASE_CARCASS_H
