#include "controller.h"

Controller::Controller(size_t floor_n, QWidget *parent):
    QWidget(parent), _floor_n(floor_n), _but_box()
{
    min_floor = 0;
    max_floor = static_cast<int>(floor_n)-1;

    this->setLayout(&_but_box);

    for (int i=min_floor; i<=max_floor; i++)
    {
        Button *new_but = new Button(i, this);

        QWidget::connect(new_but, SIGNAL(elevator_called(int)),
                         this, SLOT(get_new_call(int)));

        _but_arr.push_back(shared_ptr<Button>(new_but));
        _call_arr.push_back(false);
    }

    for (int i=max_floor; i>=min_floor; i--)
    {
        shared_ptr<Button> ptr = _but_arr[to_index(i)];
        _but_box.addWidget(ptr.get());
    }
}

Controller::~Controller() {}

void Controller::floor_visited(int floor, Direction dir)
{
    size_t arr_i = to_index(floor);
    _call_arr[arr_i] = false;

    int new_floor = find_request(floor, dir);
    if (new_floor <= max_floor)
    {
        std::cout << "(*)\t Request " << new_floor << " floor" << endl;
        emit request_visit(new_floor);
    }
    else
        _status = WAITING;
}

void Controller::get_new_call(int floor)
{
    _status = PROCESSING;

    size_t arr_i = to_index(floor);
    if (!_call_arr[arr_i])
    {
        std::cout << "(*)\t Request " << floor << " floor" << endl;
        _call_arr[arr_i] = true;
        emit request_visit(floor);
    }
}

size_t Controller::to_index(int floor)
{
    return static_cast<size_t>(floor-min_floor);
}

int Controller::find_request(int floor, Direction dir)
{
    if (!dir) dir = UP;

    for (int i=floor; i>=min_floor && i <= max_floor; i+=dir)
    {
        if (_call_arr[to_index(i)])
            return i;
    }

    for (int i=floor; i>=min_floor && i <= max_floor; i-=dir)
    {
        if (_call_arr[to_index(i)])
            return i;
    }

    return max_floor+1;
}
