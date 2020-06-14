#include "qdrawer_factory.h"

QDrawerFactory::QDrawerFactory(weak_ptr<QGraphicsScene> scene,
               const QPen& p_pen, const QPen& l_pen):
    _scene(scene), _p_pen(p_pen), _l_pen(l_pen) {}

QDrawerFactory::~QDrawerFactory() {};

BaseDrawer* QDrawerFactory::create()
{
    return new QDrawer(_scene, _p_pen, _l_pen);
}
