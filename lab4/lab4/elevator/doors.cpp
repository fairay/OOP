#include "doors.h"

Doors::Doors(int move_delay, int open_delay):
    _status(CLOSE)
{
    _opening_t.setInterval(move_delay*1000);
    _open_t.setInterval(open_delay*1000);
    _closing_t.setInterval(move_delay*1000);

    QWidget::connect(&_opening_t, SIGNAL(timeout()),
                     this, SLOT(opening_over()));
    QWidget::connect(&_open_t, SIGNAL(timeout()),
                     this, SLOT(open_over()));
    QWidget::connect(&_closing_t, SIGNAL(timeout()),
                     this, SLOT(closing_over()));
}

Doors::~Doors() {}

bool Doors::is_open()
{
    return _status == OPEN;
}
bool Doors::is_close()
{
    return _status == CLOSE;
}


void Doors::open()
{
    if (_status != CLOSE) return;
    _status = OPENING;
    cout << "|<->|\t Opening doors" << endl;
    _opening_t.start();
}

void Doors::opening_over()
{
    if (_status != OPENING) return;
    _status = OPEN;
    cout << "|<->|\t Doors are opened" << endl;
    _open_t.start();
    emit opened();
}

void Doors::open_over()
{
    if (_status != OPEN) return;
    _status = CLOSIG;
    cout << "|<->|\t Closing doors" << endl;
    _closing_t.start();
}

void Doors::closing_over()
{
    if (_status != CLOSIG) return;
    _status = CLOSE;
    cout << "|<->|\t Doors are closed" << endl;
    emit closed();
}
