#ifndef LOAD_H
#define LOAD_H

#include "base_command.h"
#include "builder/carcass_builder/director.h"
#include "builder/carcass_builder/txt_builder.h"

namespace command
{

class Load: public BaseCommand
{
public:
    Load();
    virtual ~Load() = 0;

    virtual void execute(weak_ptr<BaseScene> scene);
protected:
    shared_ptr<BuildDirector> _director;
};

class LoadCarcass: public Load
{
public:
    LoadCarcass(string file_name);
    virtual ~LoadCarcass();
};

} // command

#endif // LOAD_H
