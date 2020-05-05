#ifndef ITERATOR_H
#define ITERATOR_H

#include <iterator>
#include "node.h"

template <typename Val_t>
class ListIterator: std::iterator<std::input_iterator_tag, Val_t>
{
private:
    Node_wptr<Val_t> list;

public:
    ListIterator() {}
};

#endif // ITERATOR_H
