#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <memory>
#include <iostream>

template <typename Val_t>
class Node;

template <typename Val_t>
using Node_sptr = std::shared_ptr<Node<Val_t>>;
template <typename Val_t>
using Node_wptr = std::weak_ptr<Node<Val_t>>;



template <typename Val_t>
class Node
{
public:
    Node(): next(nullptr) {}
    Node(const Val_t&);
    ~Node() = default;

    void set_val(const Val_t&);
    void set_next(Node_sptr<Val_t>);

    Val_t& get_val();
    Val_t* get_ptr();
    const Val_t& get_val() const;
    const Val_t* get_ptr() const;
    Node_sptr<Val_t> get_next();

    bool is_last() const;
private:
    Val_t value;
    Node_sptr<Val_t> next = nullptr;
};

#ifndef NODE_HPP_EXERNAL
#include "node.hpp"
#endif // NODE_HPP_EXERNAL

#endif // NODE_H
