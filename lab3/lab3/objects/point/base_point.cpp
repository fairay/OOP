#include "base_point.h"

BasePoint::BasePoint() {}
BasePoint::BasePoint(double x, double y, double z):
    _x(x), _y(y), _z(z) {}

BasePoint::BasePoint(const BasePoint& other)
{
    _x = other.get_x();
    _y = other.get_y();
    _z = other.get_z();
}

BasePoint::~BasePoint() = default;

double& BasePoint::get_x() {return _x;}
double& BasePoint::get_y() {return _y;}
double& BasePoint::get_z() {return _z;}

double BasePoint::get_x() const {return _x;}
double BasePoint::get_y() const {return _y;}
double BasePoint::get_z() const {return _z;}

void BasePoint::set_x(double val) {_x = val;}
void BasePoint::set_y(double val) {_y = val;}
void BasePoint::set_z(double val) {_z = val;}

