#ifndef DRAWER_ERRORS_H
#define DRAWER_ERRORS_H

#include "base_error.h"

namespace err
{

class DrawerError: public SceneError
{
public:
    DrawerError(const string file_, long line_n_);
    virtual ~DrawerError();
};

class SceneExpired: public DrawerError
{
public:
    SceneExpired(const string file_, long line_n_);
    virtual ~SceneExpired();
};

} // err


#endif // DRAWER_ERRORS_H
