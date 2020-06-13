#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H

#include "scene/base_scene.h"
#include "managers/scene_manager.h"

namespace command
{

class BaseCommand
{
public:
    BaseCommand();
    virtual ~BaseCommand() = 0;

    virtual void execute(weak_ptr<BaseScene> scene) = 0;
};

} // command
#endif // BASE_COMMAND_H
