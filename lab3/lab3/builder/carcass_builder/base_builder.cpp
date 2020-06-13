#include "base_builder.h"

using namespace CarcassBuilder;

BaseBuilder::BaseBuilder():
    _carcass(new Carcass()) {}

BaseBuilder::~BaseBuilder() {}

shared_ptr<SceneObject> BaseBuilder::get_object()
{
    return _carcass;
}
