#ifndef NODE_HPP
#define NODE_HPP
#define NODE_HPP_EXERNAL

#include "node.h"


template <typename Val_t>
Node<Val_t>::Node(const Val_t& val)
{
    value = val;
    next = nullptr;
}

template <typename Val_t>
void Node<Val_t>::set_val(const Val_t &new_val)
{
    value = new_val;
}
template <typename Val_t>
void Node<Val_t>::set_next(Node_sptr<Val_t> ptr)
{
    next = ptr;
}


template <typename Val_t>
Node_sptr<Val_t> Node<Val_t>::get_next()
{
    return next;
}

template <typename Val_t>
Val_t& Node<Val_t>::get_val()
{
    return value;
}
template <typename Val_t>
const Val_t& Node<Val_t>::get_val() const
{
    return value;
}

template <typename Val_t>
Val_t* Node<Val_t>::get_ptr()
{
    return &value;
}
template <typename Val_t>
const Val_t* Node<Val_t>::get_ptr() const
{
    return &value;
}


template <typename Val_t>
bool Node<Val_t>::is_last() const
{
    return next == nullptr;
}


#endif // NODE_HPP
