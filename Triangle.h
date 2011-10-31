#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL/gl.h>
#include "Vec3.h"
#include "Material.h"

class Triangle
{
 public:
    Triangle(Vec3& vertex1, Vec3& vertex2, Vec3& vertex3, Material& material);
    Vec3 GetVertex1();
    Vec3 GetVertex2();
    Vec3 GetVertex3();
    Material GetMaterial();
 private :
    Vec3 m_vertex1;
    Vec3 m_vertex2;
    Vec3 m_vertex3;
    Material m_material;
};

#endif
