#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QVBoxLayout>
#include <memory>
#include "button.h"

using namespace std;

class Controller: public QWidget
{
    Q_OBJECT
    enum ControllerStatus { WAITING, PROCESSING };

public:
    Controller(size_t floor_n, QWidget *parent=nullptr);
    virtual ~Controller();

private:
    ControllerStatus _status;
    size_t _floor_n;

    list<shared_ptr<Button>> _but_arr;

    QVBoxLayout _but_box;
};

#endif // CONTROLLER_H
