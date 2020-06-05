#include "doors.h"

Doors::Doors(int move_delay, int open_delay):
    _status(CLOSE)
{
    opening_timer.setInterval(move_delay*1000);
    open_timer.setInterval(open_delay*1000);
    closing_timer.setInterval(move_delay*1000);

    QWidget::connect(&opening_timer, SIGNAL(timeout()),
                     this, SLOT(opening_over()));
    QWidget::connect(&open_timer, SIGNAL(timeout()),
                     this, SLOT(open_over()));
    QWidget::connect(&closing_timer, SIGNAL(timeout()),
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
    opening_timer.start();
}

void Doors::opening_over()
{
    if (_status != OPENING) return;
    _status = OPEN;
    cout << "|<->|\t Doors are opened" << endl;
    open_timer.start();
    emit opened();
}

void Doors::open_over()
{
    if (_status != OPEN) return;
    _status = CLOSIG;
    cout << "|<->|\t Closing doors" << endl;
    closing_timer.start();
}

void Doors::closing_over()
{
    if (_status != CLOSIG) return;
    _status = CLOSE;
    cout << "|<->|\t Doors are closed" << endl;
    emit closed();
}
