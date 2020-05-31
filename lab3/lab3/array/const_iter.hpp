#ifndef CONST_ITER_HPP
#define CONST_ITER_HPP

#include "const_iter.h"

template<typename Type>
const Type& ConstIterator<Type>::operator*() const
{
    return _get_value();
}
template<typename Type>
const Type& ConstIterator<Type>::get_value() const
{
    return _get_value();
}

template<typename Type>
const Type& ConstIterator<Type>::_get_value() const
{
    if (this->_arr.expired())
        throw err::ArrayPtrExpired(__FILE__, __LINE__-1);
    if (this->_count.expired())
        throw err::CountPtrExpired(__FILE__, __LINE__-1);
    if (this->_index >= *(this->_count.lock()))
        throw err::OutOfRange(__FILE__, __LINE__ - 1, this->_index);

    shared_ptr<Type[]> a(this->_arr);

    return a[this->_index];
}

template<typename Type>
const Type* ConstIterator<Type>::operator->() const
{
    return _get_ptr();
}
template<typename Type>
const Type* ConstIterator<Type>::get_ptr() const
{
    return _get_ptr();
}

template<typename Type>
const Type* ConstIterator<Type>::_get_ptr() const
{
    if (this->_arr.expired())
        throw err::ArrayPtrExpired(__FILE__, __LINE__-1);
    if (this->_count.expired())
        throw err::CountPtrExpired(__FILE__, __LINE__-1);
    if (this->_index >= *(this->_count.lock()))
        throw err::OutOfRange(__FILE__, __LINE__ - 1, this->_index);

    shared_ptr<Type[]> a(this->_arr);

    return &a[this->_index];
}

#endif // CONST_ITER_HPP
