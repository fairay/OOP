#ifndef ERRORS_H
#define ERRORS_H

#include <exception>
#include <cstring>
#include <iostream>

using namespace std;
namespace err {

    class ListError: exception
    {
    public:
        ListError(const string file_, long line_n_);
        virtual ~ListError() override;
        virtual const char* what() const noexcept override;
    protected:
        char* err_msg;
        void fill_msg();
        string type = "";
        string add_info = "";
    private:
        string file;
        string line_n;
        string err_time;

        string cur_time();
        string base_msg();
        string add_msg();
    };


    class Index: public ListError
    {
    public:
        Index(const string file_, long line_n_, int index);
        Index(const string file_, long line_n_, size_t index);
        virtual ~Index();
    };

    class NullNode: public ListError
    {
    public:
        NullNode(const string file_, long line_n_);
        virtual ~NullNode();
    };

    class WrongSize: public ListError
    {
    public:
        WrongSize(const string file_, long line_n_,
                int size);
        virtual ~WrongSize();
    };

    class EmptyList: public ListError
    {
    public:
        EmptyList(const string file_, long line_n_);
        virtual ~EmptyList();
    };

    class AllocFailed: public ListError
    {
    public:
        AllocFailed(const string file_, long line_n_);
        virtual ~AllocFailed();
    };

    class ListCorrupted: public ListError
    {
    public:
        ListCorrupted(const string file_, long line_n_,
                      const string reason);
        virtual ~ListCorrupted();
    };
}
#endif // ERRORS_H
