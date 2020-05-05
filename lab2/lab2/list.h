#ifndef LIST_H
#define LIST_H

#include "initializer_list"
#include "baselist.h"
#include "node.h"
#include "errors.h"

template <typename Val_t>
class List: public BaseList
{
private:
    Node_sptr<Val_t> head;
    Node_sptr<Val_t> tail;

    void appfront(Node_sptr<Val_t>);
    void append(Node_sptr<Val_t>);

public:
    List() {}
    List(const List<Val_t>&);
    explicit List(std::initializer_list<Val_t>);
    virtual ~List() = default;

    Val_t& operator[](size_t i);

    void appfront(Val_t);
    void append(Val_t);
};

template <typename Val_t>
List<Val_t>::List(std::initializer_list<Val_t> lst)
{
    for (Val_t val : lst)
        append(val);
}


template <typename Val_t>
void List<Val_t>::append(Node_sptr<Val_t> ptr)
{
    if (is_empty())
    {
        head = ptr;
        tail = ptr;
        *len = 1;
    }
    else
    {
        tail->set_next(ptr);
        tail = ptr;
        (*len)++;
    }
}

template <typename Val_t>
void List<Val_t>::append(Val_t val)
{
    Node<Val_t> *new_node = new Node<Val_t>(val);
    Node_sptr<Val_t> temp_ptr = Node_sptr<Val_t>(new_node);
    append(temp_ptr);
}

template <typename Val_t>
Val_t& List<Val_t>::operator[](size_t i)
{
    Node_sptr<Val_t> temp_ptr = head;
    for (size_t j=0; j<i and temp_ptr; j++)
        temp_ptr = temp_ptr->get_next();

    if (temp_ptr)
        return temp_ptr->get_val();
    else
        throw ErrIndex(__FILE__, __LINE__-5, __TIME__, i);
}


#endif // LIST_H
