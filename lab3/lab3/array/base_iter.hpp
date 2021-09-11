#ifndef BASE_ITER_HPP
#define BASE_ITER_HPP

#include "base_iter.h"

template <typename Type>
BaseIterator<Type>::BaseIterator(const BaseIterator<Type> &other)
{
    _arr = other._arr;
    _count = other._count;
    _index = other._index;
}


template<typename Type>
BaseIterator<Type>& BaseIterator<Type>::next()
{
    return _next();
}
template<typename Type>
BaseIterator<Type>& BaseIterator<Type>::operator++()
{
    return _next();
}
template<typename Type>
BaseIterator<Type> BaseIterator<Type>::operator++(int)
{
    BaseIterator<Type> iter(*this);
    ++(*this);
    return iter;
}

template<typename Type>
BaseIterator<Type>& BaseIterator<Type>::_next()
{
    if (_count.expired())
        throw err::CountPtrExpired(__FILE__, __LINE__ - 1);

    shared_ptr<size_t> n(_count);
    if (_index < *n) _index++;
    return *this;
}


template<typename Type>
bool BaseIterator<Type>::is_end() const
{
    return _is_end();
}
template<typename Type>
BaseIterator<Type>::operator bool() const
{
    return not _is_end();
}

template<typename Type>
bool BaseIterator<Type>::_is_end() const
{
    if (_count.expired())
        throw err::CountPtrExpired(__FILE__, __LINE__ - 1);

    return _index == *(_count.lock());
}


template<typename Type>
bool BaseIterator<Type>::operator !=(const BaseIterator<Type> &other) const
{
    return _index != other._index;
}
template<typename Type>
bool BaseIterator<Type>::operator ==(const BaseIterator<Type> &other) const
{
    return _index == other._index;
}

#endif // BASE_ITER_HPP
