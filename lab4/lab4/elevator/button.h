#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <iostream>

class Button: public QPushButton
{
    Q_OBJECT
    enum ButtonStatus   { PRESSED, RELEASED };

public:
    Button(int floor, QWidget *parent=nullptr);
    virtual ~Button();

private slots:
    void button_pressed();
    void button_released();

signals:
    void elevator_called(int floor);

private:
    ButtonStatus _status;
    int _floor;
};

#endif // BUTTON_H
