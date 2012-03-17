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

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vertex.h"

class Triangle
{
 public:
    Triangle();
    Triangle(Vertex &vertex1, Vertex &vertex2, Vertex &vertex3, const unsigned char &materialID);
    //SET
    void setVertex1(Vertex &vertex1);
    void setVertex2(Vertex &vertex2);
    void setVertex3(Vertex &vertex3);
    void setMaterialID(const unsigned char &materialID);
    //GET
    Vertex& getVertex1();
    Vertex& getVertex2();
    Vertex& getVertex3();
    const unsigned char getMaterialID();
 private :
    Vertex _vertex1;
    Vertex _vertex2;
    Vertex _vertex3;
    unsigned char _materialID;
};

#endif
