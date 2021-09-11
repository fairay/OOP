#ifndef SCENE_INTERFACE_H
#define SCENE_INTERFACE_H

#include "base_scene.h"
#include "command/base_command.h"

class SceneInterface
{
public:
    SceneInterface(BaseScene* scene):
        _scene(scene) {}
    ~SceneInterface() = default;

    void execute(command::BaseCommand& cmd)
    { cmd.execute(weak_ptr<BaseScene>(_scene)); }
private:
    shared_ptr<BaseScene> _scene;
};

#endif // SCENE_INTERFACE_H
