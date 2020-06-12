#include "edge.h"

Edge::Edge() {}
Edge::Edge(const BasePoint& p1, const BasePoint& p2): BaseEdge (p1, p2) {}
Edge::Edge(const Edge& other): BaseEdge (other) {}

Edge::~Edge() {}

void Edge::accept(shared_ptr<ObjectVisitor> visitor)
{
    visitor->visit(*this);
}

unique_ptr<SceneObject> Edge::clone()
{
    return unique_ptr<SceneObject>(new Edge(*this));
}
