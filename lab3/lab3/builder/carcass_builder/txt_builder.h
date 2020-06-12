#ifndef TXT_BUILDER_H
#define TXT_BUILDER_H

#include "base_builder.h"
#include <fstream>

namespace CarcassBuilder {

class TxtBuilder: public CarcassBuilder::BaseBuilder
{
public:
    TxtBuilder(string f_name);
    virtual ~TxtBuilder();

    virtual void open();
    virtual void load_nodes();
    virtual void load_edges();
    virtual void close();

private:
    string _filename;
    ifstream _file;
    Array<Point> _p_arr;

    void _load_node();
    void _load_edge();
};

} // CarcassBuilder

#endif // TXT_BUILDER_H
