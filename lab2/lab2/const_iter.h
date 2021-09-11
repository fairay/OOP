#ifndef CONST_ITER_H
#define CONST_ITER_H

#include "baseiter.h"

template <typename Val_t>
class ConstListIterator: public BaseIterator<Val_t>
{
    friend class List<Val_t>;
public:
    ConstListIterator(const ConstListIterator<Val_t> &other):
        BaseIterator<Val_t>(other) {}

    const Val_t& get_value() const;
    const Val_t& operator*() const;

    const Val_t* get_ptr() const;
    const Val_t* operator->() const;

private:
    ConstListIterator(const Node_sptr<Val_t>& node_):
        BaseIterator<Val_t>(node_) {}

    const Val_t& _get_value() const;
    const Val_t* _get_ptr() const;
    const Node_sptr<Val_t> _get_node_ptr() const;
};

#ifndef CONST_ITER_HPP
#include "const_iter.hpp"
#endif // CONST_ITER_HPP

#endif // CONST_ITER_H
