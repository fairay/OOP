#include "transform_visitor.h"

TransformVisitor::TransformVisitor(weak_ptr<Transformator> trans):
    _trans(trans) {}

TransformVisitor::~TransformVisitor() = default;


void TransformVisitor::visit(BasePoint &point)
{
    if (_trans.expired())
        throw err::TransExpired(__FILE__, __LINE__-1);
    _trans.lock()->transform(point.get_x(), point.get_y(), point.get_z());
}

void TransformVisitor::visit(BaseCamera& camera)
{
    if (_trans.expired())
        throw err::TransExpired(__FILE__, __LINE__-1);
    _trans.lock()->transform(camera.get_x(), camera.get_y(), camera.get_z());
}

void TransformVisitor::visit(BaseEdge& edge)
{
    if (_trans.expired())
        throw err::TransExpired(__FILE__, __LINE__-1);
    BasePoint& p = edge.get_p1();
    _trans.lock()->transform(p.get_x(), p.get_y(), p.get_z());
    p = edge.get_p2();
    _trans.lock()->transform(p.get_x(), p.get_y(), p.get_z());
}

void TransformVisitor::visit(BaseCarcass& carcass)
{
    if (_trans.expired())
        throw err::TransExpired(__FILE__, __LINE__-1);
    for (auto obj : carcass)
        obj.accept(shared_ptr<ObjectVisitor>(this));
}
