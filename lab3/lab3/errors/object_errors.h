#ifndef OBJECT_ERRORS_H
#define OBJECT_ERRORS_H

#include "base_error.h"

namespace err
{
class ObjectError: public SceneError
{
public:
    ObjectError(const string file_, long line_n_);
    virtual ~ObjectError();
};


class NotDrawable: public ObjectError
{
public:
    NotDrawable(const string file_, long line_n_);
    virtual ~NotDrawable();
};
class NotTransable: public ObjectError
{
public:
    NotTransable(const string file_, long line_n_);
    virtual ~NotTransable();
};
class UndefindeVisiter: public ObjectError
{
public:
    UndefindeVisiter(const string file_, long line_n_);
    virtual ~UndefindeVisiter();
};
class UndefindeClone: public ObjectError
{
public:
    UndefindeClone(const string file_, long line_n_);
    virtual ~UndefindeClone();
};

} // namespace err

#endif // OBJECT_ERRORS_H
