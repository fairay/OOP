#include <ctime>
#include "errors.h"

using namespace err;

/// err::List
ListError::ListError(const string file_, long line_n_): file(file_)
{
    line_n = to_string(line_n_);
    err_time = cur_time();
}
ListError::~ListError()
{
    delete []err_msg;
}

// private
string ListError::cur_time()
{
    const time_t cur_t = time(nullptr);
    string str = asctime(localtime(&cur_t));
    return str;
}
string ListError::base_msg()
{
    string msg = "List error! \n"
                 "File " + file + ":" + line_n + "\t" + err_time;
    return msg;
}
string ListError::add_msg()
{
    string msg = "";
    if (type == "")     return msg;
    msg += "Type: " + type;

    if (add_info == "") return msg;
    msg += " : " + add_info;
    return msg;
}

// protected
void ListError::fill_msg()
{
    string msg = base_msg() + "\n" + add_msg();
    err_msg = new char[msg.length()+1];
    strcpy(err_msg, msg.c_str());
}

// public
const char* ListError::what() const noexcept
{
    return err_msg;
}


/// err::Index
Index::Index(const string file_, long line_n_,
             int index): ListError(file_, line_n_)
{
    type = "WrongIndex";
    add_info = "requesting index = " + to_string(index);
    fill_msg();
}
Index::Index(const string file_, long line_n_,
             size_t index): ListError(file_, line_n_)
{
    type = "WrongIndex";
    add_info = "requesting index = " + to_string(index);
    fill_msg();
}
Index::~Index() = default;

/// err::NoneExist
NullNode::NullNode(const string file_, long line_n_): ListError(file_, line_n_)
{
    type = "NoneExistElement";
    add_info = "requied element allready deleted or null";
    fill_msg();
}
NullNode::~NullNode() = default;

/// err::WrongSize
WrongSize::WrongSize(const string file_, long line_n_,
                     int size): ListError(file_, line_n_)
{
    type = "WrongSize";
    add_info = "size of list " + to_string(size) + " is invalid for this operation";
    fill_msg();
}
WrongSize::~WrongSize() = default;

/// err::EmptyList
EmptyList::EmptyList(const string file_, long line_n_): ListError(file_, line_n_)
{
    type = "EmptyList";
    add_info = "empty list don't support such operation";
    fill_msg();
}
EmptyList::~EmptyList() = default;

/// err::AllocFailed
AllocFailed::AllocFailed(const string file_, long line_n_): ListError(file_, line_n_)
{
    type = "AllocFailed";
    add_info = "memory allocation of node was failed";
    fill_msg();
}
AllocFailed::~AllocFailed() = default;

/// err::WrongSize
ListCorrupted::ListCorrupted(const string file_, long line_n_,
                             const string reason): ListError(file_, line_n_)
{
    type = "ListCorrupted";
    add_info = "comment - " + reason;
    fill_msg();
}
ListCorrupted::~ListCorrupted() = default;
