#include "qdrawer.h"

QDrawer::QDrawer(weak_ptr<QGraphicsScene> scene,
        const QPen& point_pen, const QPen& line_pen):
    _scene(scene), _point_pen(point_pen), _line_pen(line_pen)
{
    _point_brush = QBrush(_line_pen.color());
}
QDrawer::~QDrawer() {}


void QDrawer::draw_line(double x1, double y1, double x2, double y2)
{
    if (_scene.expired()) throw err::SceneExpired(__FILE__, __LINE__);
    shared_ptr<QGraphicsScene> sc = _scene.lock();
    sc->addLine(x1, -y1, x2, -y2, _line_pen);
}

void QDrawer::draw_point(double x, double y)
{
    if (_scene.expired()) throw err::SceneExpired(__FILE__, __LINE__);
    shared_ptr<QGraphicsScene> sc = _scene.lock();
    sc->addEllipse(x-3, -y-3, 6, 6, _point_pen, _point_brush);
}

void QDrawer::clear()
{
    if (_scene.expired()) throw err::SceneExpired(__FILE__, __LINE__);
    shared_ptr<QGraphicsScene> sc = _scene.lock();
    sc->clear();
}
