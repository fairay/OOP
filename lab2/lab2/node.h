#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <stdlib.h>
#include <memory>

template <typename Val_t>
class Node;

template <typename Val_t>
using Node_sptr = std::shared_ptr<Node<Val_t>>;

template <typename Val_t>
using Node_wptr = std::weak_ptr<Node<Val_t>>;

template <typename Val_t>
class Node
{
private:
    Val_t value;
    Node_sptr<Val_t> next = nullptr;
public:
    Node(): next(nullptr) {}
    Node(Val_t&);
    ~Node() = default;

    void set_val(Val_t&);
    Val_t& get_val();

    void set_next(Node_sptr<Val_t>);
    Node_sptr<Val_t> get_next();

    bool is_last();
};

template <typename Val_t>
Node<Val_t>::Node(Val_t& val)
{
    value = val;
    next = nullptr;
}

template <typename Val_t>
void Node<Val_t>::set_val(Val_t& new_val)
{
    value = new_val;
}

template <typename Val_t>
Val_t& Node<Val_t>::get_val()
{
    return value;
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
bool Node<Val_t>::is_last()
{
    return *next == nullptr;
}

#endif // NODE_H