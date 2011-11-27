#ifndef OBJIMPORTER_H
#define OBJIMPORTER_H

#include <string>
#include "Vec2.h"
#include "Vec3.h"
#include "Vertex.h"
#include "Triangle.h"
#include "Material.h"
#include "Mesh.h"
#include "Logger.h"

class ObjImporter
{
 public:
    static Mesh importObj(std::string url);
};

#endif
