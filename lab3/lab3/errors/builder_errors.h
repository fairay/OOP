#ifndef BUILDER_ERRORS_H
#define BUILDER_ERRORS_H

#include "base_error.h"

namespace err
{
class BuilderError: public SceneError
{
public:
    BuilderError(const string file_, long line_n_);
    virtual ~BuilderError();
};



class FileOpenFail: public BuilderError
{
public:
    FileOpenFail(const string file_, long line_n_, const string name_);
    virtual ~FileOpenFail();
};

class FileNotOpen: public BuilderError
{
public:
    FileNotOpen(const string file_, long line_n_);
    virtual ~FileNotOpen();
};

class NodeOutOfRange: public BuilderError
{
public:
    NodeOutOfRange(const string file_, long line_n_, size_t i);
    virtual ~NodeOutOfRange();
};

class WrongNodeCount: public BuilderError
{
public:
    WrongNodeCount(const string file_, long line_n_);
    virtual ~WrongNodeCount();
};

class WrongEdgeCount: public BuilderError
{
public:
    WrongEdgeCount(const string file_, long line_n_);
    virtual ~WrongEdgeCount();
};

} // err

#endif // BUILDER_ERRORS_H
