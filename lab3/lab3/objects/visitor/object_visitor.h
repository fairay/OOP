#ifndef OBJECT_VISITOR_H
#define OBJECT_VISITOR_H

#include "objects/camera/base_camera.h"
#include "objects/edge/base_edge.h"
#include "objects/point/base_point.h"
#include "objects/carcass/base_carcass.h"

class ObjectVisitor
{
public:
    ObjectVisitor() {}
    virtual ~ObjectVisitor() = 0;

    virtual void visit(BasePoint& point) = 0;
    virtual void visit(BaseCamera& point) = 0;
    virtual void visit(BaseEdge& point) = 0;
    virtual void visit(BaseCarcass& point) = 0;
};

#endif // OBJECT_VISITOR_H