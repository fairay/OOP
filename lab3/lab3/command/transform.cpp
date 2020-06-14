#include "transform.h"

using namespace command;

Transform::Transform(Transformation* strat, size_t index):
    _trans(new Transformator(strat)), _index(index) {}
Transform::~Transform() {}

void Transform::execute(weak_ptr<BaseScene> scene)
{
    TransformManager(scene, _trans, _index).execute();
}


Rotate::Rotate(double ax, double ay, double az, size_t index):
    Transform (new transf::Rotate(ax, ay, az), index) {}
Rotate::~Rotate() {}

Move::Move(double ax, double ay, double az, size_t index):
    Transform (new transf::Move(ax, ay, az), index) {}
Move::~Move() {}

Scale::Scale(double ax, double ay, double az, size_t index):
    Transform (new transf::Scale(ax, ay, az), index) {}
Scale::~Scale() {}
