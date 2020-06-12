#include "builder_errors.h"

using namespace err;
BuilderError::BuilderError(const string file_, long line_n_): SceneError(file_, line_n_)
{
    type = "BuilderError: ";
}
BuilderError::~BuilderError() = default;



FileOpenFail::FileOpenFail(const string file_, long line_n_, const string name_):
    BuilderError(file_, line_n_)
{
    type += "FileOpenFail";
    add_info = "failed to open file: " + name_;
    fill_msg();
}
FileOpenFail::~FileOpenFail() = default;

FileNotOpen::FileNotOpen(const string file_, long line_n_):
    BuilderError(file_, line_n_)
{
    type += "FileNotOpen";
    add_info = "requesting scan operation while file isn't open";
    fill_msg();
}
FileNotOpen::~FileNotOpen() = default;

NodeOutOfRange::NodeOutOfRange(const string file_, long line_n_, size_t i):
    BuilderError(file_, line_n_)
{
    type += "NodeOutOfRange";
    add_info = "index of node if out of range " + to_string(i);
    fill_msg();
}
NodeOutOfRange::~NodeOutOfRange() = default;

WrongNodeCount::WrongNodeCount(const string file_, long line_n_):
    BuilderError(file_, line_n_)
{
    type += "WrongNodeCount";
    add_info = "scaned wrong count of nodes";
    fill_msg();
}
WrongNodeCount::~WrongNodeCount() = default;

WrongEdgeCount::WrongEdgeCount(const string file_, long line_n_):
    BuilderError(file_, line_n_)
{
    type += "WrongEdgeCount";
    add_info = "scaned wrong count of edges";
    fill_msg();
}
WrongEdgeCount::~WrongEdgeCount() = default;
