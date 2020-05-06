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

    size_t _convert_index(int i) const;

    void _appfront(Node_sptr<Val_t>);
    void _append(Node_sptr<Val_t>);
    Node_sptr<Val_t> _alloc_node(const Val_t& val);
    Node_sptr<Val_t> _get_ptr(size_t i) const;
    Val_t& _get_i(size_t i) const;
    Val_t& _get_i(int i) const;

public:
    List() {}
    List(const List<Val_t>&);
    List(Val_t arr[], int len_);
    explicit List(std::initializer_list<Val_t>);

    virtual ~List() = default;

    ListIterator<Val_t> begin() const {return ListIterator<Val_t>(head);}
    ListIterator<Val_t> end() const {return ListIterator<Val_t>(nullptr);}

    Val_t& operator[](size_t i) const;
    Val_t& operator[](int i) const;
    List<Val_t>& operator=(const Val_t& val);
    List<Val_t>& operator=(const List<Val_t>& other);
    List<Val_t>& operator+=(const Val_t& val);
    List<Val_t>& operator+=(const List<Val_t>& other);
    List<Val_t>& operator!=(const List<Val_t>& other) const;
    List<Val_t>& operator==(const List<Val_t>& other) const;

    template <typename _Val_t>
    friend List<_Val_t> operator+(const List<_Val_t>& lst1, const List<_Val_t>& lst2);

    friend ostream& operator<<(ostream &os, const List<Val_t>& lst)
    {
        lst.print();
        return os;
    }
    template <typename _Val_t>
    friend ostream& operator>>(ostream &os, List<_Val_t>& lst);

    void appfront(const Val_t&);
    void appfront(const List<Val_t>& lst);
    void appfront(Val_t arr[], int len_);

    void append(const Val_t&);
    void append(const List<Val_t>& lst);
    void append(Val_t arr[], int len_);

    Val_t popfront();
    Val_t popend();
    Val_t pop_i(size_t i);
    Val_t pop_i(int i);

    void print() const;
    void clear();
    void set(const List<Val_t>& other);
    void set(Val_t arr[], int len_);
    void add_list(const List<Val_t>& other);
    bool is_equal(const List<Val_t>& other);
    bool is_not_equal(const List<Val_t>& other);

    Val_t& get_i(size_t i) const;
    Val_t& get_i(int i) const;
    Val_t* get_arr();
    void set_i(Val_t& val, size_t i);
    void set_i(Val_t& val, int i);

    int find(const Val_t& val);
};
/// Friends

/// Constructors
template <typename Val_t>
List<Val_t>::List(const List<Val_t>& other)
{
    for (Val_t val : other)
        append(val);
}

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
size_t List<Val_t>::_convert_index(int i) const
{
    if (i < 0)
    {
        if (static_cast<size_t>(-i) > len)
            throw err::Index(__FILE__, __LINE__+7, i);
        i += len;
    }
    else if (len - i <= 0)
    {
        throw err::Index(__FILE__, __LINE__+2, i);
    }
    return static_cast<size_t>(i);
}

template <typename Val_t>
void List<Val_t>::_append(Node_sptr<Val_t> ptr)
{
    if (!ptr)   return;
    if (is_empty())
    {
        head = ptr;
        tail = ptr;
        len = 1;
    }
    else
    {
        tail->set_next(ptr);
        tail = ptr;
        len++;
    }
}

template <typename Val_t>
void List<Val_t>::_appfront(Node_sptr<Val_t> ptr)
{
    if (!ptr)   return;
    if (is_empty())
    {
        head = ptr;
        tail = ptr;
        len = 1;
    }
    else
    {
        head->set_next(ptr);
        head = ptr;
        len++;
    }
}

template <typename Val_t>
Node_sptr<Val_t> List<Val_t>::_alloc_node(const Val_t& val)
{
    try
    {
        Node<Val_t> *new_node = new Node<Val_t>(val);
        return Node_sptr<Val_t>(new_node);
    }
    catch (std::bad_alloc&)
    {
        throw err::AllocFailed(__FILE__, __LINE__-5);
    }
}

