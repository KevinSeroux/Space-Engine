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

#include "Material.h"

//SET

Material::Material(std::string &name)
{
  _name = name;
}

void Material::setName(std::string &name)
{
  _name = name;
}

void Material::setDiffuseColor(Vec3 &diffuseColor)
{
  _diffuseColor = diffuseColor;
}

void Material::setAmbientColor(Vec3 &ambientColor)
{
    _ambientColor = ambientColor;
}

void Material::setSpecularColor(Vec3 &specularColor)
{
    _specularColor = specularColor;
}

void Material::setShininess(float &shininess)
{
    _shininess = shininess;
}

void Material::setBlend(float &blend)
{
    _blend = blend;
}

void Material::setTextureURL(std::string &textureURL)
{
    _textureURL = textureURL;
}

//GET

std::string& Material::getName()
{
  return _name;
}

Vec3& Material::getDiffuseColor()
{
    return _diffuseColor;
}

Vec3& Material::getAmbientColor()
{
    return _ambientColor;
}

Vec3& Material::getSpecularColor()
{
    return _specularColor;
}

float& Material::getShininess()
{
    return _shininess;
}

float& Material::getBlend()
{
    return _blend;
}

std::string& Material::getTextureURL()
{
    return _textureURL;
}
