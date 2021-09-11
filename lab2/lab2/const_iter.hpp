#ifndef CONST_ITER_HPP
#define CONST_ITER_HPP

#include "const_iter.h"

///
/// public:
///
template <typename Val_t>
const Val_t& ConstListIterator<Val_t>::get_value() const
{
    return _get_value();
}
template <typename Val_t>
const Val_t& ConstListIterator<Val_t>::operator*() const
{
    return _get_value();
}

template <typename Val_t>
const Val_t* ConstListIterator<Val_t>::get_ptr() const
{
    return _get_ptr();
}
template <typename Val_t>
const Val_t* ConstListIterator<Val_t>::operator->() const
{
    return _get_ptr();
}


///
/// private:
///
template <typename Val_t>
const Val_t& ConstListIterator<Val_t>::_get_value() const
{
    return _get_node_ptr()->get_val();
}
template <typename Val_t>
const Val_t* ConstListIterator<Val_t>::_get_ptr() const
{
    return _get_node_ptr()->get_ptr();
}
template <typename Val_t>
const Node_sptr<Val_t> ConstListIterator<Val_t>::_get_node_ptr() const
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock();
}


#endif // CONST_ITER_HPP
