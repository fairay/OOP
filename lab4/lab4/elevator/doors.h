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
    Doors(int move_delay=2, int open_delay=5);
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
    QTimer _opening_t;
    QTimer _open_t;
    QTimer _closing_t;
};
#endif // DOORS_H
