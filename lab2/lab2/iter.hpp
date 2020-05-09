#ifndef ITER_HPP
#define ITER_HPP
#define ITER_HPP_EXERNAL

#include "iter.h"

///
/// public:
///
template <typename Val_t>
Val_t& ListIterator<Val_t>::get_value()
{
    return _get_value();
}
template <typename Val_t>
Val_t& ListIterator<Val_t>::operator*()
{
    return _get_value();
}
template <typename Val_t>
const Val_t& ListIterator<Val_t>::get_value() const
{
    return _get_value();
}
template <typename Val_t>
const Val_t& ListIterator<Val_t>::operator*() const
{
    return _get_value();
}


template <typename Val_t>
Val_t* ListIterator<Val_t>::get_ptr()
{
    return _get_ptr();
}
template <typename Val_t>
Val_t* ListIterator<Val_t>::operator->()
{
    return _get_ptr();
}
template <typename Val_t>
const Val_t* ListIterator<Val_t>::get_ptr() const
{
    return _get_ptr();
}
template <typename Val_t>
const Val_t* ListIterator<Val_t>::operator->() const
{
    return _get_ptr();
}


///
/// private:
///
template <typename Val_t>
Val_t& ListIterator<Val_t>::_get_value()
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock()->get_val();
}
template <typename Val_t>
Val_t* ListIterator<Val_t>::_get_ptr()
{
    return _get_node_ptr()->get_ptr();
}
template <typename Val_t>
Node_sptr<Val_t> ListIterator<Val_t>::_get_node_ptr()
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock();
}

template <typename Val_t>
const Val_t& ListIterator<Val_t>::_get_value() const
{
    return _get_node_ptr()->get_val();
}
template <typename Val_t>
const Val_t* ListIterator<Val_t>::_get_ptr() const
{
    return _get_node_ptr()->get_ptr();
}
template <typename Val_t>
const Node_sptr<Val_t> ListIterator<Val_t>::_get_node_ptr() const
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock();
}

#endif // ITER_HPP
