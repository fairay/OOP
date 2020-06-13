#ifndef TRANSFORMATOR_H
#define TRANSFORMATOR_H

#include "tranformation.h"
#include "memory"

using namespace std;
class Transformator
{
public:
    Transformator(Transformation* trans=nullptr): _trans(trans) {}
    ~Transformator() {}

    void set_trans(Transformation* trans)
    { _trans = unique_ptr<Transformation>(trans);}
    void transform(double& x, double& y, double& z)
    { _trans->execute(x, y, z); }
private:
    unique_ptr<Transformation> _trans;
};

#endif // TRANSFORMATOR_H
