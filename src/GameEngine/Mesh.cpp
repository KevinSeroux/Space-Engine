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

#include "Mesh.h"

Mesh::Mesh(Triangle triangles[], unsigned int &countTriangles)
{
  _countTriangles = countTriangles;
  _triangles = new Triangle[countTriangles];
  for(unsigned int i(0); i < countTriangles; i++)
    {
      _triangles[i] = triangles[i];
    }
}

Mesh::Mesh(std::vector<Triangle>& triangles)
{
  _countTriangles = triangles.size();
  _triangles = new Triangle[_countTriangles];
  for(unsigned int i(0); i < _countTriangles; i++)
    {
      _triangles[i] = triangles[i];
    }
}

Mesh::~Mesh()
{
  delete[] _triangles;
  delete[] _vertices;
}

//GET

Triangle* Mesh::getTriangles()
{
    return _triangles;
}

const float* Mesh::getVertices()
{
  _vertices = new float[_countTriangles*3];
  unsigned int index(0);

  for(unsigned int i(0); i < _countTriangles; i++)
    {
      _vertices[index] = getTriangles()[i].getVertex1().getVertexCoords().getX();
      _vertices[index+1] = getTriangles()[i].getVertex1().getVertexCoords().getY();
      _vertices[index+2] = getTriangles()[i].getVertex1().getVertexCoords().getZ();

      _vertices[index+3] = getTriangles()[i].getVertex2().getVertexCoords().getX();
      _vertices[index+4] = getTriangles()[i].getVertex2().getVertexCoords().getY();
      _vertices[index+5] = getTriangles()[i].getVertex2().getVertexCoords().getZ();

      _vertices[index+6] = getTriangles()[i].getVertex3().getVertexCoords().getX();
      _vertices[index+7] = getTriangles()[i].getVertex3().getVertexCoords().getY();
      _vertices[index+8] = getTriangles()[i].getVertex3().getVertexCoords().getZ();

      index+=9;
    }

  return _vertices;
}

const unsigned int& Mesh::getCountTriangles()
{
  return _countTriangles;
}
