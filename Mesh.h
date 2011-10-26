#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>
#include <fstream>
#include "Vertex.h"
#include "Triangle.h"
#include "Logger.h"

class Mesh
{
 public:
    void AddTriangle(Triangle triangle);
    void ImportObj(const std::string url);
    void Draw();
 private:
    std::vector<Triangle> m_triangles;
};

#endif
