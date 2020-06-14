#ifndef BUILD_DIRECTOR_H
#define BUILD_DIRECTOR_H

#include "objects/scene_object.h"
#include "memory"

using namespace std;

class BuildDirector
{
public:
    BuildDirector();
    virtual ~BuildDirector() = 0;

    virtual shared_ptr<SceneObject> create() = 0;
};

#endif // BUILD_DIRECTOR_H
