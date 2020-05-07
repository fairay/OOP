#ifndef CONST_ITER_H
#define CONST_ITER_H

#include "baseiter.h"

template <typename Val_t>
class ConstListIterator: public BaseIterator<Val_t>
{
    friend class List<Val_t>;
private:
    ConstListIterator(const Node_sptr<Val_t>& node_):
        BaseIterator<Val_t>(node_) {}

    const Val_t& _get_value() const;
    const Node_sptr<Val_t> _get_ptr() const;

public:
    ConstListIterator(const ConstListIterator<Val_t> &other):
        BaseIterator<Val_t>(other) {}

    const Val_t& get_value() const;
    const Val_t& operator*() const;

    const Node_sptr<Val_t> get_ptr() const;
    const Node_sptr<Val_t> operator->() const;
};
///
/// private:
///
template <typename Val_t>
const Val_t& ConstListIterator<Val_t>::_get_value() const
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock()->get_val();
}
template <typename Val_t>
const Node_sptr<Val_t> ConstListIterator<Val_t>::_get_ptr() const
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock();
}

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
const Node_sptr<Val_t> ConstListIterator<Val_t>::get_ptr() const
{
    return _get_ptr();
}
template <typename Val_t>
const Node_sptr<Val_t> ConstListIterator<Val_t>::operator->() const
{
    return _get_ptr();
}

#endif // CONST_ITER_H
