#include "draw_visitor.h"

DrawVisitor::DrawVisitor(weak_ptr<Visualizer> visual):
    _visual(visual) {}

DrawVisitor::~DrawVisitor() = default;


void DrawVisitor::visit(BasePoint &point)
{

}

void DrawVisitor::visit(BaseCamera& camera)
{

}

void DrawVisitor::visit(BaseEdge& edge)
{

}

void DrawVisitor::visit(BaseCarcass& carcass)
{

}
