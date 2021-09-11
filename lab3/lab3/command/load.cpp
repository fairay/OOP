#include "load.h"

using namespace command;
Load::Load() {}
Load::~Load() {}
void Load::execute(weak_ptr<BaseScene> scene)
{
    LoadManager(scene, _director).execute();
}

using namespace CarcassBuilder;
LoadCarcass::LoadCarcass(string file_name)
{
    shared_ptr<BaseBuilder> bld(new TxtBuilder(file_name));
    _director = shared_ptr<BuildDirector>(new Director(bld));
}
LoadCarcass::~LoadCarcass() {}
