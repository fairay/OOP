#ifndef BASELIST_H
#define BASELIST_H

#include <stdio.h>
#include <memory>
#include "errors.h"

using Size_sptr = std::shared_ptr<size_t>;

class BaseList
{
protected:
    Size_sptr len;
    void inc_len();
    void dec_len();

public:
    BaseList();
    virtual ~BaseList();

    size_t get_len();
    bool is_empty();
    bool is_empty() const;

    operator bool();
    operator bool() const;
};

BaseList::BaseList()
{
    len = Size_sptr(new size_t(0));
}

BaseList::~BaseList() = default;

void BaseList::inc_len()
{
    (*len)++;
}

void BaseList::dec_len()
{
    if (is_empty())
        throw err::WrongSize(__FILE__, __LINE__+1,
                             static_cast<int>(*len-1));
    (*len)--;
}


size_t BaseList::get_len()
{
    return *len;
}

bool BaseList::is_empty()
{
    return *len == 0;
}
bool BaseList::is_empty() const
{
    return *len == 0;
}

BaseList::operator bool()
{
    return is_empty();
}
BaseList::operator bool() const
{
    return is_empty();
}


#endif // BASELIST_H
