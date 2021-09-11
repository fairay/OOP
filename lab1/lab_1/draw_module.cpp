#include "draw_module.h"

typedef QColor color_t;

//
color_t get_paint_color(paint_color_t color)
{
    color_t qcolor;
    switch (color)
    {
    case RED:
        qcolor = Qt::red;
        break;
    case DARK_RED:
        qcolor = Qt::darkRed;
        break;
    case BLUE:
        qcolor = Qt::blue;
        break;
    case DARK_BLUE:
        qcolor = Qt::darkBlue;
        break;
    case YELLOW:
        qcolor = Qt::yellow;
        break;
    case GRAY:
        qcolor = Qt::gray;
        break;
    default:
        qcolor = Qt::black;
    }
    return qcolor;
}

//
draw_t init_draw(QGraphicsScene *scene)
{
    draw_t draw;
    draw.scene = scene;

    draw.p_brush = QBrush(get_paint_color(YELLOW));
    draw.p_pen = QPen(get_paint_color(DARK_RED));
    draw.p_r = PONIT_R;

    draw.e_pen = QPen(get_paint_color(DARK_BLUE));
    draw.e_pen.setWidth(3);

    draw.axis_pen = QPen(get_paint_color(GRAY));
    draw.axis_pen.setStyle(Qt::DashLine);
    return draw;
}

//
void set_p_brush(draw_t &draw, paint_color_t color)
{
    draw.p_brush.setColor(get_paint_color(color));
}
void set_p_pen(draw_t &draw, paint_color_t color)
{
    draw.p_pen.setColor(get_paint_color(color));
}
void set_e_pen(draw_t &draw, paint_color_t color)
{
    draw.e_pen.setColor(get_paint_color(color));
}
void set_axis_pen(draw_t &draw, paint_color_t color)
{
    draw.axis_pen.setColor(get_paint_color(color));
}

//
err_t clear_draw(draw_t &draw)
{
    if (!draw.scene)    return WRONG_DRAW;
    draw.scene->clear();
    return CORRECT_WORK;
}

err_t add_point(draw_t &draw, double x, double y)
{
    if (!draw.scene)    return WRONG_DRAW;
    draw.scene->addEllipse(x - draw.p_r, y - draw.p_r,
                           draw.p_r*2, draw.p_r*2,
                           draw.p_pen, draw.p_brush);
    return CORRECT_WORK;
}

err_t add_axis_line(draw_t &draw, double x1, double y1, double x2, double y2)
{
    if (!draw.scene)    return WRONG_DRAW;
    draw.scene->addLine(x1, y1, x2, y2, draw.axis_pen);
    return CORRECT_WORK;
}
err_t add_line(draw_t &draw, double x1, double y1, double x2, double y2)
{
    if (!draw.scene)    return WRONG_DRAW;
    draw.scene->addLine(x1, y1, x2, y2, draw.e_pen);
    return CORRECT_WORK;
}
