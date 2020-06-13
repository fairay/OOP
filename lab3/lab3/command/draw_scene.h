#ifndef DRAW_SCENE_H
#define DRAW_SCENE_H

#include "base_command.h"
#include "visualiser/qdrawer_factory.h"

namespace command
{

class DrawScene: public BaseCommand
{
public:
    DrawScene();
    virtual ~DrawScene() = 0;

    virtual void execute(weak_ptr<BaseScene> scene);
protected:
    shared_ptr<BaseDrawerFactory> _draw_factory;
};

class QDrawScene: public DrawScene
{
public:
    QDrawScene(weak_ptr<QGraphicsScene> scene,
               const QPen& point, const QPen& line);
    virtual ~QDrawScene();
};

} // command

#endif // DRAW_SCENE_H
