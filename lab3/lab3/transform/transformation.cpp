#include "tranformation.h"

Transformation::~Transformation() {}

using namespace transf;

Move::Move(double dx, double dy, double dz):
    _dx(dx), _dy(dy), _dz(dz) {}

Move::~Move() {}

void Move::execute(double& x, double& y, double& z)
{
    x += _dx;
    y += _dy;
    z += _dz;
}


Scale::Scale(double dx, double dy, double dz):
    _kx(dx), _ky(dy), _kz(dz) {}

Scale::~Scale() {}

void Scale::execute(double& x, double& y, double& z)
{
    x *= _kx;
    y *= _ky;
    z *= _kz;
}


Rotate::Rotate(double dx, double dy, double dz)
{
    _ax = _to_radians(dx);
    _ay = _to_radians(dy);
    _az = _to_radians(dz);
}

Rotate::~Rotate() {}

void Rotate::execute(double& x, double& y, double& z)
{
    rotate_x(x, y, z);
    rotate_y(x, y, z);
    rotate_z(x, y, z);
}

void Rotate::rotate_x(double&, double& y_, double& z_)
{
    double y, z;
    y = y_*cos(_ax) + z_*sin(_ax);
    z = -y_*sin(_ax) + z_*cos(_ax);

    y_ = y;
    z_ = z;
}
void Rotate::rotate_y(double& x_, double&, double& z_)
{
    double x, z;
    x = x_*cos(_ay) - z_*sin(_ay);
    z = x_*sin(_ay) + z_*cos(_ay);

    x_ = x;
    z_ = z;
}
void Rotate::rotate_z(double& x_, double& y_, double&)
{
    double y, x;
    x = x_*cos(_az) + y_*sin(_az);
    y = -x_*sin(_az) + y_*cos(_az);

    x_ = x;
    y_ = y;
}

double Rotate::_to_radians(double a)
{
    return a * PI / 180;
}
