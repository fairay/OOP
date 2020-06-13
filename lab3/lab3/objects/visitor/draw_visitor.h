#ifndef DRAW_VISITOR_H
#define DRAW_VISITOR_H

#include "object_visitor.h"
#include "visualiser/visualizer.h"

class DrawVisitor: public ObjectVisitor
{
public:
    DrawVisitor(weak_ptr<Visualizer> visual);
    virtual ~DrawVisitor();

    virtual void visit(BasePoint& point);
    virtual void visit(BaseCamera& camera);
    virtual void visit(BaseEdge& edge);
    virtual void visit(BaseCarcass& carcass);
protected:
    weak_ptr<Visualizer> _visual;
};

#endif // DRAW_VISITOR_H
