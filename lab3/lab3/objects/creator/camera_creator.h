#ifndef CAMERA_CREATOR_H
#define CAMERA_CREATOR_H

#include "object_creator.h"
#include "objects/camera/camera.h"

class CameraCreator: public ObjectCreator
{
public:
    CameraCreator();
    CameraCreator(double x, double y, double z):
        _x(x), _y(y), _z(z) {}
    virtual ~CameraCreator() override;

    virtual unique_ptr<SceneObject> create() override
    { return unique_ptr<SceneObject>(new Camera(_x, _y, _z));}
private:
    double _x, _y, _z;
};

CameraCreator::~CameraCreator() {}

#endif // CAMERA_CREATOR_H
