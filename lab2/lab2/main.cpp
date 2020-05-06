#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    try
    {
        int arr[3] = {1, 2, 3};
        List<float> a{1, 2, 3, 9};
        List<float> b{10, 23, 31};
        // List<double> c{101, 22, 31, 41.1};
        List<double> c{};
        List<int> d(arr, 3);

        cout << a[0] << " = " << a[-4] << endl;
        for (size_t i=0; i < 4; i++)
            cout << a[i] << endl;

        for (auto val:b)
            cout << val << " ";
        cout << endl;

        cout << c << endl;
        c.print();

        cout << endl << b.pop_i(-1) << endl;
        cout << d << endl;


        cout<<endl<< "= and += tests" << endl;
        cout << "Previos d" << d << endl;
        d = 3;
        d += 10;
        cout << d << endl;

        a = b;
        a += b;
        cout << "b: "<< b << endl;
        cout << "copy b: " << a << endl;

        d = {2, 3, 10, 123};
        d += {51, 12};
        cout << "d: " << d << endl;
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
