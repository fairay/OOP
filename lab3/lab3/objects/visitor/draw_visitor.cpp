#include "draw_visitor.h"

DrawVisitor::DrawVisitor(weak_ptr<Visualizer> visual):
    _visual(visual) {}

DrawVisitor::~DrawVisitor() = default;


void DrawVisitor::visit(BasePoint &point)
{
    if (_visual.expired())
        throw err::VisualExpired(__FILE__, __LINE__-1);
    _visual.lock()->draw_point(point);
}

void DrawVisitor::visit(BaseCamera&)
{
}

void DrawVisitor::visit(BaseEdge& edge)
{
    cout << "Draw line" << endl;
    if (_visual.expired())
        throw err::VisualExpired(__FILE__, __LINE__-1);
    _visual.lock()->draw_line(edge.get_p1(), edge.get_p2());
}

void DrawVisitor::visit(BaseCarcass& carcass)
{
    if (_visual.expired())
        throw err::VisualExpired(__FILE__, __LINE__-1);

    for (auto obj : carcass)
        obj->accept(_this_ptr);
}
