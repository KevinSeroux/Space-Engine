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

#include "Vec3.h"

Vec3::Vec3() : _x(0.0f), _y(0.0f), _z(0.0f) {}

Vec3::Vec3(const float x, const float y, const float z) : _x(x), _y(y), _z(z) {}

//SET

void Vec3::setX(float x)
{
    _x = x;
}

void Vec3::setY(float y)
{
    _y = y;
}

void Vec3::setZ(float z)
{
    _z = z;
}

//GET

float Vec3::getX()
{
    return _x;
}

float Vec3::getY()
{
    return _y;
}

float Vec3::getZ()
{
    return _z;
}

float Vec3::operator[](unsigned char a)
{
  if(a == '0')
    return _x;
  else if(a == '1')
    return _y;
  else if(a == '2')
    return _z;
}
