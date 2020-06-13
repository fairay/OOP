#ifndef ADD_OBJECT_H
#define ADD_OBJECT_H

#include "base_command.h"
#include "objects/creator/object_creator.h"
#include "objects/creator/camera_creator.h"

namespace command
{

class AddObject: public BaseCommand
{
public:
    AddObject();
    virtual ~AddObject() = 0;

    virtual void execute(weak_ptr<BaseScene> scene);
protected:
    shared_ptr<ObjectCreator> _creator;
};

class AddCamera: public AddObject
{
public:
    AddCamera(double x, double y, double z);
    virtual ~AddCamera();
};


} // command

#endif // ADD_OBJECT_H
