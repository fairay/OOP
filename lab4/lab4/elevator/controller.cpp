#include "controller.h"

Controller::Controller(size_t floor_n, QWidget *parent):
    QWidget(parent), _floor_n(floor_n), _but_box()
{
    this->setLayout(&_but_box);

    for (int i=0; i < static_cast<int>(floor_n); i++)
    {
        Button *new_but = new Button(i, this);
        _but_box.addWidget(new_but);
        _but_arr.push_back(shared_ptr<Button>(new_but));
    }
}

Controller::~Controller()
{
    // delete _but_box;
}
