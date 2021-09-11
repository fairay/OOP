#ifndef DRAW_H
#define DRAW_H

#include "defines.h"
#include <QGraphicsScene>

#define PONIT_R     4

typedef enum
{
    RED,
    DARK_RED,
    BLUE,
    DARK_BLUE,
    YELLOW,
    GRAY,
    BLACK
} paint_color_t;

typedef struct
{
    QGraphicsScene *scene;

    QBrush p_brush;
    QPen p_pen;
    int p_r;

    QPen e_pen;

    QPen axis_pen;
} draw_t;

draw_t init_draw(QGraphicsScene *scene);
err_t clear_draw(draw_t &draw);

err_t add_point(draw_t &draw, double x, double y);
err_t add_axis_line(draw_t &draw, double x1, double y1, double x2, double y2);
err_t add_line(draw_t &draw, double x1, double y1, double x2, double y2);

#endif // DRAW_H
