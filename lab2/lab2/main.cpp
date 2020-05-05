#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    try
    {
        List<float> a{1, 2, 3};
        List<float> b{10, 22, 31};
        List<double> c{101, 22, 31, 41.1};
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
