#ifndef BASE_BUILDER_H
#define BASE_BUILDER_H

#include "builder/builder.h"
#include "objects/carcass/carcass.h"
#include "objects/point/point.h"
#include "objects/edge/edge.h"

namespace CarcassBuilder {

class BaseBuilder: public Builder
{
public:
    BaseBuilder(): _carcass(new Carcass()) {}
    virtual ~BaseBuilder() = default;

    virtual void open();
    virtual void load_nodes();
    virtual void load_edges();
    virtual void close();

protected:
    shared_ptr<Carcass> _carcass;
};

} // CarcassBuilder

#endif // BASE_BUILDER_H
