#include "mainwindow.h"
#include <QApplication>
#include "array/array.h"

int main(int argc, char *argv[])
{
    try
    {
        Array<int> arr{1, 3, 5};
        for (auto val : arr)
            cout << val << " ";

        cout << endl;
        arr.append(10);
        cout << "Exit" << endl;
        arr.append(2);
        for (auto val : arr)
            cout << val << " ";
        cout << "END!" << endl;

        arr.clear();
        arr.append(3);
        for (auto val : arr)
            cout << val << " ";
        cout << endl << "END!" << arr.get_size() << endl;
    }
    catch (err::ArrayError &error) {
        cout << error.what() << endl;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
