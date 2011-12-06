#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vertex.h"
#include "Material.h"

class Triangle
{
 public:
    Triangle();
    Triangle(Vertex *vertex1, Vertex *vertex2, Vertex *vertex3, Material *material);
    //OPERATOR
    Triangle* operator=(Triangle *triangle);
    //SET
    void setVertex1(Vertex *vertex1);
    void setVertex2(Vertex *vertex2);
    void setVertex3(Vertex *vertex3);
    void setMaterial(Material *material);
    //GET
    Vertex* getVertex1();
    Vertex* getVertex2();
    Vertex* getVertex3();
    Material* getMaterial();
 private :
    Vertex *_vertex1;
    Vertex *_vertex2;
    Vertex *_vertex3;
    Material *_material;
};

#endif
