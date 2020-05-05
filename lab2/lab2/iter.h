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

public:
    ListIterator(const Node_sptr<Val_t>& node_): node(node_) {}
    ListIterator(const ListIterator<Val_t> &iter) = default;

    bool operator!=(const ListIterator<Val_t>& other) const;
    bool operator==(const ListIterator<Val_t>& other) const;

    Val_t& operator*();
    const Val_t& operator*() const;

    Node_sptr<Val_t> operator->();
    const Node_sptr<Val_t> operator->() const;

    ListIterator<Val_t>& operator++();
    ListIterator<Val_t> operator++(int);
};

template <typename Val_t>
bool ListIterator<Val_t>::operator!=(const ListIterator<Val_t>& other) const
{
    return !(this->node.lock() == other.node.lock());
//    Node_sptr<Val_t> this_ptr = this->node.lock();
//    Node_sptr<Val_t> other_ptr = other.node.lock();
//    return (*this_ptr) != (*other_ptr);
}
template <typename Val_t>
bool ListIterator<Val_t>::operator==(const ListIterator<Val_t>& other) const
{
    return (this->node.lock()) == (other.node.lock());
}

template <typename Val_t>
Val_t& ListIterator<Val_t>::operator*()
{
    if (this->node.expired())
        throw err::NoneExist(__FILE__, __LINE__+1);
    return this->node.lock()->get_val();
}
template <typename Val_t>
const Val_t& ListIterator<Val_t>::operator*() const
{
    if (this->node.expired())
        throw err::NoneExist(__FILE__, __LINE__+1);
    return (this->node.lock())->get_val;
}

template <typename Val_t>
Node_sptr<Val_t> ListIterator<Val_t>::operator->()
{
    if (this->node.expired())
        throw err::NoneExist(__FILE__, __LINE__+1);
    return this->node.lock();
}
template <typename Val_t>
const Node_sptr<Val_t> ListIterator<Val_t>::operator->() const
{
    if (this->node.expired())
        throw err::NoneExist(__FILE__, __LINE__+1);
    return this->node.lock();
}

template <typename Val_t>
ListIterator<Val_t>& ListIterator<Val_t>::operator++()
{
    if (this->node.expired())
        throw err::NoneExist(__FILE__, __LINE__+2);
    Node_sptr<Val_t> temp_ptr = this->node.lock();
    node = temp_ptr->get_next();

    return *this;
}

template <typename Val_t>
ListIterator<Val_t> ListIterator<Val_t>::operator++(int)
{
    ListIterator<Val_t> temp_iter(*this);
    ++(*this);
    return temp_iter;
}

#endif // ITERATOR_H
