#include "director.h"

using namespace CarcassBuilder;
Director::Director(shared_ptr<BaseBuilder> bld):
    _builder(bld) {}
Director::~Director() {};

shared_ptr<SceneObject> Director::create()
{
    _builder->open();
    _builder->load_nodes();
    _builder->load_edges();
    _builder->close();
    return _builder->get_object();
}
