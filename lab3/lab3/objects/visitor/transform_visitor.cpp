#include "transform_visitor.h"

TransformVisitor::TransformVisitor(weak_ptr<Transformator> trans):
    _trans(trans) {}

TransformVisitor::~TransformVisitor() = default;


void TransformVisitor::visit(BasePoint &point)
{

}

void TransformVisitor::visit(BaseCamera& camera)
{

}

void TransformVisitor::visit(BaseEdge& edge)
{

}

void TransformVisitor::visit(BaseCarcass& carcass)
{

}
