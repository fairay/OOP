#ifndef CHANGE_CAMERA_H
#define CHANGE_CAMERA_H

#include "base_command.h"

namespace command
{

class ChangeCamera: public BaseCommand
{
public:
    ChangeCamera(size_t index);
    virtual ~ChangeCamera();

    virtual void execute(weak_ptr<BaseScene> scene);
protected:
    size_t _index;
};

} // command

#endif // CHANGE_CAMERA_H
