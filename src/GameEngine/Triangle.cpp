#include "Triangle.h"

Triangle::Triangle() {}

Triangle::Triangle(Vertex &vertex1, Vertex &vertex2, Vertex &vertex3, const unsigned char &materialID)
{
    _vertex1 = vertex1;
    _vertex2 = vertex2;
    _vertex3 = vertex3;
    _materialID = materialID;
}

//SET

void Triangle::setVertex1(Vertex &vertex1)
{
    _vertex1 = vertex1;
}

void Triangle::setVertex2(Vertex &vertex2)
{
    _vertex2 = vertex2;
}

void Triangle::setVertex3(Vertex &vertex3)
{
    _vertex3 = vertex3;
}

void Triangle::setMaterialID(const unsigned char &materialID)
{
    _materialID = materialID;
}

//GET

Vertex& Triangle::getVertex1()
{
    return _vertex1;
}

Vertex& Triangle::getVertex2()
{
    return _vertex2;
}

Vertex& Triangle::getVertex3()
{
    return _vertex3;
}

const unsigned char Triangle::getMaterialID()
{
    return _materialID;
}
