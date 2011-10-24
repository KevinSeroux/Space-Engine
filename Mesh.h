#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Vertex.h"
#include "Triangles.h"
#include "ErrorManager.h"

class Mesh
{
 public:
    void AddVertices(const Vertex& vertex);
    void ImportObj(const std::string& url);
    void Draw();
 private:
    std::vector<Triangles> *m_triangles;
};

#endif
