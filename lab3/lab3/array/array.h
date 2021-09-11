#ifndef ARRAY_H
#define ARRAY_H

#include "base_array.h"
#include "iter.h"
#include "const_iter.h"
#include "errors/array_errors.h"

template <typename Type>
class Array: public BaseArray
{
public:
    Array();
    Array(initializer_list<Type> args);
    explicit Array(size_t num);
    explicit Array(const Array<Type>& other);
    Array(Array<Type>&& other);

    virtual ~Array() = default;

    Iterator<Type> begin() {return Iterator<Type>(_arr, _count, 0);}
    Iterator<Type> end() {return Iterator<Type>(_arr, _count, *_count);}
    ConstIterator<Type> begin() const {return ConstIterator<Type>(_arr, _count, 0);}
    ConstIterator<Type> end() const {return ConstIterator<Type>(_arr, _count, *_count);}
    ConstIterator<Type> cbegin() const {return ConstIterator<Type>(_arr, _count, 0);}
    ConstIterator<Type> cend() const {return ConstIterator<Type>(_arr, _count, *_count);}

    Type& operator[](size_t index);
    const Type& operator[](size_t index) const;
    Type* get_arr();

    Array<Type>& operator=(const Array<Type>& other);
    Array<Type>& operator=(initializer_list<Type> args);
    Array<Type>& operator=(Array<Type>&& other);

    void append(const Type& new_el);
    void remove(const Iterator<Type>& iter);

    void clear();
private:
    shared_ptr<Type[]> _arr {nullptr};

    void _copy_array(const Array<Type>& other);
    void _clone_array(Array<Type>&& other);

    void _realloc(size_t new_n);
    Type& _get_elem(size_t index);
    const Type& _get_elem(size_t index) const;
};

#ifndef ARRAY_HPP
#include "array.hpp"
#endif//ARRAY_HPP

#endif // ARRAY_H
