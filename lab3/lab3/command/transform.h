#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "base_command.h"

namespace command
{
class Transform: public BaseCommand
{
public:
    Transform(size_t index);
    virtual ~Transform();

    virtual void execute(weak_ptr<BaseScene> scene);
protected:
    size_t _index;
};

} // command

#endif // TRANSFORM_H
