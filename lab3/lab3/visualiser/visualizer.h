#ifndef VISUALIZER_H
#define VISUALIZER_H

#include "base_drawer.h"
#include "base_drawer_factory.h"
#include "objects/camera/base_camera.h"
#include "objects/point/point.h"
#include "memory"
#include "math.h"

using namespace std;
class Visualizer
{
public:
    Visualizer();
    ~Visualizer();

    void set_draw(BaseDrawerFactory& factory);
    void set_camera(shared_ptr<BaseCamera> camera);

    void draw_line(const BasePoint& p1, const BasePoint& p2);
    void draw_point(const BasePoint& p);
    void clear();

private:
    shared_ptr<BaseDrawer> _draw;
    shared_ptr<BaseCamera> _camera;

    shared_ptr<BasePoint> _proj_point(const BasePoint& p);
};

#endif // VISUALIZER_H
