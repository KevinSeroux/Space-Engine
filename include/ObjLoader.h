#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <string>
#include <fstream>
#include <cstdio>
#include <vector>
#include "Mesh.h"
#include "Vec3.h"
#include "Vec2.h"
#include "Triangle.h"

class Engine; //Protection againts circular inclusions

class ObjLoader
{
 public:
  Mesh& load(std::string& file);
 private:
  std::ifstream _objStream;
  std::ifstream _mtlStream;
  unsigned char _lastMtl;
  float _x;
  unsigned int _id[8];
  std::vector<Vec3> _vertices;
  std::vector<Vec3> _normals;
  std::vector<Vec2> _textures;
};

#endif
