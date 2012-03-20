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

#include "Vec2.h"

Vec2::Vec2() : _x(0.0f), _y(0.0f) {}

Vec2::Vec2(float x, float y) : _x(x), _y(y) {}

//SET

void Vec2::setX(float x)
{
    _x = x;
}

void Vec2::setY(float y)
{
    _y = y;
}

//GET

float Vec2::getX()
{
    return _x;
}

float Vec2::getY()
{
    return _y;
}

float Vec2::operator[](unsigned char a)
{
    if(a == '0')
	return _x;
    else if(a == '1')
	return _y;
}
