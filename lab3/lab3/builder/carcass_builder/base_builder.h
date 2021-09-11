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
    BaseBuilder();
    virtual ~BaseBuilder() = 0;

    virtual void load_nodes() = 0;
    virtual void load_edges() = 0;

    virtual shared_ptr<SceneObject> get_object();

protected:
    shared_ptr<Carcass> _carcass;
};

} // CarcassBuilder

#endif // BASE_BUILDER_H
