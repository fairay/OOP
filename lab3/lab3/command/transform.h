#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "base_command.h"
#include "transform/transformator.h"

namespace command
{
class Transform: public BaseCommand
{
public:
    Transform(Transformation* strat, size_t index);
    virtual ~Transform() = 0;

    virtual void execute(weak_ptr<BaseScene> scene);
protected:
    shared_ptr<Transformator> _trans;
    size_t _index;
};



class Rotate: public Transform
{
public:
    Rotate(double ax, double ay, double az, size_t index);
    virtual ~Rotate();
};

class Move: public Transform
{
public:
    Move(double dx, double dy, double dz, size_t index);
    virtual ~Move();
};

class Scale: public Transform
{
public:
    Scale(double kx, double ky, double kz, size_t index);
    virtual ~Scale();
};

} // command

#endif // TRANSFORM_H
