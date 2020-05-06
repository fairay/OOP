#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    try
    {
        List<float> a{1, 2, 3, 9};
        List<float> b{10, 23, 31};
        // List<double> c{101, 22, 31, 41.1};
        List<double> c{};
        // List<double> d(c);

        cout << a[0] << " = " << a[-4] << endl;
        for (size_t i=0; i < 4; i++)
            cout << a[i] << endl;

        for (auto val:b)
            cout << val << " ";
        cout << endl;

        cout << c << endl;
        c.print();

        cout << endl << b.pop_i(-1) << endl;
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
