#include <ctime>
#include "errors.h"

using namespace err;

/// err::List
List::List(const string file_, long line_n_): file(file_)
{
    line_n = to_string(line_n_);
    err_time = cur_time();
}
List::~List()
{
    delete []err_msg;
}

// private
string List::cur_time()
{
    const time_t cur_t = time(nullptr);
    string str = asctime(localtime(&cur_t));
    return str;
}
string List::base_msg()
{
    string msg = "List error! \n"
                 "File " + file + ":" + line_n + "\t" + err_time;
    return msg;
}
string List::add_msg()
{
    string msg = "";
    if (type == "")     return msg;
    msg += "Type: " + type;

    if (add_info == "") return msg;
    msg += " : " + add_info;
    return msg;
}

// protected
void List::fill_msg()
{
    string msg = base_msg() + "\n" + add_msg();
    err_msg = new char[msg.length()];
    strcpy(err_msg, msg.c_str());
}

// public
const char* List::what() const noexcept
{
    return err_msg;
}


/// err::Index
Index::Index(const string file_, long line_n_,
             size_t index): List(file_, line_n_)
{
    type = "WrongIndex";
    add_info = "requesting index = " + to_string(index);
    fill_msg();
}
Index::~Index() = default;

/// err::NoneExist
NullNode::NullNode(const string file_, long line_n_): List(file_, line_n_)
{
    type = "NoneExistElement";
    add_info = "requied element allready deleted or null";
    fill_msg();
}
NullNode::~NullNode() = default;

/// err::WrongSize
WrongSize::WrongSize(const string file_, long line_n_,
                     int size): List(file_, line_n_)
{
    type = "WrongSize";
    add_info = "size of list changed to " + to_string(size) + " value";
    fill_msg();
}
WrongSize::~WrongSize() = default;
