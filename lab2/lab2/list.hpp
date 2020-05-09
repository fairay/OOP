#ifndef LIST_HPP
#define LIST_HPP
#define LIST_HPP_EXERNAL

#include "list.h"

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
void List<Val_t>::_insert(ListIterator<Val_t>& iter, const Val_t &val)
{
    if (iter.is_end())
    {
        _append(val);
        iter = ListIterator<Val_t>(tail);
    }
    else
    {
        Node_sptr<Val_t> ptr = iter._get_node_ptr();
        Val_t old_val = *iter;

        Node_sptr<Val_t> new_ptr = _alloc_node(old_val);
        if (ptr->is_last())
            tail = new_ptr;
        new_ptr->set_next(ptr->get_next());
        ptr->set_next(new_ptr);

        (*iter) = val;
        len++;
    }
}

template <typename Val_t>
bool List<Val_t>::_is_equal(const Val_t& val) const
{
    if (len != 1)   return false;
    return _get_i(0) == val;
}
template <typename Val_t>
bool List<Val_t>::_is_equal(const List<Val_t>& other) const
{
    if (len != other.get_len()) return false;

    ConstListIterator<Val_t> iter = this->begin();
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
        if (_get_i(i) != arr[i]) return false;
    return true;
}
template <typename Val_t>
bool List<Val_t>::_is_equal(std::initializer_list<Val_t> lst) const
{
    if (len != lst.size()) return false;

    ConstListIterator<Val_t> iter = this->begin();
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
List<Val_t>::List(List<Val_t>&& other)
{
    _append_list(other);
    other.clear();
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
List<Val_t>::List(const ListIterator<Val_t>& begin_, const ListIterator<Val_t>& end_)
{
    ListIterator<Val_t> temp_iter(begin_);
    while (end_ != temp_iter)
    {
        _append(*temp_iter);
        ++temp_iter;
    }
}
template <typename Val_t>
List<Val_t>::List(const ConstListIterator<Val_t>& begin_, const ConstListIterator<Val_t>& end_)
{
    ConstListIterator<Val_t> temp_iter(begin_);
    while (end_ != temp_iter)
    {
        _append(*temp_iter);
        ++temp_iter;
    }
}

/*
template <typename Val_t>
List<Val_t>::List(iterator<input_iterator_tag, Val_t> begin_,
                  iterator<input_iterator_tag, Val_t> end_)
{
    std::iterator<std::input_iterator_tag, Val_t> temp_iter(begin_);
    temp_iter = begin_;
    while (end_ != temp_iter)
    {
        _append(*temp_iter);
        ++temp_iter;
    }
}
*/



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
Val_t* List<Val_t>::get_arr()
{
    if (!len)   return nullptr;
    Val_t *arr = new Val_t[len];
    for (size_t i=0; i<len; i++)
        arr[i] = _get_i(i);
    return arr;
}



//
// Adders
//
template <typename Val_t>
List<Val_t> List<Val_t>::operator+(const Val_t& val) const
{
    List<Val_t> new_lst(*this);
    new_lst += val;
    return new_lst;
}
template <typename Val_t>
List<Val_t> List<Val_t>::operator+(const List<Val_t>& other) const
{
    List<Val_t> new_lst(*this);
    new_lst += other;
    return new_lst;
}

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
void List<Val_t>::insert(ListIterator<Val_t>& iter, const Val_t& val)
{
    _insert(iter, val);
}
template <typename Val_t>
void List<Val_t>::insert(ListIterator<Val_t>& iter, const List<Val_t>& other)
{
    ListIterator<Val_t> temp_iter(iter);
    for (Val_t val : other)
    {
        _insert(temp_iter, val);
        temp_iter++;
    }
}
template <typename Val_t>
void List<Val_t>::insert(ListIterator<Val_t>& iter, std::initializer_list<Val_t> lst)
{
    ListIterator<Val_t> temp_iter(iter);
    for (Val_t val : lst)
    {
        _insert(temp_iter, val);
        temp_iter++;
    }
}
template <typename Val_t>
void List<Val_t>::insert(ListIterator<Val_t>& iter, Val_t arr[], size_t len_)
{
    ListIterator<Val_t> temp_iter(iter);
    for (size_t j=0; j<len_; j++)
    {
        _insert(temp_iter, arr[j]);
        temp_iter++;
    }
}



/*
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
*/
// Deleters, popers
//
template <typename Val_t>
Val_t List<Val_t>::remove(ListIterator<Val_t>& iter)
{
    Node_sptr<Val_t> ptr = iter._get_node_ptr();
    if (ptr->is_last())
    {
        iter++;
        return popend();
    }
    else if (iter == this->begin())
    {
        iter++;
        return popfront();
    }
    else
    {
        Val_t val = *iter;
        Node_sptr<Val_t> next_ptr = ptr->get_next();

        ptr->set_val(next_ptr->get_val());
        ptr->set_next(next_ptr->get_next());
        return val;
    }
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

/*
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
*/



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
void List<Val_t>::swap(ListIterator<Val_t>& iter1, ListIterator<Val_t>& iter2)
{
    if (iter1 == iter2)   return;
    Val_t temp = (*iter2);
    (*iter2) = (*iter1);
    (*iter1) = temp;
}
/*
template <typename Val_t>
void List<Val_t>::sort(bool is_rev)
{
    for (size_t i=0; i < len-1; i++)
        for (size_t j=0; j < len-i-1; j++)
            if (is_rev && (get_i(j) < get_i(j+1)))
                swap(j, j+1);
            else if (!is_rev && (get_i(j) > get_i(j+1)))
                swap(j, j+1);
}

template <typename Val_t>
void List<Val_t>::sort_cmp(bool (*cmp)(const Val_t &, const Val_t &))
{
    for (size_t i=0; i < len-1; i++)
        for (size_t j=0; j < len-i-1; j++)
            if (cmp(get_i(j), get_i(j+1)))
                swap(j, j+1);
}
*/


//
// Other apply functions
//
template <typename Val_t>
void List<Val_t>::_print() const
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
ListIterator<Val_t> List<Val_t>::find(const Val_t& val)
{
    ListIterator<Val_t> iter = begin();
    while (iter)
    {
        if ((*iter) == val)
            return iter;
        iter++;
    }
    return end();
}
template <typename Val_t>
ConstListIterator<Val_t> List<Val_t>::find(const Val_t& val) const
{
    ConstListIterator<Val_t> iter = begin();
    while (iter)
    {
        if ((*iter) == val)
            return iter;
        iter++;
    }
    return end();
}
template <typename Val_t>
bool List<Val_t>::is_belongs(const Val_t& val) const
{
    return find(val) != end();
}


#endif // LIST_HPP
