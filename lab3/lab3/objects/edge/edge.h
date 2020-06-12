#ifndef EDGE_H
#define EDGE_H

#include "base_edge.h"
#include "objects/visitor/object_visitor.h"

class Edge: public BaseEdge
{
public:
    Edge();
    Edge(const BasePoint& p1, const BasePoint& p2);
    explicit Edge(const Edge& other);
    virtual ~Edge();

    virtual void accept(shared_ptr<ObjectVisitor>);
    virtual unique_ptr<SceneObject> clone();
};


#endif // EDGE_H
