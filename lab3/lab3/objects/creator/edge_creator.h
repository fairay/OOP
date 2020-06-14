#ifndef EDGE_CREATOR_H
#define EDGE_CREATOR_H

#include "object_creator.h"
#include "objects/edge/edge.h"
#include "objects/point/point.h"

class EdgeCreator: public ObjectCreator
{
public:
    EdgeCreator();
    virtual ~EdgeCreator() override;

    virtual SceneObject* create() override
    { return new Edge(p1, p2);}
private:
    Point p1, p2;
};

#endif // EDGE_CREATOR_H
