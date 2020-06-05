#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QWidget>
#include "controller.h"
#include "cabine.h"

class Elevator: public QHBoxLayout
{
    Q_OBJECT
public:
    Elevator(size_t floor_n, QWidget *parent=nullptr);
    virtual ~Elevator();

private:
    Controller _controller;
    Cabine _cabine;
};

#endif // ELEVATOR_H
