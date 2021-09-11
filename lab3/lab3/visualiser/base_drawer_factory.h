#ifndef BASE_DRAWER_FACTORY_H
#define BASE_DRAWER_FACTORY_H

#include "base_drawer.h"
#include "memory"

using namespace std;
class BaseDrawerFactory
{
public:
    BaseDrawerFactory();
    virtual ~BaseDrawerFactory() = 0;

    virtual BaseDrawer* create() = 0;
};

#endif // BASE_DRAWER_FACTORY_H
