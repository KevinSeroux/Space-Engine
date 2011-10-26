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


    glVertex3d(m_vertex1.GetX(),m_vertex1.GetY(),m_vertex1.GetZ());


    std::cout << std::endl << "DRAW V1 : " << m_vertex1.GetX();
    std::cout << "," << m_vertex1.GetY();
    std::cout << "," << m_vertex1.GetZ() << std::endl;

    glColor3ub(0,255,0);


    glVertex3d(m_vertex2.GetX(),m_vertex2.GetY(),m_vertex2.GetZ());


    std::cout << "DRAW V2 : " << m_vertex1.GetX();
    std::cout << "," << m_vertex2.GetY();
    std::cout << "," << m_vertex2.GetZ() << std::endl;

    glColor3ub(0,0,255);


    glVertex3d(m_vertex3.GetX(),m_vertex3.GetZ(),m_vertex3.GetZ());


    std::cout << "DRAW V3 : " << m_vertex1.GetX();
    std::cout << "," << m_vertex3.GetY();
    std::cout << "," << m_vertex3.GetZ() << std::endl;
    glEnd();
}

void Triangle::Print()
{
    //std::cout << "//Triangle :" << std::endl << "glColor3ub(255,0,0);" << std::endl;
    m_vertex1.Print();
    //std::cout << "glColor3ub(0,255,0);" << std::endl;
    m_vertex2.Print();
    //std::cout << "glColor3ub(0,0,255);" << std::endl;
    m_vertex3.Print();
}
