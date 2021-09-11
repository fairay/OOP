#ifndef BASEITER_H
#define BASEITER_H

template <typename Val_t>
class List;

#include <iterator>
#include "node.h"
#include "errors.h"

template <typename Val_t>
class BaseIterator: public std::iterator<std::input_iterator_tag, Val_t>
{
public:
    BaseIterator(const BaseIterator<Val_t> &other)
    { node = other.node; }

    operator bool() const;
    bool is_end() const;

    bool operator!=(const BaseIterator<Val_t>& other) const;
    bool operator==(const BaseIterator<Val_t>& other) const;

    BaseIterator<Val_t>& operator++();
    BaseIterator<Val_t> operator++(int);
    BaseIterator<Val_t>& next();

protected:
    Node_wptr<Val_t> node;
    BaseIterator(const Node_sptr<Val_t>& node_): node(node_) {}

private:
    BaseIterator<Val_t>& _next();
    bool _is_end() const;
};

#ifndef BASEITER_HPP
#include "baseiter.hpp"
#endif // BASEITER_HPP

#endif // BASEITER_H
