#ifndef LIST_H
#define LIST_H

#include "initializer_list"
#include "baselist.h"
#include "node.h"
#include "errors.h"
#include "iter.h"
#include "const_iter.h"

template <typename Val_t>
class List: public BaseList
{
private:
    Node_sptr<Val_t> head = nullptr;
    Node_sptr<Val_t> tail = nullptr;

    size_t _convert_index(int i) const;

    Node_sptr<Val_t> _alloc_node(const Val_t& val);
    Node_sptr<Val_t> _get_ptr(size_t i) const;
    Val_t& _get_i(size_t i);
    Val_t& _get_i(int i);
    const Val_t& _get_i(size_t i) const;
    const Val_t& _get_i(int i) const;

    void _appfront_ptr(Node_sptr<Val_t>);
    void _append_ptr(Node_sptr<Val_t>);
    void _appfront(const Val_t& val);
    void _append(const Val_t& val);

    void _append_list(const List<Val_t>& other);
    void _append_array(Val_t arr[], size_t _len);
    void _append_init_list(std::initializer_list<Val_t> lst);

    void _insert_ptr(size_t i, Node_sptr<Val_t> ptr);
    void _insert(size_t i, const Val_t& val);

    bool _is_equal(const Val_t& val) const;
    bool _is_equal(const List<Val_t>& other) const;
    bool _is_equal(Val_t arr[], size_t len_) const;
    bool _is_equal(std::initializer_list<Val_t> lst) const;

public:
    List() {}
    List(const List<Val_t>&);
    List(Val_t arr[], size_t _len);
    explicit List(std::initializer_list<Val_t>);

    virtual ~List() = default;

    ListIterator<Val_t> begin() {return ListIterator<Val_t>(head);}
    ListIterator<Val_t> end() {return ListIterator<Val_t>(nullptr);}
    ConstListIterator<Val_t> begin() const {return ConstListIterator<Val_t>(head);}
    ConstListIterator<Val_t> end() const {return ConstListIterator<Val_t>(nullptr);}

    /// Getters
    Val_t& operator[](size_t i);
    Val_t& operator[](int i);
    const Val_t& operator[](size_t i) const;
    const Val_t& operator[](int i) const;
    //
    Val_t& get_i(size_t i);
    Val_t& get_i(int i);
    const Val_t& get_i(size_t i) const;
    const Val_t& get_i(int i) const;
    Val_t* get_arr();

    /// Setters
    List<Val_t>& operator=(const Val_t& val);
    List<Val_t>& operator=(const List<Val_t>& other);
    List<Val_t>& operator=(std::initializer_list<Val_t> lst);
    //
    void set(const Val_t& other);
    void set(const List<Val_t>& other);
    void set(std::initializer_list<Val_t> lst);
    void set(Val_t arr[], size_t len_);
    //
    void set_i(const Val_t& val, size_t i);
    void set_i(const Val_t& val, int i);

    /// Adders
    List<Val_t>& operator+=(const Val_t& val);
    List<Val_t>& operator+=(const List<Val_t>& other);
    List<Val_t>& operator+=(std::initializer_list<Val_t> lst);
    //
    void appfront(const Val_t&);
    void appfront(const List<Val_t>& lst);
    void appfront(std::initializer_list<Val_t> lst);
    void appfront(Val_t arr[], size_t len_);
    //
    void append(const Val_t&);
    void append(const List<Val_t>& lst);
    void append(std::initializer_list<Val_t> lst);
    void append(Val_t arr[], size_t len_);

    /// Inserters
    void insert(size_t i, const Val_t& val);
    void insert(size_t i, const List<Val_t>& other);
    void insert(size_t i, std::initializer_list<Val_t> lst);
    void insert(size_t i, Val_t arr[], size_t len_);

    /// Deleters
    void clear();
    Val_t popfront();
    Val_t popend();
    Val_t pop_i(size_t i);
    Val_t pop_i(int i);

    /// Comparators
    /// Equal
    bool operator==(const Val_t& val) const;
    bool operator==(const List<Val_t>& other) const;
    bool operator==(std::initializer_list<Val_t> lst) const;
    //
    bool is_equal(const Val_t&) const;
    bool is_equal(const List<Val_t>& other) const;
    bool is_equal(std::initializer_list<Val_t> lst) const;
    bool is_equal(Val_t arr[], int len_) const;

    /// Not equal
    bool operator!=(const Val_t& val) const;
    bool operator!=(const List<Val_t>& other) const;
    bool operator!=(std::initializer_list<Val_t> lst) const;
    //
    bool isnt_equal(const Val_t&) const;
    bool isnt_equal(const List<Val_t>& other) const;
    bool isnt_equal(std::initializer_list<Val_t> lst) const;
    bool isnt_equal(Val_t arr[], size_t len_) const;