template <typename Val_t>
Node_sptr<Val_t> List<Val_t>::_get_ptr(size_t i) const
{
    if (len <= i)
        throw err::Index(__FILE__, __LINE__-1, static_cast<int>(i));

    Node_sptr<Val_t> temp_ptr = head;
    for (size_t j=0; j<i and temp_ptr; j++)
        temp_ptr = temp_ptr->get_next();

    if (!temp_ptr)
        throw err::Index(__FILE__, __LINE__-5, static_cast<int>(i));
    return temp_ptr;
}

template <typename Val_t>
Val_t& List<Val_t>::_get_i(size_t i) const
{
    Node_sptr<Val_t> ptr = _get_ptr(i);
    return ptr->get_val();
}
template <typename Val_t>
Val_t& List<Val_t>::_get_i(int i) const
{
    size_t convert_i = _convert_index(i);
    Node_sptr<Val_t> ptr = _get_ptr(convert_i);
    return ptr->get_val();
}


///
/// public:
///
template <typename Val_t>
void List<Val_t>::appfront(const Val_t& val)
{
    Node_sptr<Val_t> temp_ptr = _alloc_node(val);
    _append(temp_ptr);
}

template <typename Val_t>
void List<Val_t>::append(const Val_t& val)
{
    Node_sptr<Val_t> temp_ptr = _alloc_node(val);
    _append(temp_ptr);
}


template <typename Val_t>
Val_t List<Val_t>::popfront()
{
    if (is_empty())
        throw err::EmptyList(__FILE__, __LINE__-3);

    Val_t val = head->get_val();
    if (len > 1)
        head = head->get_next();
    else
    {
        head = nullptr;
        tail = nullptr;
    }
    len--;
    return val;
}
template <typename Val_t>
Val_t List<Val_t>::popend()
{
    if (is_empty())
        throw err::EmptyList(__FILE__, __LINE__-3);

    Val_t val = tail->get_val();
    if (len > 1)
    {
        Node_sptr<Val_t> pre_ptr= _get_ptr(len-2);
        pre_ptr->set_next(nullptr);
        tail = pre_ptr;
    }
    else
    {
        head = nullptr;
        tail = nullptr;
    }
    len--;
    return val;
}

template <typename Val_t>
Val_t List<Val_t>::pop_i(size_t i)
{
    if (is_empty())
        throw err::EmptyList(__FILE__, __LINE__-3);
    if (i >= len)
        throw err::Index(__FILE__, __LINE__-3, static_cast<int>(i));


    if (i == 0)
        return popfront();
    else if (i == len - 1)
        return popend();
    else
    {
        Val_t val = _get_ptr(i)->get_val();
        Node_sptr<Val_t> pre_ptr= _get_ptr(i-1);
        Node_sptr<Val_t> post_ptr= _get_ptr(i+1);
        pre_ptr->set_next(post_ptr);
        len--;

        return val;
    }
}
template <typename Val_t>
Val_t List<Val_t>::pop_i(int i)
{
    return pop_i(_convert_index(i));
}


template <typename Val_t>
void List<Val_t>::print() const
{
    if (is_empty())
    {
        cout << "Empty list";
        return;
    }

    ListIterator<Val_t> iter = this->begin();
    ListIterator<Val_t> end = this->end();

    cout << "[" << (*iter++) << "]";
    while (iter != end)
        cout << " -> [" << (*iter++) << "]";
}

template <typename Val_t>
void List<Val_t>::clear()
{
    if (is_empty()) return;
    Node_sptr<Val_t> temp_ptr;
    while (head)
    {
        temp_ptr = head->get_next();
        head.reset();
        head = temp_ptr;
    }
    tail.reset();
    len = 0;
}


// Operators
template <typename Val_t>
Val_t& List<Val_t>::operator[](size_t i) const
{
    return _get_i(i);
}
template <typename Val_t>
Val_t& List<Val_t>::operator[](int i) const
{
    return _get_i(i);
}

#endif // LIST_H
