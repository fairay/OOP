#ifndef ARRAY_ERRORS_H
#define ARRAY_ERRORS_H

#include "base_error.h"

namespace err
{

class ArrayError: public SceneError
{
public:
    ArrayError(const string file_, long line_n_);
    virtual ~ArrayError();
};


class CountPtrExpired: public ArrayError
{
public:
    CountPtrExpired(const string file_, long line_n_);
    virtual ~CountPtrExpired();
};
class ArrayPtrExpired: public ArrayError
{
public:
    ArrayPtrExpired(const string file_, long line_n_);
    virtual ~ArrayPtrExpired();
};
class OutOfRange: public ArrayError
{
public:
    OutOfRange(const string file_, long line_n_, size_t index);
    virtual ~OutOfRange();
};

} // namespace err

#endif // ARRAY_ERRORS_H
