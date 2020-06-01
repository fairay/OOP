#include "mainwindow.h"
#include <QApplication>
#include "array/array.h"

class Tea
{
public:
    Tea(): num(0) {}
    Tea(int i);
    void call() {cout << "My name is " << num << endl;}
    void set_num(int n) {num = n;}
private:
    int num;
};

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

        Array<Tea> att(3);
        att[2].set_num(4);
        Iterator<Tea> beg = att.begin();
        for (; bool(beg); beg++)
            beg->call();
    }
    catch (err::ArrayError &error) {
        cout << error.what() << endl;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
