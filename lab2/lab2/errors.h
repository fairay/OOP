#ifndef ERRORS_H
#define ERRORS_H

#include <string.h>
#include <exception>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;
namespace err {

class List: exception
{
private:
    string file;
    string line_n;
    string err_time;

    string cur_time();
    string base_msg();
    string add_msg();
protected:
    char* err_msg;
    void fill_msg();
    string type = "";
    string add_info = "";
public:
    List(const string file_, long line_n_):
        file(file_), line_n(to_string(line_n_)) {err_time = cur_time();}
    virtual ~List() override;
    virtual const char* what() const noexcept override;
};



class Index: public List
{
public:
    Index(const string file_, long line_n_, size_t index):
        List(file_, line_n_)
    {
        type = "Wrong index";
        add_info = "index = " + to_string(index);
        fill_msg();
    }
    virtual ~Index();
};
}
#endif // ERRORS_H
