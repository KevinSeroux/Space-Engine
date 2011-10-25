#include "Triangle.h"

Triangle::Triangle(Vertex& vertex1, Vertex& vertex2, Vertex& vertex3)
{
    m_vertex1=vertex1;
    m_vertex2=vertex2;
    m_vertex3=vertex3;
}

void Triangle::Draw()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(255,255,255);
    glVertex3d(m_vertex1.GetX(),m_vertex1.GetY(),m_vertex1.GetZ());
    glVertex3d(m_vertex2.GetX(),m_vertex2.GetY(),m_vertex2.GetZ());
    glVertex3d(m_vertex3.GetX(),m_vertex3.GetZ(),m_vertex3.GetZ());
    glEnd();
}
