#include "draw_scene.h"

using namespace command;

DrawScene::DrawScene() {}
DrawScene::~DrawScene() {}
void DrawScene::execute(weak_ptr<BaseScene> scene)
{
    DrawManager mng(scene, _draw_factory);
    mng.execute();
    cout << "Done" << endl;
}

QDrawScene::QDrawScene(weak_ptr<QGraphicsScene> scene,
                       const QPen& point, const QPen& line)
{
    _draw_factory = shared_ptr<BaseDrawerFactory>
            (new QDrawerFactory(scene, point, line));
}
QDrawScene::~QDrawScene() {}