    template <typename _Val_t>
    friend List<_Val_t> operator+(const List<_Val_t>& lst1, const List<_Val_t>& lst2);

    friend ostream& operator<<(ostream &os, const List<Val_t>& lst)
    {
        lst.print();
        return os;
    }

    void print() const;
    void swap(size_t i1, size_t i2);
    void reverse();
    void sort(bool is_rev=false);
    void sort(bool (*cmp)(const Val_t&, const Val_t&));
    int find(const Val_t& val);
    bool is_belongs(const Val_t& val);
};
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
void List<Val_t>::_append_ptr(Node_sptr<Val_t> ptr)
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
void List<Val_t>::_appfront_ptr(Node_sptr<Val_t> ptr)
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
        ptr->set_next(head);
        head = ptr;
        len++;
    }
}

template <typename Val_t>
void List<Val_t>::_append(const Val_t& val)
{
    Node_sptr<Val_t> temp_ptr = _alloc_node(val);
    _append_ptr(temp_ptr);
}
template <typename Val_t>
void List<Val_t>::_appfront(const Val_t& val)
{
    Node_sptr<Val_t> temp_ptr = _alloc_node(val);
    _appfront_ptr(temp_ptr);
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
        throw err::ListCorrupted(__FILE__, __LINE__-1, "len isn't = real size");
    return temp_ptr;
}


template <typename Val_t>
Val_t& List<Val_t>::_get_i(size_t i)
{
    Node_sptr<Val_t> ptr = _get_ptr(i);
    return ptr->get_val();
}
template <typename Val_t>
Val_t& List<Val_t>::_get_i(int i)
{
    size_t convert_i = _convert_index(i);
    Node_sptr<Val_t> ptr = _get_ptr(convert_i);
    return ptr->get_val();
}
template <typename Val_t>
const Val_t& List<Val_t>::_get_i(size_t i) const
{
    Node_sptr<Val_t> ptr = _get_ptr(i);
    return ptr->get_val();
}
template <typename Val_t>
const Val_t& List<Val_t>::_get_i(int i) const
{
    size_t convert_i = _convert_index(i);
    Node_sptr<Val_t> ptr = _get_ptr(convert_i);
    return ptr->get_val();
}

template <typename Val_t>
void List<Val_t>::_append_list(const List<Val_t>& other)
{
    for (Val_t val : other)
        _append(val);
}
template <typename Val_t>
void List<Val_t>::_append_array(Val_t arr[], size_t _len)
{
    for (size_t i; i<_len; i++)
        _append(arr[i]);
}
template <typename Val_t>
void List<Val_t>::_append_init_list(std::initializer_list<Val_t> lst)
{
    for (Val_t val : lst)
        _append(val);
}

template <typename Val_t>
void List<Val_t>::_insert_ptr(size_t i, Node_sptr<Val_t> ptr)
{
    if (i > len)
        throw err::Index(__FILE__, __LINE__-1, i);
    if (i == 0 || i == len)
        throw err::ListCorrupted(__FILE__, __LINE__-1,
                                 "function can't be call for such index");
    Node_sptr<Val_t> pre_ptr = _get_ptr(i-1);
    Node_sptr<Val_t> post_ptr = _get_ptr(i);
    pre_ptr->set_next(ptr);
    ptr->set_next(post_ptr);
    len++;
}
template <typename Val_t>
void List<Val_t>::_insert(size_t i, const Val_t &val)
{
    if (i > len)
        throw err::Index(__FILE__, __LINE__-1, i);

    Node_sptr<Val_t> temp_ptr = _alloc_node(val);

    if (i == 0)             _appfront_ptr(temp_ptr);
    else if (i == len)      _append_ptr(temp_ptr);
    else                    _insert_ptr(i, temp_ptr);
}

template <typename Val_t>
bool List<Val_t>::_is_equal(const Val_t& val) const
{
    if (len != 1)   return false;
    return head->get_val() == val;
}
template <typename Val_t>
bool List<Val_t>::_is_equal(const List<Val_t>& other) const
{
    if (len != other.get_len()) return false;

    ListIterator<Val_t> iter = this->begin();
    for (Val_t val : other)
    {
        if ((*iter) != val) return false;
        iter++;
    }
    if (!iter.is_end())
        throw err::ListCorrupted(__FILE__, __LINE__-1, "len isn't = real size");
    return true;
}
template <typename Val_t>
bool List<Val_t>::_is_equal(Val_t arr[], size_t len_) const
{
    if (len != len_)    return false;

    for (size_t i=0; i<len; i++)
        if (get_i(i) != arr[i]) return false;
    return true;
}
template <typename Val_t>
bool List<Val_t>::_is_equal(std::initializer_list<Val_t> lst) const
{
    if (len != lst.size()) return false;

    ListIterator<Val_t> iter = this->begin();
    for (Val_t val : lst)
    {
        if ((*iter) != val) return false;
        iter++;
    }
    if (!iter.is_end())
        throw err::ListCorrupted(__FILE__, __LINE__-1, "len isn't = real size");
    return true;
}

