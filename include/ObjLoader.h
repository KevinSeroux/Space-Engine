/*------------------------------------------------------------------------------
| Copyright (C) 2012 Seroux Kévin                                              |
|                                                                              |
| This program is free software; you can redistribute it and/or                |
| modify it under the terms of the GNU Lesser General Public                   |
| License as published by the Free Software Foundation; either                 |
| version 2.1 of the License, or (at your option) any later version.           |
|                                                                              |
| This program is distributed in the hope that it will be useful,              |
| but WITHOUT ANY WARRANTY; without even the implied warranty of               |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU             |
| Lesser General Public License for more details.                              |
|                                                                              |
| You should have received a copy of the GNU Lesser General Public             |
| License along with this program; if not, write to the Free Software          |
| Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA |
------------------------------------------------------------------------------*/

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
    Mesh* load(std::string& file);
private:
    std::ifstream _objStream;
    std::ifstream _mtlStream;
    unsigned char _lastMtl;
    std::vector<Vec3> _vertices;
    std::vector<Vec3> _normals;
    std::vector<Vec2> _textures;
    std::vector<Triangle> _triangles;
};

#endif
