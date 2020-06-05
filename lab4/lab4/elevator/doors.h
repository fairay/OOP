#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QTimer>
#include <QWidget>
#include <iostream>

using namespace std;
class Doors : public QObject
{
    Q_OBJECT
    enum DoorsStatus
    {
        CLOSE,
        OPENING,
        OPEN,
        CLOSIG
    };

public:
    Doors(int move_delay=1, int open_delay=1);
    virtual ~Doors();
    bool is_open();
    bool is_close();

signals:
    void opened();
    void closed();

public slots:
    void open();

private slots:
    void opening_over();
    void open_over();
    void closing_over();

private:
    DoorsStatus _status;
    QTimer opening_timer;
    QTimer open_timer;
    QTimer closing_timer;
};
#endif // DOORS_H
