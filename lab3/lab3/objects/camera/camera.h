#ifndef CAMERA_H
#define CAMERA_H


#include "base_camera.h"
#include "objects/visitor/object_visitor.h"

class Camera: public BaseCamera
{
public:
    Camera();
    Camera(double x, double y, double z);
    explicit Camera(const Camera& other);
    virtual ~Camera();

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual unique_ptr<SceneObject> clone();
};

#endif // CAMERA_H
