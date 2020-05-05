#ifndef ERRORS_H
#define ERRORS_H

#include <string.h>
#include <exception>
#include <string>
#include <iostream>

using namespace std;
class ErrList: exception
{
protected:
    char* err_msg;
    void fill_msg()
    {
        string msg = base_msg() + "\n" + add_msg();
        err_msg = new char[msg.length()];
        strcpy(err_msg, msg.c_str());
    }
    string base_msg()
    {
        string msg = "List error! \n"
                     "File " + file + ":" + line_n + "\t time " + time;
        return msg;
    }
    string add_msg()
    {
        string msg = "";
        if (type == "")     return msg;
        msg += "Type: " + type;

        if (add_info == "") return msg;
        msg += " : " + add_info;
        return msg;
    }

    string file;
    string line_n;
    string time;

    string type = "";
    string add_info = "";
public:
    ErrList(const string file_, long line_n_, const string time_):
        file(file_), line_n(to_string(line_n_)), time(time_) {}
    virtual ~ErrList() override;
    virtual const char* what() const noexcept override;
};
ErrList::~ErrList()
{
    delete []err_msg;
}
const char* ErrList::what() const noexcept
{
    return err_msg;
}

class ErrIndex: public ErrList
{
public:
    ErrIndex(const string file_, long line_n_, const string time_, size_t index):
        ErrList(file_, line_n_, time_)
    {
        type = "Wrong index";
        add_info = "index = " + to_string(index);
        fill_msg();
    }
    virtual ~ErrIndex();
};
ErrIndex::~ErrIndex() {};

#endif // ERRORS_H
