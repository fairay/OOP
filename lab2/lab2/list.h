#ifndef LIST_H
#define LIST_H

#include "initializer_list"
#include "baselist.h"
#include "node.h"
#include "errors.h"
#include "iter.h"

template <typename Val_t>
class List: public BaseList
{
private:
    Node_sptr<Val_t> head = nullptr;
    Node_sptr<Val_t> tail = nullptr;

    void _appfront(Node_sptr<Val_t>);
    void _append(Node_sptr<Val_t>);

public:
    List() {}
    List(const List<Val_t>&);
    explicit List(std::initializer_list<Val_t>);
    virtual ~List() = default;

    ListIterator<Val_t> begin() {return ListIterator<Val_t>(head);}
    ListIterator<Val_t> end() {return ListIterator<Val_t>(nullptr);}
    ListIterator<Val_t> begin() const {return ListIterator<Val_t>(head);}
    ListIterator<Val_t> end() const {return ListIterator<Val_t>(nullptr);}

    Val_t& operator[](size_t i);
    friend ostream& operator<<(ostream &os, const List<Val_t>& lst)
    {
        lst.print();
        return os;
    }

    void appfront(Val_t);
    void append(Val_t);
    void print() const;
};
/// Constructors
//template <typename Val_t>
//List<Val_t>::List(const List<Val_t>& other)
//{

//}

template <typename Val_t>
List<Val_t>::List(std::initializer_list<Val_t> lst)
{
    for (Val_t val : lst)
        append(val);
}

///
/// private:
///
template <typename Val_t>
void List<Val_t>::_append(Node_sptr<Val_t> ptr)
{
    if (!ptr)   return;
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


///
/// public:
///
template <typename Val_t>
void List<Val_t>::print() const
{
    ListIterator<Val_t> iter = this->begin();
    ListIterator<Val_t> end = this->end();

    cout << "[" << (*iter++) << "]";
    while (iter != end)
        cout << " -> [" << (*iter++) << "]";
}

template <typename Val_t>
void List<Val_t>::append(Val_t val)
{
    Node<Val_t> *new_node = new Node<Val_t>(val);
    Node_sptr<Val_t> temp_ptr = Node_sptr<Val_t>(new_node);
    _append(temp_ptr);
}

template <typename Val_t>
Val_t& List<Val_t>::operator[](size_t i)
{
    if (*len <= i)
        throw err::Index(__FILE__, __LINE__-1, i);

    Node_sptr<Val_t> temp_ptr = head;
    for (size_t j=0; j<i and temp_ptr; j++)
        temp_ptr = temp_ptr->get_next();

    if (!temp_ptr)
        throw err::Index(__FILE__, __LINE__-5, i);
    return temp_ptr->get_val();
}

#endif // LIST_H