///
/// public:
///
//
// Constructors, setters
//
template <typename Val_t>
List<Val_t>::List(const List<Val_t>& other)
{
    _append_list(other);
}
template <typename Val_t>
List<Val_t>::List(Val_t arr[], size_t _len)
{
    _append_array(arr, _len);
}
template <typename Val_t>
List<Val_t>::List(std::initializer_list<Val_t> lst)
{
    _append_init_list(lst);
}

template <typename Val_t>
List<Val_t>& List<Val_t>::operator=(const Val_t& val)
{
    if (!is_empty()) clear();
    _append(val);
    return (*this);
}
template <typename Val_t>
List<Val_t>& List<Val_t>::operator=(const List<Val_t>& other)
{
    if (!is_empty()) clear();
    _append_list(other);
    return (*this);
}
template <typename Val_t>
List<Val_t>& List<Val_t>::operator=(std::initializer_list<Val_t> lst)
{
    if (!is_empty()) clear();
    _append_init_list(lst);
    return (*this);
}

template <typename Val_t>
void List<Val_t>::set(const Val_t& val)
{
    if (!is_empty()) clear();
    _append(val);
}
template <typename Val_t>
void List<Val_t>::set(const List<Val_t>& other)
{
    if (!is_empty()) clear();
    _append_list(other);
}
template <typename Val_t>
void List<Val_t>::set(std::initializer_list<Val_t> lst)
{
    if (!is_empty()) clear();
    _append_init_list(lst);
}
template <typename Val_t>
void List<Val_t>::set(Val_t arr[], size_t len_)
{
    if (!is_empty()) clear();
    _append_array(arr, len_);
}

template <typename Val_t>
void List<Val_t>::set_i(const Val_t& val, size_t i)
{
    get_i(i) = val;
}
template <typename Val_t>
void List<Val_t>::set_i(const Val_t& val, int i)
{
    get_i(i) = val;
}



//
// Getters
//
template <typename Val_t>
Val_t& List<Val_t>::operator[](size_t i)
{
    return _get_i(i);
}
template <typename Val_t>
Val_t& List<Val_t>::operator[](int i)
{
    return _get_i(i);
}
template <typename Val_t>
const Val_t& List<Val_t>::operator[](size_t i) const
{
    return _get_i(i);
}
template <typename Val_t>
const Val_t& List<Val_t>::operator[](int i) const
{
    return _get_i(i);
}

template <typename Val_t>
Val_t& List<Val_t>::get_i(size_t i)
{
    return _get_i(i);
}
template <typename Val_t>
Val_t& List<Val_t>::get_i(int i)
{
    return _get_i(i);
}
template <typename Val_t>
const Val_t& List<Val_t>::get_i(size_t i) const
{
    return _get_i(i);
}
template <typename Val_t>
const Val_t& List<Val_t>::get_i(int i) const
{
    return _get_i(i);
}

template <typename Val_t>
Val_t* List<Val_t>::get_arr()
{
    if (!len)   return nullptr;
    Val_t *arr = new Val_t[len];
    for (size_t i=0; i<len; i++)
        arr[i] = get_i(i);
    return arr;
}



//
// Adders
//
template <typename Val_t>
List<Val_t>& List<Val_t>::operator+=(const Val_t& val)
{
    _append(val);
    return (*this);
}
template <typename Val_t>
List<Val_t>& List<Val_t>::operator+=(const List<Val_t>& other)
{
    _append_list(other);
    return (*this);
}
template <typename Val_t>
List<Val_t>& List<Val_t>::operator+=(std::initializer_list<Val_t> lst)
{
    _append_init_list(lst);
    return (*this);
}

template <typename Val_t>
void List<Val_t>::append(const Val_t& val)
{
    _append(val);
}
template <typename Val_t>
void List<Val_t>::append(const List<Val_t>& other)
{
    _append_list(other);
}
template <typename Val_t>
void List<Val_t>::append(std::initializer_list<Val_t> lst)
{
    _append_init_list(lst);
}
template <typename Val_t>
void List<Val_t>::append(Val_t arr[], size_t len_)
{
    _append_array(arr, len_);
}

