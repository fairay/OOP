#ifndef BUILDER_H
#define BUILDER_H

#include "objects/scene_object.h"
#include "errors/builder_errors.h"

using namespace std;

class Builder
{
public:
    Builder();
    virtual ~Builder() = 0;

    virtual shared_ptr<SceneObject> get_object() = 0;
};

#endif // BUILDER_H
