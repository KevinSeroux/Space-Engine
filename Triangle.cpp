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
    glColor3ub(255,0,0);
    glVertex3f(m_vertex1.GetX(),m_vertex1.GetY(),m_vertex1.GetZ());
    glColor3ub(0,255,0);
    glVertex3f(m_vertex2.GetX(),m_vertex2.GetY(),m_vertex2.GetZ());
    glColor3ub(0,0,255);
    glVertex3f(m_vertex3.GetX(),m_vertex3.GetY(),m_vertex3.GetZ());;
    glEnd();
}
