#ifndef BASE_EDGE_H
#define BASE_EDGE_H

#include "objects/simple_object.h"
#include "objects/point/base_point.h"

class BaseEdge: public VisibleObject
{
public:
    BaseEdge();
    BaseEdge(const BasePoint& p1, const BasePoint& p2);
    explicit BaseEdge(const BaseEdge& other);
    virtual ~BaseEdge() = 0;

    BasePoint& get_p1();
    BasePoint& get_p2();

    const BasePoint& get_p1() const;
    const BasePoint& get_p2() const;

    void set_p1(const BasePoint& point);
    void set_p2(const BasePoint& point);

private:
    BasePoint _p1, _p2;
};

#endif // BASE_EDGE_H
