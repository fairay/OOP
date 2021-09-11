#ifndef REMOVE_OBJECT_H
#define REMOVE_OBJECT_H

#include "base_command.h"

namespace command
{

class RemoveObject: public BaseCommand
{
public:
    RemoveObject(size_t index);
    virtual ~RemoveObject();

    virtual void execute(weak_ptr<BaseScene> scene);
protected:
    size_t _index;
};

} // command

#endif // REMOVE_OBJECT_H
