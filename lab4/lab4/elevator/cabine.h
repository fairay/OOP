#ifndef CABINE_H
#define CABINE_H

#include <QObject>
#include <QTimer>
#include "doors.h"

enum Direction { DOWN=-1, STAY=0, UP=1 };

class Cabine: public QObject
{
    Q_OBJECT
    enum CabineStatus
    {
        STARTING,
        MOVE,
        STOPING,
        REQUEST_WAIT,
        CLOSING_WAIT
    };

public:
    Cabine(int init_floor, int move_delay=2);
    virtual ~Cabine();

signals:
    void dest_get(int floor, Direction dir);
    void open_doors();

    void _request_sig();
    void _stoped_sig();
    void _started_sig();
    void _move_sig();

public slots:
    void request_waiting(int floor=0);
    void doors_waiting(int floor);

private slots:
    void stoped();
    void started();
    void move();

private:
    CabineStatus _status;
    int _cur_floor;
    int _dest_floor;
    Direction _move_dir;

    Doors _doors;

    QTimer _move_t;

    bool _is_new_dest(int floor);
};

#endif // CABINE_H
