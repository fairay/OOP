#ifndef BASE_ARRAY_H
#define BASE_ARRAY_H

#include <memory>

using namespace std;
class BaseArray
{
public:
    BaseArray(size_t sz = 0);
    BaseArray(const BaseArray& other);
    virtual ~BaseArray() = 0;

    size_t get_size() const;
    operator bool() const;

protected:
    shared_ptr<size_t> _count;
};


#endif // BASE_ARRAY_H
