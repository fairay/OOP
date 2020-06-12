#ifndef BUILD_DIRECTOR_H
#define BUILD_DIRECTOR_H

#include "objects/scene_object.h"
#include "memory"

using namespace std;

class BuildDirector
{
public:
    BuildDirector() = default;
    virtual ~BuildDirector() = default;

    virtual shared_ptr<SceneObject> create();
};

#endif // BUILD_DIRECTOR_H
