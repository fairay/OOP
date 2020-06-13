#include "transform_visitor.h"

TransformVisitor::TransformVisitor(weak_ptr<Transformator> trans):
    _trans(trans) {}

TransformVisitor::~TransformVisitor() = default;


void TransformVisitor::visit(BasePoint &point)
{
    if (_trans.expired())
        throw err::TransExpired(__FILE__, __LINE__-1);
}

void TransformVisitor::visit(BaseCamera& camera)
{
    if (_trans.expired())
        throw err::TransExpired(__FILE__, __LINE__-1);
}

void TransformVisitor::visit(BaseEdge& edge)
{
    if (_trans.expired())
        throw err::TransExpired(__FILE__, __LINE__-1);
}

void TransformVisitor::visit(BaseCarcass& carcass)
{
    if (_trans.expired())
        throw err::TransExpired(__FILE__, __LINE__-1);
}
