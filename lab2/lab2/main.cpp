#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    try
    {
        List<float> a{1, 2, 3};
        for (size_t i=0; i < 4; i++)
            cout << a[i] << endl;
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
