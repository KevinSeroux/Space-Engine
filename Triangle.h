#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL/gl.h>
#include "Vertex.h"
#include "Material.h"

class Triangle
{
 public:
    Triangle();
    Triangle(Vertex vertex1, Vertex vertex2, Vertex vertex3, Material material);
    //GET
    Vertex getVertex1();
    Vertex getVertex2();
    Vertex getVertex3();
    Material getMaterial();
    //SET
    void setVertex1(Vertex vertex1);
    void setVertex2(Vertex vertex2);
    void setVertex3(Vertex vertex3);
    void setMaterial(Material material);
 private :
    Vertex m_vertex1;
    Vertex m_vertex2;
    Vertex m_vertex3;
    Material m_material;
};

#endif
