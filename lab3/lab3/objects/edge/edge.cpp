#include "edge.h"

Edge::Edge() {}
Edge::Edge(const Point &p1, const Point &p2): BaseEdge (p1, p2) {}
Edge::Edge(const Edge& other): BaseEdge (other) {}

Edge::~Edge() {}

void Edge::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

SceneObject *Edge::clone()
{
    return (new Edge(*this));
}
