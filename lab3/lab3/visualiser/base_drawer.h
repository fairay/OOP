#ifndef BASE_DRAWER_H
#define BASE_DRAWER_H

#include "errors/drawer_errors.h"

class BaseDrawer
{
public:
    BaseDrawer();
    virtual ~BaseDrawer() = 0;

    virtual void draw_line(double x1, double y1, double x2, double y2) = 0;
    virtual void draw_point(double x, double y) = 0;
    virtual void clear() = 0;
};

#endif // BASE_DRAWER_H
