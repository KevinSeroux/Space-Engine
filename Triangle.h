#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <GL/gl.h>
#include <vector>
#include "Vertex.h"

class Triangle
{
 public:
    Triangle(Vertex& vertex1, Vertex& vertex2, Vertex& vertex3);
    std::vector<Vertex> GetVertices();
    void Draw();
    void Print();
 private :
    Vertex m_vertex1;
    Vertex m_vertex2;
    Vertex m_vertex3;
};

#endif
