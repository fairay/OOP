#ifndef ITER_HPP
#define ITER_HPP

#include "iter.h"

template<typename Type>
const Type& Iterator<Type>::operator*() const
{
    return _get_value();
}
template<typename Type>
const Type& Iterator<Type>::get_value() const
{
    return _get_value();
}
template<typename Type>
Type& Iterator<Type>::operator*()
{
    return _get_value();
}
template<typename Type>
Type& Iterator<Type>::get_value()
{
    return _get_value();
}

template<typename Type>
const Type& Iterator<Type>::_get_value() const
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
Type& Iterator<Type>::_get_value()
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
const Type* Iterator<Type>::operator->() const
{
    return _get_ptr();
}
template<typename Type>
const Type* Iterator<Type>::get_ptr() const
{
    return _get_ptr();
}
template<typename Type>
Type* Iterator<Type>::operator->()
{
    return _get_ptr();
}
template<typename Type>
Type* Iterator<Type>::get_ptr()
{
    return _get_ptr();
}

template<typename Type>
const Type* Iterator<Type>::_get_ptr() const
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
template<typename Type>
Type* Iterator<Type>::_get_ptr()
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

#endif // ITER_HPP
