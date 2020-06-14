#include "object_visitor.h"

ObjectVisitor::ObjectVisitor() {}

ObjectVisitor::~ObjectVisitor() {}

void ObjectVisitor::set_ptr(shared_ptr<ObjectVisitor>& ptr)
{
    _this_ptr = ptr;
}
