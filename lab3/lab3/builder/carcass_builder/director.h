#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "base_builder.h"
#include "builder/build_director.h"

namespace CarcassBuilder {
class Director: public BuildDirector
{
public:
    Director(shared_ptr<BaseBuilder> bld);
    virtual ~Director();

    virtual shared_ptr<SceneObject> create();
private:
    shared_ptr<BaseBuilder> _builder;
};
} // CarcassBuilder

#endif // DIRECTOR_H
