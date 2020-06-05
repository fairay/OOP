#include "elevator.h"

Elevator::Elevator(size_t floor_n): _controller(floor_n) {}

Elevator::~Elevator() {};

QWidget* Elevator::get_qwidget()
{
    return &_controller;
}
