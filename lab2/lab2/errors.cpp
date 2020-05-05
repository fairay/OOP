#include "errors.h"

using namespace err;
#pragma region Base Methods
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
#pragma endregion

#pragma region Index Methods
Index::~Index() = default;
#pragma endregion
