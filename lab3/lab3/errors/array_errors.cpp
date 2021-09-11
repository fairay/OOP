#include "array_errors.h"

using namespace err;

ArrayError::ArrayError(const string file_, long line_n_): SceneError(file_, line_n_)
{
    type = "ArrayError: ";
}
ArrayError::~ArrayError() = default;



CountPtrExpired::CountPtrExpired(const string file_, long line_n_): ArrayError(file_, line_n_)
{
    type += "CountPtrExpired";
    add_info = "requied element allready deleted or null";
    fill_msg();
}
CountPtrExpired::~CountPtrExpired() = default;

ArrayPtrExpired::ArrayPtrExpired(const string file_, long line_n_): ArrayError(file_, line_n_)
{
    type += "ArrayPtrExpired";
    add_info = "requied element allready deleted or null";
    fill_msg();
}
ArrayPtrExpired::~ArrayPtrExpired() = default;

AllocFailed::AllocFailed(const string file_, long line_n_): ArrayError(file_, line_n_)
{
    type += "AllocFailed";
    add_info = "memory allocation of array was failed";
    fill_msg();
}
AllocFailed::~AllocFailed() = default;

OutOfRange::OutOfRange(const string file_, long line_n_, size_t index): ArrayError(file_, line_n_)
{
    type = "OutOfRange";
    add_info = "requesting index = " + to_string(index) + " is out of array range";
    fill_msg();
}
OutOfRange::~OutOfRange() = default;
