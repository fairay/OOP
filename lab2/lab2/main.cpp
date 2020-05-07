#include <iostream>
#include "list.h"

using namespace std;

bool cmp_test(const int &a1, const int &a2)
{
    return (a1 % 10) > (a2 % 10);
}

void test_attachment()
{
    cout<<endl<< "= and += tests" << endl;

    int arr[3] = {1, 2, 3};
    List<float> a{1, 2, 3, 9};
    List<float> b{10, 23, 31};
    List<double> c{};
    List<int> d(arr, 3);

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
    d.append({-1, -10});
    cout << "d: " << d << endl;
}
void test_get()
{
    cout<<endl<< "get, [] and get_arr tests" << endl;

    List<int> a{1, 2, 3, 102, 9};
    List<float> b{1.241f, 2.1f, 2};

    cout << a.get_i(1) << endl;
    cout << a.get_i(-1) << endl;
    cout << a[2] << endl;
    cout << a[-2] << endl;

    float *b_arr = b.get_arr();
    for (int i=0; i<3; i++)
        cout << b_arr[i] << " ";
    cout << endl;
    delete []b_arr;
}
void test_set()
{
    cout<<endl<< "set, set_i tests" << endl;

    List<int> a{0, 1, 2, 3, 4, 5};
    cout << a << endl;

    a.set_i(10, 1);
    a.set_i(-20, -2);
    cout << a << endl;


}
void test_insert_pop()
{
    cout<<endl<< "insert and pop tests" << endl;
    List<float> a{1, 1.2f, 3};
    List<float> b{0, 0, 0};
    cout << a << endl;

    a.insert(3, 2);
    cout << a << endl;

    a.insert(0, b);
    cout << a << endl;

    a.insert(2, {-1, -1});
    cout << a << endl;

    float arr[3] = {1, 2, 3};
    a.insert(5, arr, 3);
    cout << a << endl;

    a.popfront();
    a.popend();
    a.pop_i(-2);
    a.pop_i(static_cast<size_t>(2));
    cout << a << endl;
}
void test_cmp()
{
    cout<<endl<< "== != tests" << endl;
}
void test_order()
{
    cout<<endl<< "swap, revese, shuffle sort tests" << endl;

    List<int> a{1, 2, 3, 4, 5, 6, 7, 8};
    cout << a << endl;

    a.shuffle();
    cout << a << endl;

    a.swap(0, 4);
    cout << a << endl;

    a.reverse();
    cout << a << endl;

    a.shuffle();
    a.sort();
    cout << a << endl;

    a.shuffle();
    a.sort(true);
    cout << a << endl;

    a.shuffle();
    a.sort_cmp(cmp_test);
    cout << a << endl;
}
void test_find()
{
    cout<<endl<< "find and below tests" << endl;

    List<int> a{1, 2, 3, 4, 5, 6, 7, 8};
    cout << a << endl;

    cout << "9 is on " << a.find(9)<< " position"<< endl;
    cout << "9 is " << (a.is_belongs(9) ? "belongs" : "not belongs") << endl;

    cout << "1 is on " << a.find(1)<< " position"<< endl;
    cout << "1 is " << (a.is_belongs(1) ? "belongs" : "not belongs") << endl;
}
void test_addition()
{
    cout<<endl<< "addition tests" << endl;

    const List<float> a{1, 2, 3, 9};
    List<float> b{10, 23, 31};
    List<float> c = List<float>();

    cout << a + b << endl;
    cout << b + a << endl;

    c = b+b;
    c += a;
    c += {1, 1.2f};
    c.append({10, 20});
    c.append(1.2f);
    cout << c << endl;
}


int main()
{
    try
    {
        int arr[3] = {1, 2, 3};
        const List<float> a{1, 2, 3, 9};
        List<float> b{10, 23, 31};
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

        test_get();
        test_set();
        test_insert_pop();
        test_attachment();
        test_order();
        test_find();
        test_addition();
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
