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
public:
    List() = default;
    explicit List(const List<Val_t>&);
    List(List<Val_t>&&);
    List(Val_t arr[], size_t _len);
    List(const ListIterator<Val_t>& begin_, const ListIterator<Val_t>& end_);
    List(const ConstListIterator<Val_t>& begin_, const ConstListIterator<Val_t>& end_);
    explicit List(std::initializer_list<Val_t>);

    virtual ~List() = default;

    ListIterator<Val_t> begin() {return ListIterator<Val_t>(head);}
    ListIterator<Val_t> end() {return ListIterator<Val_t>(nullptr);}
    ConstListIterator<Val_t> begin() const {return ConstListIterator<Val_t>(head);}
    ConstListIterator<Val_t> end() const {return ConstListIterator<Val_t>(nullptr);}

    ConstListIterator<Val_t> c_begin() const {return ConstListIterator<Val_t>(head);}
    ConstListIterator<Val_t> c_end() const {return ConstListIterator<Val_t>(nullptr);}

    /// Getters
    Val_t* get_arr();

    /// Setters
    List<Val_t>& operator=(const Val_t& val);
    List<Val_t>& operator=(const List<Val_t>& other);
    List<Val_t>& operator=(std::initializer_list<Val_t> lst);

    /// Adders
    List<Val_t> operator+(const Val_t& val) const;
    List<Val_t> operator+(const List<Val_t>& other) const;
    //
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
    void insert(ListIterator<Val_t>& iter, const Val_t& val);
    void insert(ListIterator<Val_t>& iter, const List<Val_t>& other);
    void insert(ListIterator<Val_t>& iter, std::initializer_list<Val_t> lst);
    void insert(ListIterator<Val_t>& iter, Val_t arr[], size_t len_);

    /// Deleters
    void clear();
    Val_t popfront();
    Val_t popend();
    Val_t remove(ListIterator<Val_t>& iter);

    /// Comparators
    /// Equal
    bool operator==(const Val_t& val) const;
    bool operator==(const List<Val_t>& other) const;
    //
    bool is_equal(const Val_t&) const;
    bool is_equal(const List<Val_t>& other) const;
    bool is_equal(std::initializer_list<Val_t> lst) const;
    bool is_equal(Val_t arr[], int len_) const;

    /// Not equal
    bool operator!=(const Val_t& val) const;
    bool operator!=(const List<Val_t>& other) const;
    //
    bool isnt_equal(const Val_t&) const;
    bool isnt_equal(const List<Val_t>& other) const;
    bool isnt_equal(std::initializer_list<Val_t> lst) const;
    bool isnt_equal(Val_t arr[], size_t len_) const;

    void swap(ListIterator<Val_t>& iter1, ListIterator<Val_t>& iter2);
    ListIterator<Val_t> find(const Val_t& val);
    ConstListIterator<Val_t> find(const Val_t& val) const;
    bool is_belongs(const Val_t& val) const;

    friend ostream& operator<<(ostream &os, const List<Val_t>& lst)
    {
        lst._print();
        return os;
    }

protected:
    Val_t& operator[](size_t i);
    Val_t& operator[](int i);
    const Val_t& operator[](size_t i) const;
    const Val_t& operator[](int i) const;

private:
    Node_sptr<Val_t> head{nullptr};
    Node_sptr<Val_t> tail{nullptr};

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
    void _insert(ListIterator<Val_t>& iter, const Val_t& val);

    bool _is_equal(const Val_t& val) const;
    bool _is_equal(const List<Val_t>& other) const;
    bool _is_equal(Val_t arr[], size_t len_) const;
    bool _is_equal(std::initializer_list<Val_t> lst) const;

    void _print() const;
};

#ifndef LIST_HPP_EXERNAL
#include "list.hpp"
#endif // LIST_HPP_EXERNAL

#endif // LIST_H
