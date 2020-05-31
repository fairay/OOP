#ifndef ARRAY_H
#define ARRAY_H

#include "base_array.h"
#include "iter.h"
#include "const_iter.h"

template <typename Type>
class Array: public BaseArray
{
public:
    Array();
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

    void append(const Type&);
private:
    shared_ptr<Type[]>& _arr;
};

#ifndef ARRAY_HPP
#include "array.hpp"
#endif//ARRAY_HPP

#endif // ARRAY_H
