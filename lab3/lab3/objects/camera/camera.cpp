#include "camera.h"

Camera::Camera() {}
Camera::Camera(double x, double y, double z): BaseCamera (x, y, z) {}
Camera::Camera(const Camera& other): BaseCamera (other) {}

Camera::~Camera() {}

void Camera::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

unique_ptr<SceneObject> Camera::clone()
{
    return unique_ptr<SceneObject>(new Camera(*this));
}
