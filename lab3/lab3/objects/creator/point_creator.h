#ifndef POINT_CREATOR_H
#define POINT_CREATOR_H

#include "object_creator.h"
#include "objects/point/point.h"

class PointCreator: public ObjectCreator
{
public:
    PointCreator();
    PointCreator(double x, double y, double z):
        _x(x), _y(y), _z(z) {}
    virtual ~PointCreator() override;

    virtual SceneObject* create() override
    { return new Point(_x, _y, _z);}
private:
    double _x, _y, _z;
};

#endif // POINT_CREATOR_H
