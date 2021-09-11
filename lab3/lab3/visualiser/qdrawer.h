#ifndef QDRAWER_H
#define QDRAWER_H

#include "base_drawer.h"
#include "memory"
#include <QGraphicsScene>

using namespace std;
class QDrawer: public BaseDrawer
{
public:
    QDrawer(weak_ptr<QGraphicsScene> scene,
            const QPen& point_pen, const QPen& line_pen);
    virtual ~QDrawer();

    virtual void draw_line(double x1, double y1, double x2, double y2);
    virtual void draw_point(double x, double y);
    virtual void clear();

private:
    weak_ptr<QGraphicsScene> _scene;
    QPen _point_pen, _line_pen;
    QBrush _point_brush;
};

#endif // QDRAWER_H
