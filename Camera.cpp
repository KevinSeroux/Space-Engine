#include "Camera.h"

Camera::Camera(Vec3 pos, Vec3 target)
{
    _pos = pos;
    _target = target;
}

void Camera::place()
{
    gluLookAt(_pos.getX(),_pos.getY(),_pos.getZ(),_target.getX(),_target.getY(),_target.getZ(),0,0,1);
}

//SET

void Camera::setPos(Vec3 pos)
{
    _pos = pos;
}

void Camera::setTarget(Vec3 target)
{
    _target = target;
}

//GET

Vec3 Camera::getPos()
{
    return _pos;
}

Vec3 Camera::getTarget()
{
    return _target;
}
