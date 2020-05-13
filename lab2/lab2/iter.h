#ifndef ITERATOR_H
#define ITERATOR_H

template <typename Val_t>
class List;

#include "node.h"
#include "errors.h"
#include "baseiter.h"


template <typename Val_t>
class ListIterator: public BaseIterator<Val_t>
{
    friend class List<Val_t>;
public:
    ListIterator(const ListIterator<Val_t> &other):
        BaseIterator<Val_t>(other) {}

    Val_t& get_value();
    Val_t& operator*();
    const Val_t& get_value() const;
    const Val_t& operator*() const;

    Val_t* get_ptr();
    Val_t* operator->();
    const Val_t* get_ptr() const;
    const Val_t* operator->() const;

private:
    ListIterator(const Node_sptr<Val_t>& node_):
        BaseIterator<Val_t>(node_) {}

    Val_t& _get_value();
    Val_t* _get_ptr();
    Node_sptr<Val_t> _get_node_ptr();
    const Val_t& _get_value() const;
    const Val_t* _get_ptr() const;
    const Node_sptr<Val_t> _get_node_ptr() const;
};

#ifndef ITER_HPP
#include "iter.hpp"
#endif // ITER_HPP

#endif // ITERATOR_H
