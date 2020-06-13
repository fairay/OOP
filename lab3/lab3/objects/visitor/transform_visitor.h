#ifndef TRANSFORM_VISITOR_H
#define TRANSFORM_VISITOR_H

#include "object_visitor.h"
#include "transform/transformator.h"

class TransformVisitor: public ObjectVisitor
{
public:
    TransformVisitor(weak_ptr<Transformator> trans);
    virtual ~TransformVisitor();

    virtual void visit(BasePoint& point);
    virtual void visit(BaseCamera& camera);
    virtual void visit(BaseEdge& edge);
    virtual void visit(BaseCarcass& carcass);

protected:
    weak_ptr<Transformator> _trans;
};

#endif // TRANSFORM_VISITOR_H
