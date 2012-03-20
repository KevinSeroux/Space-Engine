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

#include "Vertex.h"

Vertex::Vertex() {}

Vertex::Vertex(Vec3 &vertexCoords, Vec3 &normalCoords, Vec2 &textureCoords)
{
    _vertexCoords = vertexCoords;
    _textureCoords = textureCoords;
    _normalCoords = normalCoords;
}

Vertex::Vertex(Vec3 &vertexCoords, Vec3 &normalCoords)
{
    _vertexCoords = vertexCoords;
    _normalCoords = normalCoords;
}

Vertex::Vertex(Vec3 &vertexCoords)
{
    _vertexCoords = vertexCoords;
}

//SET

void Vertex::setVertexCoords(Vec3 &vertexCoords)
{
    _vertexCoords = vertexCoords;
}

void Vertex::setTextureCoords(Vec2 &textureCoords)
{
    _textureCoords = textureCoords;
}

void Vertex::setNormalCoords(Vec3 &normalCoords)
{
    _normalCoords = normalCoords;
}

//GET

Vec3& Vertex::getVertexCoords()
{
    return _vertexCoords;
}

Vec2& Vertex::getTextureCoords()
{
    return _textureCoords;
}

Vec3& Vertex::getNormalCoords()
{
    return _normalCoords;
}
