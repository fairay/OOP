#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <cstring>
#include <iostream>

using namespace std;
namespace err {

    class List: exception
    {
    private:
        string file;
        string line_n;
        string err_time;

        string cur_time();
        string base_msg();
        string add_msg();
    protected:
        char* err_msg;
        void fill_msg();
        string type = "";
        string add_info = "";
    public:
        List(const string file_, long line_n_);
        virtual ~List() override;
        virtual const char* what() const noexcept override;
    };


    class Index: public List
    {
    public:
        Index(const string file_, long line_n_, int index);
        Index(const string file_, long line_n_, size_t index);
        virtual ~Index();
    };

    class NullNode: public List
    {
    public:
        NullNode(const string file_, long line_n_);
        virtual ~NullNode();
    };

    class WrongSize: public List
    {
    public:
        WrongSize(const string file_, long line_n_,
                int size);
        virtual ~WrongSize();
    };

    class EmptyList: public List
    {
    public:
        EmptyList(const string file_, long line_n_);
        virtual ~EmptyList();
    };

    class AllocFailed: public List
    {
    public:
        AllocFailed(const string file_, long line_n_);
        virtual ~AllocFailed();
    };

    class ListCorrupted: public List
    {
    public:
        ListCorrupted(const string file_, long line_n_,
                      const string reason);
        virtual ~ListCorrupted();
    };
}
#endif // ERRORS_H
