#ifndef ITERATOR_H
#define ITERATOR_H

template <typename Val_t>
class List;

#include <iterator>
#include "node.h"
#include "errors.h"
#include "baseiter.h"

template <typename Val_t>
class ListIterator: public BaseIterator<Val_t>
{
    friend class List<Val_t>;
private:
    ListIterator(const Node_sptr<Val_t>& node_):
        BaseIterator<Val_t>(node_) {}

    Val_t& _get_value() const;
    Val_t* _get_ptr() const;
    Node_sptr<Val_t> _get_node_ptr() const;

public:
    ListIterator(const ListIterator<Val_t> &other):
        BaseIterator<Val_t>(other) {}

    Val_t& get_value() const;
    Val_t& operator*() const;

    Val_t* get_ptr() const;
    Val_t* operator->() const;
};
///
/// private:
///
template <typename Val_t>
Val_t& ListIterator<Val_t>::_get_value() const
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock()->get_val();
}
template <typename Val_t>
Val_t* ListIterator<Val_t>::_get_ptr() const
{
    return _get_node_ptr()->get_ptr();
}
template <typename Val_t>
Node_sptr<Val_t> ListIterator<Val_t>::_get_node_ptr() const
{
    if (this->node.expired())
        throw err::NullNode(__FILE__, __LINE__+1);
    return this->node.lock();
}

///
/// public:
///
template <typename Val_t>
Val_t& ListIterator<Val_t>::get_value() const
{
    return _get_value();
}
template <typename Val_t>
Val_t& ListIterator<Val_t>::operator*() const
{
    return _get_value();
}

template <typename Val_t>
Val_t* ListIterator<Val_t>::get_ptr() const
{
    return _get_ptr();
}
template <typename Val_t>
Val_t* ListIterator<Val_t>::operator->() const
{
    return _get_ptr();
}

#endif // ITERATOR_H
