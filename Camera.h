#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glu.h>
#include "Vec3.h"

class Camera
{
 public:
    Camera(Vec3 pos, Vec3 target);
    void place();
    void setPos(Vec3 xPos);
    void setTarget(Vec3 target);
    Vec3 getPos();
    Vec3 getTarget();
 private:
    Vec3 _pos;
    Vec3 _target;
};

#endif
