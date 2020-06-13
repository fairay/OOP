#ifndef BUILDER_H
#define BUILDER_H

#include "objects/scene_object.h"
#include "errors/builder_errors.h"

using namespace std;

class Builder
{
public:
    Builder() = default;
    virtual ~Builder() = default;

    virtual shared_ptr<SceneObject> get_object() = 0;
};

#endif // BUILDER_H
