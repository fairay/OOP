#ifndef QDRAWER_FACTORY_H
#define QDRAWER_FACTORY_H

#include "base_drawer_factory.h"
#include "qdrawer.h"

class QDrawerFactory: public BaseDrawerFactory
{
public:
    QDrawerFactory(weak_ptr<QGraphicsScene> scene,
                   const QPen& p_pen, const QPen& l_pen);
    virtual ~QDrawerFactory();

    virtual unique_ptr<BaseDrawer> create();

private:
    weak_ptr<QGraphicsScene> _scene;
    QPen _p_pen, _l_pen;
};

#endif // QDRAWER_FACTORY_H
