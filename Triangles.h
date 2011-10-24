#ifndef TRIANGLES_H
#define TRIANGLES_H

#include <GL/gl.h>
#include "Vertex.h"

class Triangles
{
 public:
    Triangles(const Vertex& vertex1, const Vertex& vertex2, const Vertex& vertex3);
    void Draw();
 private :
    Vertex *m_vertex1;
    Vertex *m_vertex2;
    Vertex *m_vertex3;
};

#endif
