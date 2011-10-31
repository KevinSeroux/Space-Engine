#include "Triangle.h"

Triangle::Triangle(Vec3& vertex1, Vec3& vertex2, Vec3& vertex3, Material& material)
{
    m_vertex1 = vertex1;
    m_vertex2 = vertex2;
    m_vertex3 = vertex3;
    m_material = material;
}

Vec3 Triangle::GetVertex1()
{
    return m_vertex1;
}

Vec3 Triangle::GetVertex2()
{
    return m_vertex2;
}

Vec3 Triangle::GetVertex3()
{
    return m_vertex3;
}

Material Triangle::GetMaterial()
{
    return m_material;
}
