#ifndef EDGE_CREATOR_H
#define EDGE_CREATOR_H

#include "object_creator.h"
#include "objects/edge/edge.h"

class EdgeCreator: public ObjectCreator
{
public:
    EdgeCreator();
    virtual ~EdgeCreator() override;

    virtual unique_ptr<SceneObject> create() override
    { return unique_ptr<SceneObject>(new Edge(p1, p2));}
private:
    Point p1, p2;
};

EdgeCreator::~EdgeCreator() {}


#endif // EDGE_CREATOR_H
