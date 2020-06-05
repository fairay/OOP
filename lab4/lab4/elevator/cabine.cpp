#include "cabine.h"

Cabine::Cabine(int move_delay)
{
    _status = REQUEST_WAIT;
    move_timer.setInterval(move_delay*1000);

    QWidget::connect(this, SIGNAL(dest_get()),
                     &_doors, SLOT(open()));
    QWidget::connect(&_doors, SIGNAL(closed()),
                     this, SLOT(doors_closed()));
}

Cabine::~Cabine() {}

void Cabine::get_signal(int floor)
{
    if (_status == MOVE)
    {
        if (cur_floor < floor < dest_floor && move_dir == UP)
        {
            dest_floor = floor;
            cout << "Current destanation updated to " << floor << endl;
        }
        else if (dest_floor < floor < cur_floor && move_dir == DOWN)
        {
            dest_floor = floor;
            cout << "Current destanation updated to " << floor << endl;
        }
    }
    else if (_status == REQUEST_WAIT)
    {
        if (cur_floor == floor)
        {
            cout << "Get request for current floor" << endl;
            cout << "Waiting for new request" << endl;
            emit dest_get(cur_floor, move_dir);
            emit dest_get();
        }
        else
        {
            cout << "Get request for another floor" << endl;
            cout << "Waiting for the doors to close" << endl;
            _status = CLOSIG_WAIT;
            dest_floor = floor;
            doors_closed();
        }
    }
}

void Cabine::doors_closed()
{
    if (!_doors.is_close() || _status != CLOSIG_WAIT) return;

    cout << "Doors are closed, starting move" <<endl;
    _status = STARTING;
    started();
}

void Cabine::stoped()
{
    if (_status != STOPING) return;

    Direction old_dir = move_dir;
    move_dir = STAY;

    cout << "Waiting for new request" << endl;
    _status = REQUEST_WAIT;
    emit dest_get(dest_floor, old_dir);
    emit dest_get();
}

void Cabine::started()
{
    if (_status != STARTING) return;

    if (cur_floor == dest_floor)
    {
        _status = STOPING;
        cout << "Cansel moving" << endl;
        stoped();
    }
    else
    {
        _status = MOVE;
        move_timer.start();
        cout << "Move begins" << endl;
        if (cur_floor > dest_floor) move_dir = DOWN;
        else move_dir = UP;
    }
}

void Cabine::move()
{
    if (_status != MOVE) return;

    cur_floor += move_dir;
    cout << "Reached " << cur_floor << " floor" << endl;
    if (cur_floor == dest_floor)
    {
        _status = STOPING;
        cout << "Stoping move" << endl;
        stoped();
    }
    else
        move_timer.start();
}
