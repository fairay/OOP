#include "cabine.h"

Cabine::Cabine(int init_floor, int move_delay): _status(REQUEST_WAIT),
    _cur_floor(init_floor), _dest_floor(init_floor), _move_dir(STAY)
{
    _move_t.setInterval(move_delay*1000);

    QWidget::connect(this, SIGNAL(open_doors()),
                     &_doors, SLOT(open()));
    QWidget::connect(&_doors, SIGNAL(closed()),
                     this, SLOT(started()));
    QWidget::connect(&_move_t, SIGNAL(timeout()),
                     this, SLOT(move()));
}

Cabine::~Cabine() {}

void Cabine::request_waiting(int floor)
{
    if (_status == REQUEST_WAIT)
    {
        if (floor == _cur_floor)
        {
            cout << "/_\\\t Get request for current floor" << endl;
            cout << "/_\\\t Waiting for new request" << endl;
            emit open_doors();
            emit dest_get(_cur_floor, _move_dir);
        }
    }
    else if (_status == STOPING)
    {
        cout << "/_\\\t Waiting for new request" << endl;
        _status = REQUEST_WAIT;
    }
}

void Cabine::doors_waiting(int floor)
{
    if (_status != REQUEST_WAIT || floor == _cur_floor) return;
    cout << "/_\\\t Get request for another floor" << endl;
    cout << "/_\\\t Waiting for the doors to close" << endl;
    _status = CLOSING_WAIT;
    _dest_floor = floor;

    if (_doors.is_close())
        started();
}

void Cabine::stoped()
{
    if (_status != MOVE) return;
    cout << "/_\\\t Moving stoped" << endl;
    _status = STOPING;

    Direction old_dir = _move_dir;
    _move_dir = STAY;

    emit open_doors();
    request_waiting();
    emit dest_get(_dest_floor, old_dir);
}

void Cabine::started()
{
    if (_status != CLOSING_WAIT || !_doors.is_close()) return;
    cout << "/_\\\t Doors are closed, starting move" <<endl;
    _status = STARTING;

    if (_cur_floor > _dest_floor) _move_dir = DOWN;
    else _move_dir = UP;
    move();
}

void Cabine::move()
{
    if (_status == MOVE)
    {
        _cur_floor += _move_dir;
        cout << "/_\\\t Reached " << _cur_floor << " floor" << endl;
        if (_cur_floor == _dest_floor)
            stoped();
        else
            _move_t.start();
    }
    else if (_status == STARTING)
    {
        _status = MOVE;
        _move_t.start();
    }
}


bool Cabine::_is_new_dest(int floor)
{
    if (_cur_floor < floor && floor < _dest_floor && _move_dir == UP)
        return true;
    else if (_dest_floor < floor && floor < _cur_floor && _move_dir == DOWN)
        return true;
    else
        return false;
}
