#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Vec3.h"
#include "Vec2.h"
#include "Triangle.h"
#include "Material.h"
#include "Logger.h"

class Mesh
{
 public:
    void importObj(const std::string url);
    void draw();
 private:
    std::vector<Triangle> m_triangles;
};

#endif
