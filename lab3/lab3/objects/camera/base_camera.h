#ifndef BASE_CAMERA_H
#define BASE_CAMERA_H

#include "objects/simple_object.h"

class BaseCamera: public VisibleObject
{
public:
    BaseCamera();
    BaseCamera(double x, double y, double z);
    explicit BaseCamera(const BaseCamera& other);
    virtual ~BaseCamera();

    double& get_x();
    double& get_y();
    double& get_z();

    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(double val);
    void set_y(double val);
    void set_z(double val);

private:
    double _x, _y, _z;
};


#endif // BASE_CAMERA_H
