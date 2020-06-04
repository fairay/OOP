#include "elevator.h"

Elevator::Elevator(size_t floor_n): _controler(floor_n) {}

Elevator::~Elevator() {};

QWidget* Elevator::get_qwidget()
{
    return &_controler;
}
