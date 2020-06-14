#include "visualizer.h"

Visualizer::Visualizer() {}
Visualizer::~Visualizer() {}

void Visualizer::set_draw(BaseDrawerFactory& factory)
{
    _draw = shared_ptr<BaseDrawer>(factory.create());
}
void Visualizer::set_camera(shared_ptr<BaseCamera> camera)
{
    if (camera.get())
        _camera = camera;
    else
        throw err::NoSceneCamera(__FILE__, __LINE__-3);
}

void Visualizer::draw_line(const BasePoint& p1, const BasePoint& p2)
{
    BasePoint p1_proj(*_proj_point(p1));
    BasePoint p2_proj(*_proj_point(p2));
    _draw->draw_line(p1_proj.get_x(), p1_proj.get_y(),
                     p2_proj.get_x(), p2_proj.get_y());
}

void Visualizer::draw_point(const BasePoint& p)
{
    BasePoint new_p(*_proj_point(p));
    _draw->draw_point(new_p.get_x(), new_p.get_y());
}

void Visualizer::clear()
{
    _draw->clear();
}

shared_ptr<BasePoint> Visualizer::_proj_point(const BasePoint& p)
{
    shared_ptr<BasePoint> res(new Point());
    double k;

    if (fabs(_camera->get_z() - p.get_z()) < 1e-5)
        k = 1e20;
    else
        k = _camera->get_z() / (_camera->get_z() - p.get_z());

    res->set_z(0);
    res->set_x(_camera->get_x() + (p.get_x() - _camera->get_x())*k);
    res->set_y(_camera->get_y() + (p.get_y() - _camera->get_y())*k);
    return res;
}
