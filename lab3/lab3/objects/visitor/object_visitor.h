#ifndef OBJECT_VISITOR_H
#define OBJECT_VISITOR_H

#include "objects/camera/base_camera.h"
#include "objects/edge/base_edge.h"
#include "objects/point/base_point.h"
#include "objects/carcass/base_carcass.h"
#include "errors/object_errors.h"

class ObjectVisitor
{
public:
    ObjectVisitor();
    virtual ~ObjectVisitor() = 0;
    void set_ptr(shared_ptr<ObjectVisitor>& ptr);

    virtual void visit(BasePoint& point) = 0;
    virtual void visit(BaseCamera& point) = 0;
    virtual void visit(BaseEdge& point) = 0;
    virtual void visit(BaseCarcass& point) = 0;
protected:
    shared_ptr<ObjectVisitor> _this_ptr;
};

#endif // OBJECT_VISITOR_H
