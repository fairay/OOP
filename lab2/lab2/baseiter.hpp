#ifndef BASEITER_HPP
#define BASEITER_HPP
#define BASEITER_HPP_EXERNAL

#include "baseiter.h"

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
    return not _is_end();
}
template <typename Val_t>
bool BaseIterator<Val_t>::is_end() const
{
    return _is_end();
}

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


#endif // BASEITER_HPP
