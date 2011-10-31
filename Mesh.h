#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>
#include <fstream>
#include "Vec3.h"
#include "Vec2.h"
#include "Triangle.h"
#include "Material.h"
#include "Logger.h"

class Mesh
{
 public:
    void ImportObj(const std::string url);
    void Draw();
 private:
    std::vector<Triangle> m_triangles;
    std::vector<Material> m_materials;
    std::vector<Vec3> m_normals;
    std::vector<Vec2> m_textureCoords;
};

#endif
