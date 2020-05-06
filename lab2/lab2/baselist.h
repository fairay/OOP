#ifndef BASELIST_H
#define BASELIST_H

#include <stdio.h>
#include <memory>
#include "errors.h"

using Size_sptr = std::shared_ptr<size_t>;

class BaseList
{
protected:
    size_t len = 0;

public:
    BaseList();
    virtual ~BaseList();

    size_t get_len();
    bool is_empty() const;
    operator bool() const;
};

BaseList::BaseList(): len(0) {}

BaseList::~BaseList() = default;


size_t BaseList::get_len()
{
    return len;
}

bool BaseList::is_empty() const
{
    return len == 0;
}

BaseList::operator bool() const
{
    return is_empty();
}


#endif // BASELIST_H
