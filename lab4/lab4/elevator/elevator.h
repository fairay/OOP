#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include "controller.h"

class Elevator
{
public:
    Elevator(size_t floor_n);
    virtual ~Elevator();
    QWidget* get_qwidget();

private:
    Controller _controller;
};

#endif // ELEVATOR_H
