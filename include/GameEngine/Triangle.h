#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vertex.h"

class Triangle
{
 public:
    Triangle();
    Triangle(Vertex &vertex1, Vertex &vertex2, Vertex &vertex3, const unsigned char &materialID);
    //SET
    void setVertex1(Vertex &vertex1);
    void setVertex2(Vertex &vertex2);
    void setVertex3(Vertex &vertex3);
    void setMaterialID(const unsigned char &materialID);
    //GET
    Vertex& getVertex1();
    Vertex& getVertex2();
    Vertex& getVertex3();
    const unsigned char getMaterialID();
 private :
    Vertex _vertex1;
    Vertex _vertex2;
    Vertex _vertex3;
    unsigned char _materialID;
};

#endif
