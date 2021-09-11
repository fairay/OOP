#ifndef CONST_ITER_H
#define CONST_ITER_H

#include "base_iter.h"

template<typename Type>
class Array;

template<typename Type>
class ConstIterator : public BaseIterator<Type>
{
    friend class Array<Type>;

public:
    ConstIterator(const ConstIterator &other) : BaseIterator<Type>(other){}

    const Type& get_value() const;
    const Type& operator*() const;

    const Type* get_ptr() const;
    const Type* operator->() const;

private:
    ConstIterator(const shared_ptr<Type[]>& arr, const shared_ptr<size_t>& count,
             size_t index = 0) : BaseIterator<Type>(arr, count, index) {}
    const Type& _get_value() const;
    const Type* _get_ptr() const;
};

#ifndef CONST_ITER_HPP
#include "const_iter.hpp"
#endif // CONST_ITER_HPP

#endif // CONST_ITER_H
