#include "remove_object.h"

using namespace command;

RemoveObject::RemoveObject(size_t index): _index(index) {}
RemoveObject::~RemoveObject() {}
void RemoveObject::execute(weak_ptr<BaseScene> scene)
{
    RemoveManager(scene, _index).execute();
}
