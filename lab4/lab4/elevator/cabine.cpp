#include "cabine.h"

Cabine::Cabine(int init_floor, int move_delay): _status(REQUEST_WAIT),
    _cur_floor(init_floor), _dest_floor(init_floor), _move_dir(STAY)
{
    _move_t.setInterval(move_delay*1000);

    QWidget::connect(this, SIGNAL(dest_get()),
                     &_doors, SLOT(open()));
    QWidget::connect(&_doors, SIGNAL(closed()),
                     this, SLOT(doors_closed()));
    QWidget::connect(&_move_t, SIGNAL(timeout()),
                     this, SLOT(move()));
}

Cabine::~Cabine() {}

void Cabine::get_signal(int floor)
{
    if (_status == MOVE)
    {
        if (_is_new_dest(floor))
        {
            _dest_floor = floor;
            cout << "/_\\\t Current destanation updated to " << floor << endl;
        }
    }
    else if (_status == REQUEST_WAIT)
    {
        if (_cur_floor == floor)
        {
            cout << "/_\\\t Get request for current floor" << endl;
            cout << "/_\\\t Waiting for new request" << endl;
            emit dest_get();
            emit dest_get(_cur_floor, _move_dir);
        }
        else
        {
            cout << "/_\\\t Get request for another floor" << endl;
            cout << "/_\\\t Waiting for the doors to close" << endl;
            _status = CLOSING_WAIT;
            _dest_floor = floor;
            doors_closed();
        }
    }
}

void Cabine::doors_closed()
{
    if (!_doors.is_close() || _status != CLOSING_WAIT) return;

    cout << "/_\\\t Doors are closed, starting move" <<endl;
    _status = STARTING;
    started();
}

void Cabine::stoped()
{
    if (_status != STOPING) return;

    Direction old_dir = _move_dir;
    _move_dir = STAY;
    emit dest_get();

    cout << "/_\\\t Waiting for new request" << endl;
    _status = REQUEST_WAIT;
    emit dest_get(_dest_floor, old_dir);
}

void Cabine::started()
{
    if (_status != STARTING) return;

    if (_cur_floor == _dest_floor)
    {
        _status = STOPING;
        cout << "/_\\\t Cansel moving" << endl;
        stoped();
    }
    else
    {
        _status = MOVE;
        _move_t.start();
        cout << "/_\\\t Moving begins" << endl;
        if (_cur_floor > _dest_floor) _move_dir = DOWN;
        else _move_dir = UP;
    }
}

void Cabine::move()
{
    if (_status != MOVE) return;

    _cur_floor += _move_dir;
    cout << "/_\\\t Reached " << _cur_floor << " floor" << endl;
    if (_cur_floor == _dest_floor)
    {
        _status = STOPING;
        cout << "/_\\\t Moving stoped" << endl;
        stoped();
    }
    else
        _move_t.start();
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
