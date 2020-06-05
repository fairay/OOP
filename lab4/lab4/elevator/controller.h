#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QVBoxLayout>
#include <memory>
#include "button.h"
#include "cabine.h"

using namespace std;

class Controller: public QWidget
{
    Q_OBJECT
    enum ControllerStatus { WAITING, PROCESSING };

public:
    Controller(size_t floor_n, QWidget *parent=nullptr);
    virtual ~Controller();

signals:
    void request_visit(int floor);

public slots:
    void floor_visited(int floor, Direction dir);

private slots:
    void get_new_call(int floor);

private:
    ControllerStatus _status;
    size_t _floor_n;
    int _low_floor, _up_floor;

    vector<shared_ptr<Button>> _but_arr;
    vector<bool> _call_arr;

    QVBoxLayout _but_box;

    int _find_request(int floor, Direction dir);
    size_t _to_index(int floor);
};

#endif // CONTROLLER_H
