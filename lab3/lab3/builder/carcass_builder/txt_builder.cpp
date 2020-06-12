#include "txt_builder.h"

using namespace CarcassBuilder;

TxtBuilder::TxtBuilder(string f_name):
    _filename(f_name) {}

TxtBuilder::~TxtBuilder()
{
    if (_file.is_open())
        close();
}

void TxtBuilder::open()
{
    if (_file.is_open()) close();

    _file.open(_filename);

    if (!_file)
        throw err::FileOpenFail(__FILE__, __LINE__-3, _filename);
}

void TxtBuilder::close()
{
    if (_file.is_open())
        _file.close();
}

void TxtBuilder::load_nodes()
{
    if (!_file.is_open()) throw err::FileNotOpen(__FILE__, __LINE__-1);
    size_t count;
    _file >> count;
    if (count<2)
        throw err::WrongNodeCount(__FILE__, __LINE__-1);
    for (size_t i=0; i<count; i++)
        _load_node();
}

void TxtBuilder::load_edges()
{
    if (!_file.is_open()) throw err::FileNotOpen(__FILE__, __LINE__-1);
    size_t count;
    _file >> count;

    if (count<1)
        throw err::WrongNodeCount(__FILE__, __LINE__-1);

    for (size_t i=0; i<count; i++)
        _load_edge();
}


void TxtBuilder::_load_node()
{
    double x, y, z;
    _file >> x >> y >> z;
    _carcass->add_object(Point(x, y, z));
    _p_arr.append(Point(x, y, z));
}

void TxtBuilder::_load_edge()
{
    size_t i1, i2;
    _file >> i1 >> i2;

    if (i1 >= _p_arr.get_size())
        throw err::NodeOutOfRange(__FILE__, __LINE__-1, i1);
    if (i1 >= _p_arr.get_size())
        throw err::NodeOutOfRange(__FILE__, __LINE__-1, i1);

    _carcass->add_object(Edge(_p_arr[i1], _p_arr[i2]));
}
