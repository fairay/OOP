#include "elevator.h"

Elevator::Elevator(size_t floor_n, QWidget *parent):
    QHBoxLayout(parent), _controller(floor_n), _cabine(1)
{
    cout << "Elevator created at 1 floor" << endl;
    cout << "(*)\t - controller" << endl;
    cout << "/_\\\t - cabine" << endl;
    cout << "|<->|\t - doors" << endl << endl;

    this->addWidget(&_controller);

    QWidget::connect(&_controller, SIGNAL(request_visit(int)),
                     &_cabine, SLOT(request_waiting(int)));
    QWidget::connect(&_controller, SIGNAL(request_visit(int)),
                     &_cabine, SLOT(doors_waiting(int)));

    QWidget::connect(&_cabine, SIGNAL(dest_get(int, Direction)),
                     &_controller, SLOT(floor_visited(int, Direction)));
}

Elevator::~Elevator() {};

