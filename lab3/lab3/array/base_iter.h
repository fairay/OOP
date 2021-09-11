#ifndef BASE_ITER_H
#define BASE_ITER_H

#include <iterator>
#include <memory>
#include "errors/array_errors.h"

using namespace std;

template <typename Type>
class BaseIterator:  public std::iterator<std::input_iterator_tag, Type>
{
public:
    BaseIterator(const BaseIterator<Type> &other);

    operator bool() const;
    bool is_end() const;

    bool operator !=(const BaseIterator<Type> &other) const;
    bool operator ==(const BaseIterator<Type> &other) const;

    BaseIterator<Type>& operator++();
    BaseIterator<Type> operator++(int);
    BaseIterator<Type>& next();
protected:
    BaseIterator(const shared_ptr<Type[]>& a, const shared_ptr<size_t>& c,
                 size_t ind = 0) : _arr(a), _count(c), _index(ind) {}

    weak_ptr<Type[]> _arr;
    weak_ptr<size_t> _count;
    size_t _index = 0;
private:
    bool _is_end() const;
    BaseIterator<Type>& _next();
};

#ifndef BASE_ITER_HPP
#include "base_iter.hpp"
#endif // BASE_ITER_HPP

#endif // BASE_ITER_H
