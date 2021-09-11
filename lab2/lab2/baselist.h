#ifndef BASELIST_H
#define BASELIST_H

#include <stdio.h>
#include <memory>
#include "errors.h"

class BaseList
{
public:
    BaseList();
    virtual ~BaseList() = 0;

    size_t get_len() const;
    bool is_empty() const;
    operator bool() const;
protected:
    size_t len = 0;
};


#endif // BASELIST_H
