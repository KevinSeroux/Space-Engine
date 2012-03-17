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

#ifndef VERTEX_H
#define VERTEX_H

#include "Vec3.h"
#include "Vec2.h"

class Vertex
{
 public:
    Vertex();
    Vertex(Vec3 &vertexCoords, Vec3 &normalCoords, Vec2 &textureCoords);
    Vertex(Vec3 &vertexCoords, Vec3 &normalCoords);
    Vertex(Vec3 &vertexCoords);
    //SET
    void setVertexCoords(Vec3 &vertexCoords);
    void setTextureCoords(Vec2 &textureCoords);
    void setNormalCoords(Vec3 &normalCoords);
    //GET
    Vec3& getVertexCoords();
    Vec2& getTextureCoords();
    Vec3& getNormalCoords();

 private:
    Vec3 _vertexCoords;
    Vec2 _textureCoords;
    Vec3 _normalCoords;
};

#endif
