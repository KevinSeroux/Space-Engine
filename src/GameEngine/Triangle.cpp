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

#include "Triangle.h"

Triangle::Triangle() {}

Triangle::Triangle(Vertex &vertex1, Vertex &vertex2, Vertex &vertex3, const unsigned char &materialID)
{
    _vertex1 = vertex1;
    _vertex2 = vertex2;
    _vertex3 = vertex3;
    _materialID = materialID;
}

//SET

void Triangle::setVertex1(Vertex &vertex1)
{
    _vertex1 = vertex1;
}

void Triangle::setVertex2(Vertex &vertex2)
{
    _vertex2 = vertex2;
}

void Triangle::setVertex3(Vertex &vertex3)
{
    _vertex3 = vertex3;
}

void Triangle::setMaterialID(const unsigned char &materialID)
{
    _materialID = materialID;
}

//GET

Vertex& Triangle::getVertex1()
{
    return _vertex1;
}

Vertex& Triangle::getVertex2()
{
    return _vertex2;
}

Vertex& Triangle::getVertex3()
{
    return _vertex3;
}

const unsigned char Triangle::getMaterialID()
{
    return _materialID;
}
