#include "change_camera.h"

using namespace command;

ChangeCamera::ChangeCamera(size_t index): _index(index) {}
ChangeCamera::~ChangeCamera() {}
void ChangeCamera::execute(weak_ptr<BaseScene> scene)
{
    CameraManager(scene, _index).execute();
}