template <typename Val_t>
void List<Val_t>::appfront(const Val_t& val)
{
    _appfront(val);
}
template <typename Val_t>
void List<Val_t>::appfront(const List<Val_t>& other)
{
    for (size_t j=0; j<other.get_len(); j++)
        _insert(j, other[j]);
}
template <typename Val_t>
void List<Val_t>::appfront(std::initializer_list<Val_t> lst)
{
    size_t j = 0;
    for (Val_t val : lst)
    {
        _insert(j, val);
        j++;
    }
}
template <typename Val_t>
void List<Val_t>::appfront(Val_t arr[], size_t len_)
{
    for (size_t j=0; j<len_; j++)
        _insert(j, arr[j]);
}



//
// Inserters
//
template <typename Val_t>
void List<Val_t>::insert(size_t i, const Val_t& val)
{
    _insert(i, val);
}
template <typename Val_t>
void List<Val_t>::insert(size_t i, const List<Val_t>& other)
{
    for (size_t j=0; j<other.get_len(); j++)
        _insert(i+j, other[j]);
}
template <typename Val_t>
void List<Val_t>::insert(size_t i, std::initializer_list<Val_t> lst)
{
    size_t j = 0;
    for (Val_t val : lst)
    {
        _insert(i+j, val);
        j++;
    }
}
template <typename Val_t>
void List<Val_t>::insert(size_t i, Val_t arr[], size_t len_)
{
    for (size_t j=0; j<len_; j++)
        _insert(i+j, arr[j]);
}


//
// Deleters, popers
//
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
        throw err::Index(__FILE__, __LINE__-3, i);


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



//
// Comparators
//
/// Equal
template <typename Val_t>
bool List<Val_t>::operator==(const Val_t& val) const
{
    return _is_equal(val);
}
template <typename Val_t>
bool List<Val_t>::operator==(const List<Val_t>& other) const
{
    return _is_equal(other);
}
template <typename Val_t>
bool List<Val_t>::operator==(std::initializer_list<Val_t> lst) const
{
    return _is_equal(lst);
}

template <typename Val_t>
bool List<Val_t>::is_equal(const Val_t& val) const
{
    return _is_equal(val);
}
template <typename Val_t>
bool List<Val_t>::is_equal(const List<Val_t>& other) const
{
    return _is_equal(other);
}
template <typename Val_t>
bool List<Val_t>::is_equal(Val_t arr[], int len_) const
{
    return _is_equal(arr, len_);
}
template <typename Val_t>
bool List<Val_t>::is_equal(std::initializer_list<Val_t> lst) const
{
    return _is_equal(lst);
}


/// Not equal
template <typename Val_t>
bool List<Val_t>::operator!=(const Val_t& val) const
{
    return not _is_equal(val);
}
template <typename Val_t>
bool List<Val_t>::operator!=(const List<Val_t>& other) const
{
    return not _is_equal(other);
}
template <typename Val_t>
bool List<Val_t>::operator!=(std::initializer_list<Val_t> lst) const
{
    return not _is_equal(lst);
}

template <typename Val_t>
bool List<Val_t>::isnt_equal(const Val_t& val) const
{
    return not _is_equal(val);
}
template <typename Val_t>
bool List<Val_t>::isnt_equal(const List<Val_t>& other) const
{
    return not _is_equal(other);
}
template <typename Val_t>
bool List<Val_t>::isnt_equal(Val_t arr[], size_t len_) const
{
    return not _is_equal(arr, len_);
}
template <typename Val_t>
bool List<Val_t>::isnt_equal(std::initializer_list<Val_t> lst) const
{
    return _is_equal(lst);
}



//
// Order functions
//
template <typename Val_t>
void List<Val_t>::swap(size_t i1, size_t i2)
{

}
template <typename Val_t>
void List<Val_t>::reverse()
{

}
template <typename Val_t>
void List<Val_t>::sort(bool is_rev)
{

}
template <typename Val_t>
void List<Val_t>::sort(bool (*cmp)(const Val_t&, const Val_t&))
{

}



//
// Other apply functions
//
template <typename Val_t>
void List<Val_t>::print() const
{
    if (is_empty())
    {
        cout << "Empty list";
        return;
    }

    ConstListIterator<Val_t> iter = this->begin();
    ConstListIterator<Val_t> end = this->end();

    cout << "[" << (*iter) << "]";
    iter++;
    while (iter != end)
    {
        cout << " -> [" << (*iter) << "]";
        iter++;
    }
}
template <typename Val_t>
int List<Val_t>::find(const Val_t& val)
{

}
template <typename Val_t>
bool List<Val_t>::is_belongs(const Val_t& val)
{

}


#endif // LIST_H
