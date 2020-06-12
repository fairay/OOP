#include "point.h"

Point::Point() {}
Point::Point(double x, double y, double z): BasePoint (x, y, z) {}
Point::Point(const Point& other): BasePoint (other) {}

Point::~Point() {}

void Point::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

unique_ptr<SceneObject> Point::clone()
{
    return unique_ptr<SceneObject>(new Point(*this));
}
