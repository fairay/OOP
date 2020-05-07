#ifndef BASEITER_H
#define BASEITER_H

template <typename Val_t>
class List;

#include <iterator>
#include "node.h"
#include "errors.h"

template <typename Val_t>
class BaseIterator: std::iterator<std::input_iterator_tag, Val_t>
{
protected:
    Node_wptr<Val_t> node;
    BaseIterator(const Node_sptr<Val_t>& node_): node(node_) {}

private:
    BaseIterator<Val_t>& _next();
    bool _is_end() const;

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
};

///
/// private:
///
template <typename Val_t>
BaseIterator<Val_t>& BaseIterator<Val_t>::_next()
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+2);
    Node_sptr<Val_t> temp_ptr = this->node.lock();
    node = temp_ptr->get_next();

    return *this;
}

template <typename Val_t>
bool BaseIterator<Val_t>::_is_end() const
{
    return this->node.lock() == nullptr;
}

///
/// public:
///
template <typename Val_t>
bool BaseIterator<Val_t>::operator!=(const BaseIterator<Val_t>& other) const
{
    return !(this->node.lock() == other.node.lock());
}
template <typename Val_t>
bool BaseIterator<Val_t>::operator==(const BaseIterator<Val_t>& other) const
{
    return (this->node.lock()) == (other.node.lock());
}


template <typename Val_t>
BaseIterator<Val_t>& BaseIterator<Val_t>::operator++()
{
    return _next();
}
template <typename Val_t>
BaseIterator<Val_t> BaseIterator<Val_t>::operator++(int)
{
    BaseIterator<Val_t> temp_iter(*this);
    ++(*this);
    return temp_iter;
}
template <typename Val_t>
BaseIterator<Val_t>& BaseIterator<Val_t>::next()
{
    return _next();
}


template <typename Val_t>
BaseIterator<Val_t>::operator bool() const
{
    return _is_end();
}
template <typename Val_t>
bool BaseIterator<Val_t>::is_end() const
{
    return _is_end();
}


#endif // BASEITER_H
