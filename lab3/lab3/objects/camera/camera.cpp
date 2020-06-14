#include "camera.h"

Camera::Camera() {}
Camera::Camera(double x, double y, double z): BaseCamera (x, y, z) {}
Camera::Camera(const Camera& other): BaseCamera (other) {}

Camera::~Camera() { cout << "Camera deleted" << endl;}

void Camera::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

SceneObject* Camera::clone()
{
    return (new Camera(*this));
}
