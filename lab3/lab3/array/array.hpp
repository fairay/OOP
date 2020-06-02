#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "array.h"

template <typename Type>
Array<Type>::Array(): BaseArray (0), _arr(nullptr) {}
template <typename Type>
Array<Type>::Array(initializer_list<Type> args)
{
    _realloc(args.size());
    Iterator<Type> iter = this->begin();
    for (Type val : args)
    {
        *iter = val;
        iter++;
    }
}
template <typename Type>
Array<Type>::Array(size_t num)
{
    _realloc(num);
}
template <typename Type>
Array<Type>::Array(const Array<Type>& other): BaseArray (other)
{
    _copy_array(other);
}
template <typename Type>
Array<Type>::Array(Array<Type>&& other)
{
    _realloc(other.get_size());
    Iterator<Type> iter = this->begin();
    ConstIterator<Type> other_iter = other.cbegin();
    for (; iter; iter++, other_iter++)
        *iter = *other_iter;
    other.clear();
}

template <typename Type>
Array<Type>& Array<Type>::operator=(const Array<Type>& other)
{
    clear();
    _copy_array(other);
    return *this;
}

template <typename Type>
void Array<Type>::_copy_array(const Array<Type>& other)
{
    _realloc(other.get_size());
    Iterator<Type> iter = this->begin();
    ConstIterator<Type> other_iter = other.begin();
    for (; iter; iter++, other_iter++)
        *iter = *other_iter;
}
template <typename Type>
void Array<Type>::_clone_array(Array<Type>&& other)
{
    _arr = other._arr;
    _count = other._count;
}


template <typename Type>
Type& Array<Type>::operator[](size_t index)
{
    return _get_elem(index);
}
template <typename Type>
const Type& Array<Type>::operator[](size_t index) const
{
    return _get_elem(index);
}

template<typename Type>
Type& Array<Type>::_get_elem(size_t index)
{
    if (index >= get_size())
        throw err::OutOfRange(__FILE__, __LINE__ - 1, index);
    return _arr[index];
}
template<typename Type>
const Type& Array<Type>::_get_elem(size_t index) const
{
    if (index >= get_size())
        throw err::OutOfRange(__FILE__, __LINE__ - 1, index);
    return _arr[index];
}

template<typename Type>
void Array<Type>::append(const Type& new_el)
{
    _realloc(get_size()+1);
    _get_elem(get_size()-1) = new_el;
}
template<typename Type>
void Array<Type>::remove(const Iterator<Type>& iter_)
{
    if (iter_.is_end())  return;
    Iterator<Type> iter(iter_);
    Iterator<Type> forward(iter);
    forward++;
    for (; forward; iter++, forward++)
        *iter = *forward;
    _realloc(get_size()-1);
}

template <typename Type>
void Array<Type>::clear()
{
    if (!get_size()) return;
    _realloc(0);
}
template <typename Type>
void Array<Type>::_realloc(size_t new_n)
{
    if (new_n == get_size())    return;

    if (_arr == nullptr)
    {
        try
        {
            _arr = shared_ptr<Type[]>(new Type[new_n]);
        }
        catch(std::bad_alloc&)
        {
            throw err::AllocFailed(__FILE__, __LINE__-4);
        }
    }
    else if (new_n != 0)
    {
        Array<Type> new_arr(new_n);
        Iterator<Type> new_iter = new_arr.begin();
        ConstIterator<Type> iter = this->cbegin();
        for (; bool(new_iter) && bool(iter); new_iter++, iter++)
        {
            *new_iter = *iter;
        }
        _clone_array(std::move(new_arr));
    }
    else
    {
        _arr.reset();
    }
    *_count = new_n;
}

#endif // ARRAY_HPP
