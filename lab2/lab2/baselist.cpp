#include "baselist.h"

BaseList::BaseList(): len(0) {}

BaseList::~BaseList() {}


size_t BaseList::get_len() const
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

