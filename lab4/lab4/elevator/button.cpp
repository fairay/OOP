#include "button.h"

Button::Button(int floor, QWidget *parent):
    QPushButton(parent), _status(RELEASED), _floor(floor)
{
    QString name("Этаж ");
    name.append(floor);
    this->setText(name);

    QWidget::connect(this, SIGNAL(pressed()),
                     this, SLOT(button_pressed()));

    QWidget::connect(this, SIGNAL(released()),
                     this, SLOT(button_released()));
}

Button::~Button() {}

void Button::button_pressed()
{
    if (_status == PRESSED) return;
    _status = PRESSED;
    emit elevator_called(_floor);
}

void Button::button_released()
{
    if (_status == RELEASED) return;
    _status = RELEASED;
}
