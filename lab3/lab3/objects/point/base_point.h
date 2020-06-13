#ifndef BASE_POINT_H
#define BASE_POINT_H

#include "objects/simple_object.h"

class BasePoint: public VisibleObject
{
public:
    BasePoint();
    BasePoint(double x, double y, double z);
    BasePoint(const BasePoint& other);
    virtual ~BasePoint();

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

#endif // BASE_POINT_H
