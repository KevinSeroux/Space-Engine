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

#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Triangle.h"
#include "Vec3.h"

class Mesh
{
public:
    Mesh(Triangle triangles[], unsigned int countTriangles);
    Mesh(std::vector<Triangle>& triangles);
    ~Mesh();
    //SET
    void setPosition(const Vec3& position);
    void setRotation(const Vec3& rotation);
    void setScale(const Vec3& scale);
    //GET
    Triangle* getTriangles() const;
    const float* getVertices();
    const unsigned int& getCountTriangles() const;
    const Vec3& getPosition() const;
    const Vec3& getRotation() const;
    const Vec3& getScale() const;
private:
    Triangle *_triangles;
    unsigned int _countTriangles;
    float *_vertices;
    Vec3 _position;
    Vec3 _rotation;
    Vec3 _scale;
};

#endif
