#ifndef BASE_CARCASS_H
#define BASE_CARCASS_H

#include "objects/composite_object.h"

class BaseCarcass: public CompositeObject
{
public:
    BaseCarcass();
    explicit BaseCarcass(const BaseCarcass& other);
    virtual ~BaseCarcass();

    virtual bool is_drawable() final;
    virtual bool is_observer() final;
};

#endif // BASE_CARCASS_H
