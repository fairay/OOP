#include "add_object.h"

using namespace command;

AddObject::AddObject() {}
AddObject::~AddObject() {}
void AddObject::execute(weak_ptr<BaseScene> scene)
{
    AddManager(scene, _creator).execute();
}

AddCamera::AddCamera(double x, double y, double z)
{
    _creator = shared_ptr<ObjectCreator>(new CameraCreator(x, y, z));
}
AddCamera::~AddCamera() {}

AddPoint::AddPoint(double x, double y, double z)
{
    _creator = shared_ptr<ObjectCreator>(new PointCreator(x, y, z));
}
AddPoint::~AddPoint() {}
