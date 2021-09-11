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

    virtual SceneObject* create() override
    { return new Camera(_x, _y, _z);}
private:
    double _x, _y, _z;
};

#endif // CAMERA_CREATOR_H
