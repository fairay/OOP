#include <iostream>
#include "list.h"

using namespace std;

class A
{
private:
    int val;
public:
    A(int val_) {val = val_;}

    // int& get_val() { cout << "Call def" <<endl; return val; }
    const int& get_val() const { cout << "Call const" <<endl; return val; }

    const int* get_ptr() const { cout << "Call const ptr" <<endl; return &val; }
};

int main()
{
    A a(3);
    const A b(4);
    int getter = a.get_val();
    const int const_getter = b.get_val();

    const int* ptr_get = a.get_ptr();
    try
    {
        List<float> a{1, 2, 3};
        List<float> b{10, 22, 31};
        List<double> c{101, 22, 31, 41.1};
        // List<double> c{};
        // List<double> d(c);

        for (size_t i=0; i < 3; i++)
            cout << a[i] << endl;

        for (auto val:b)
            cout << val << " ";
        cout << endl;

        cout << c << endl;
        c.print();
    }
    catch (err::List& err)
    {
        cout << err.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown error!" << endl;
    }

    return 0;
}
