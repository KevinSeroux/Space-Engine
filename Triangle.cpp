#include "Triangle.h"

Triangle::Triangle() {}

Triangle::Triangle(Vertex *vertex1, Vertex *vertex2, Vertex *vertex3, Material *material)
{
    _vertex1 = vertex1;
    _vertex2 = vertex2;
    _vertex3 = vertex3;
    _material = material;
}

//SET

void Triangle::setVertex1(Vertex *vertex1)
{
    _vertex1 = vertex1;
}

void Triangle::setVertex2(Vertex *vertex2)
{
    _vertex2 = vertex2;
}

void Triangle::setVertex3(Vertex *vertex3)
{
    _vertex3 = vertex3;
}

void Triangle::setMaterial(Material *material)
{
    _material = material;
}

//GET

Vertex* Triangle::getVertex1()
{
    return _vertex1;
}

Vertex* Triangle::getVertex2()
{
    return _vertex2;
}

Vertex* Triangle::getVertex3()
{
    return _vertex3;
}

Material* Triangle::getMaterial()
{
    return _material;
}
