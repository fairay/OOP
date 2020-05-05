#ifndef BASELIST_H
#define BASELIST_H

#include <stdio.h>
#include <memory>

using Size_sptr = std::shared_ptr<size_t>;
using Size_wptr = std::weak_ptr<size_t>;

class BaseList
{
protected:
    Size_sptr len;

public:
    BaseList();
    virtual ~BaseList();

    size_t get_len();
    bool is_empty();
    operator bool();
};

BaseList::BaseList()
{
    len = Size_sptr(new size_t(0));
}

BaseList::~BaseList() = default;

size_t BaseList::get_len()
{
    return *len;
}

bool BaseList::is_empty()
{
    return *len == 0;
}

BaseList::operator bool()
{
    return is_empty();
}

#endif // BASELIST_H
