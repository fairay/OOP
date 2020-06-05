#include "cabine.h"

Cabine::Cabine(int init_floor, int move_delay): _status(REQUEST_WAIT),
    cur_floor(init_floor), dest_floor(init_floor), move_dir(STAY)
{
    move_timer.setInterval(move_delay*1000);

    QWidget::connect(this, SIGNAL(dest_get()),
                     &_doors, SLOT(open()));
    QWidget::connect(&_doors, SIGNAL(closed()),
                     this, SLOT(doors_closed()));
    QWidget::connect(&move_timer, SIGNAL(timeout()),
                     this, SLOT(move()));
}

Cabine::~Cabine() {}

void Cabine::get_signal(int floor)
{
    if (_status == MOVE)
    {
        if (_is_new_dest(floor))
        {
            dest_floor = floor;
            cout << "/_\\\t Current destanation updated to " << floor << endl;
        }
    }
    else if (_status == REQUEST_WAIT)
    {
        if (cur_floor == floor)
        {
            cout << "/_\\\t Get request for current floor" << endl;
            cout << "/_\\\t Waiting for new request" << endl;
            emit dest_get();
            emit dest_get(cur_floor, move_dir);
        }
        else
        {
            cout << "/_\\\t Get request for another floor" << endl;
            cout << "/_\\\t Waiting for the doors to close" << endl;
            _status = CLOSIG_WAIT;
            dest_floor = floor;
            doors_closed();
        }
    }
}

void Cabine::doors_closed()
{
    if (!_doors.is_close() || _status != CLOSIG_WAIT) return;

    cout << "/_\\\t Doors are closed, starting move" <<endl;
    _status = STARTING;
    started();
}

void Cabine::stoped()
{
    if (_status != STOPING) return;

    Direction old_dir = move_dir;
    move_dir = STAY;
    emit dest_get();

    cout << "/_\\\t Waiting for new request" << endl;
    _status = REQUEST_WAIT;
    emit dest_get(dest_floor, old_dir);
}

void Cabine::started()
{
    if (_status != STARTING) return;

    if (cur_floor == dest_floor)
    {
        _status = STOPING;
        cout << "/_\\\t Cansel moving" << endl;
        stoped();
    }
    else
    {
        _status = MOVE;
        move_timer.start();
        cout << "/_\\\t Moving begins" << endl;
        if (cur_floor > dest_floor) move_dir = DOWN;
        else move_dir = UP;
    }
}

void Cabine::move()
{
    if (_status != MOVE) return;

    cur_floor += move_dir;
    cout << "/_\\\t Reached " << cur_floor << " floor" << endl;
    if (cur_floor == dest_floor)
    {
        _status = STOPING;
        cout << "/_\\\t Moving stoped" << endl;
        stoped();
    }
    else
        move_timer.start();
}


bool Cabine::_is_new_dest(int floor)
{
    if (cur_floor < floor && floor < dest_floor && move_dir == UP)
        return true;
    else if (dest_floor < floor && floor < cur_floor && move_dir == DOWN)
        return true;
    else
        return false;
}
