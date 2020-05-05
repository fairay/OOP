#ifndef ITERATOR_H
#define ITERATOR_H

template <typename Val_t>
class List;

#include <iterator>
#include "node.h"
#include "errors.h"

template <typename Val_t>
class ListIterator: std::iterator<std::input_iterator_tag, Val_t>
{
    friend class List<Val_t>;
private:
    Node_wptr<Val_t> node;

    ListIterator<Val_t>& _next();
    bool _is_end() const;

    Val_t& _value();
    const Val_t& _value() const;

    Node_sptr<Val_t> _get_ptr();
    const Node_sptr<Val_t> _get_ptr() const;

public:
    ListIterator(const Node_sptr<Val_t>& node_): node(node_) {}
    ListIterator(const ListIterator<Val_t> &iter) = default;

    ListIterator<Val_t>& next();
    bool is_end() const;

    Val_t& value();
    const Val_t& value() const;

    Node_sptr<Val_t> get_ptr();
    const Node_sptr<Val_t> get_ptr() const;


    bool operator!=(const ListIterator<Val_t>& other) const;
    bool operator==(const ListIterator<Val_t>& other) const;

    Val_t& operator*();
    const Val_t& operator*() const;

    Node_sptr<Val_t> operator->();
    const Node_sptr<Val_t> operator->() const;

    ListIterator<Val_t>& operator++();
    ListIterator<Val_t> operator++(int);

    operator bool() const;
};

///
/// private:
///
template <typename Val_t>
ListIterator<Val_t>& ListIterator<Val_t>::_next()
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+2);
    Node_sptr<Val_t> temp_ptr = this->node.lock();
    node = temp_ptr->get_next();

    return *this;
}

template <typename Val_t>
bool ListIterator<Val_t>::_is_end() const
{
    return this->node.lock() == nullptr;
}

template <typename Val_t>
Val_t& ListIterator<Val_t>::_value()
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock()->get_val();
}
template <typename Val_t>
const Val_t& ListIterator<Val_t>::_value() const
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock()->get_val();
}

template <typename Val_t>
Node_sptr<Val_t> ListIterator<Val_t>::_get_ptr()
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock();
}
template <typename Val_t>
const Node_sptr<Val_t> ListIterator<Val_t>::_get_ptr() const
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock();
}

///
/// public:
///
template <typename Val_t>
ListIterator<Val_t>& ListIterator<Val_t>::next()
{
    return _next();
}

template <typename Val_t>
bool ListIterator<Val_t>::is_end() const
{
    return _is_end();
}

template <typename Val_t>
Val_t& ListIterator<Val_t>::value()
{
    return _value();
}
template <typename Val_t>
const Val_t& ListIterator<Val_t>::value() const
{
    return _value();
}

template <typename Val_t>
Node_sptr<Val_t> ListIterator<Val_t>::get_ptr()
{
    return _get_ptr();
}
template <typename Val_t>
const Node_sptr<Val_t> ListIterator<Val_t>::get_ptr() const
{
    return _get_ptr();
}


// Operators
template <typename Val_t>
bool ListIterator<Val_t>::operator!=(const ListIterator<Val_t>& other) const
{
    return !(this->node.lock() == other.node.lock());
}
template <typename Val_t>
bool ListIterator<Val_t>::operator==(const ListIterator<Val_t>& other) const
{
    return (this->node.lock()) == (other.node.lock());
}

template <typename Val_t>
Val_t& ListIterator<Val_t>::operator*()
{
    return _value();
}
template <typename Val_t>
const Val_t& ListIterator<Val_t>::operator*() const
{
    return _value();
}

template <typename Val_t>
Node_sptr<Val_t> ListIterator<Val_t>::operator->()
{
    return _get_ptr();
}
template <typename Val_t>
const Node_sptr<Val_t> ListIterator<Val_t>::operator->() const
{
    return _get_ptr();
}

template <typename Val_t>
ListIterator<Val_t>& ListIterator<Val_t>::operator++()
{
    return _next();
}
template <typename Val_t>
ListIterator<Val_t> ListIterator<Val_t>::operator++(int)
{
    ListIterator<Val_t> temp_iter(*this);
    ++(*this);
    return temp_iter;
}

template <typename Val_t>
ListIterator<Val_t>::operator bool() const
{
    return _is_end();
}
#endif // ITERATOR_H
