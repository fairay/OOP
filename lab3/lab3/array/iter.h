#ifndef ITERATOR_H
#define ITERATOR_H

#include "base_iter.h"

template<typename Type>
class Array;


template<typename Type>
class Iterator : public BaseIterator<Type>
{
    friend class Array<Type>;

public:
    Iterator(const Iterator &other) : BaseIterator<Type>(other){}

    const Type& get_value() const;
    const Type& operator*() const;
    Type& get_value();
    Type& operator*();

    const Type* get_ptr() const;
    const Type* operator->() const;
    Type* get_ptr();
    Type* operator->();

private:
    Iterator(const shared_ptr<Type[]>& arr, const shared_ptr<size_t>& count,
             size_t index = 0) : BaseIterator<Type>(arr, count, index) {}

    const Type& _get_value() const;
    const Type* _get_ptr() const;
    Type& _get_value();
    Type* _get_ptr();
};

#ifndef ITER_HPP
#include "iter.hpp"
#endif // ITER_HPP


#endif // ITERATOR_H
