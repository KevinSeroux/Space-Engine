#include "Triangle.h"

Triangle::Triangle() {}

Triangle::Triangle(Vertex vertex1, Vertex vertex2, Vertex vertex3, Material material)
{
    m_vertex1 = vertex1;
    m_vertex2 = vertex2;
    m_vertex3 = vertex3;
    m_material = material;
}

//GET

Vertex Triangle::getVertex1()
{
    return m_vertex1;
}

Vertex Triangle::getVertex2()
{
    return m_vertex2;
}

Vertex Triangle::getVertex3()
{
    return m_vertex3;
}

Material Triangle::getMaterial()
{
    return m_material;
}

//SET

void Triangle::setVertex1(Vertex vertex1)
{
    m_vertex1 = vertex1;
}

void Triangle::setVertex2(Vertex vertex2)
{
    m_vertex2 = vertex2;
}

void Triangle::setVertex3(Vertex vertex3)
{
    m_vertex3 = vertex3;
}

void Triangle::setMaterial(Material material)
{
    m_material = material;
}
