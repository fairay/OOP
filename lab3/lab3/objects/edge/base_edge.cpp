#include "base_edge.h"

BaseEdge::BaseEdge() {}
BaseEdge::BaseEdge(const BasePoint& p1, const BasePoint& p2):
    _p1(p1), _p2(p2) {}
BaseEdge::BaseEdge(const BaseEdge& other)
{
    _p1 = other.get_p1();
    _p2 = other.get_p2();
}
BaseEdge::~BaseEdge() {}

BasePoint& BaseEdge::get_p1()
{
    return _p1;
}
BasePoint& BaseEdge::get_p2()
{
    return _p2;
}

const BasePoint& BaseEdge::get_p1() const
{
    return _p1;
}
const BasePoint& BaseEdge::get_p2() const
{
    return _p2;
}

void BaseEdge::set_p1(const BasePoint& point)
{
    _p1 = point;
}
void BaseEdge::set_p2(const BasePoint& point)
{
    _p2 = point;
}
