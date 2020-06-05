#include "controller.h"

Controller::Controller(size_t floor_n, QWidget *parent):
    QWidget(parent), _floor_n(floor_n), _but_box()
{
    _low_floor = 0;
    _up_floor = static_cast<int>(floor_n)-1;

    this->setLayout(&_but_box);

    for (int i=_low_floor; i<=_up_floor; i++)
    {
        Button *new_but = new Button(i, this);

        QWidget::connect(new_but, SIGNAL(elevator_called(int)),
                         this, SLOT(get_new_call(int)));

        _but_arr.push_back(shared_ptr<Button>(new_but));
        _call_arr.push_back(false);
    }

    for (int i=_up_floor; i>=_low_floor; i--)
    {
        shared_ptr<Button> ptr = _but_arr[_to_index(i)];
        _but_box.addWidget(ptr.get());
    }
}

Controller::~Controller() {}

void Controller::floor_visited(int floor, Direction dir)
{
    if (_status != WAITING) return;
    _status = WAITING;

    size_t arr_i = _to_index(floor);
    _call_arr[arr_i] = false;

    int new_floor = _find_request(floor, dir);
    if (new_floor <= _up_floor)
        get_new_call(new_floor);
}

void Controller::get_new_call(int floor)
{
    _status = PROCESSING;

    size_t arr_i = _to_index(floor);
    std::cout << "(*)\t Request " << floor << " floor" << endl;
    _call_arr[arr_i] = true;
    emit request_visit(floor);
}

size_t Controller::_to_index(int floor)
{
    return static_cast<size_t>(floor-_low_floor);
}

int Controller::_find_request(int floor, Direction dir)
{
    if (!dir) dir = UP;

    for (int i=floor; i>=_low_floor && i <= _up_floor; i+=dir)
    {
        if (_call_arr[_to_index(i)])
            return i;
    }

    for (int i=floor; i>=_low_floor && i <= _up_floor; i-=dir)
    {
        if (_call_arr[_to_index(i)])
            return i;
    }

    return _up_floor+1;
}
