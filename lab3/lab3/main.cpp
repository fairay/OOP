#include "mainwindow.h"
#include <QApplication>
#include "array/array.h"

int main(int argc, char *argv[])
{
    cout << "Begin" << endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
