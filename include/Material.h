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

#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "Vec3.h"

class Material
{
public:
    Material(std::string &name);
    void setName(std::string &name);
    void setDiffuseColor(Vec3 &diffuseColor);
    void setAmbientColor(Vec3 &ambientColor);
    void setSpecularColor(Vec3 &specularColor);
    void setShininess(float &shininess);
    void setBlend(float &blend);
    void setTextureURL(std::string &textureURL);

    std::string& getName();
    Vec3& getDiffuseColor();
    Vec3& getAmbientColor();
    Vec3& getSpecularColor();
    float& getShininess();
    float& getBlend();
    std::string& getTextureURL();

private:
    std::string _name;
    Vec3 _diffuseColor;
    Vec3 _ambientColor;
    Vec3 _specularColor;
    float _shininess;
    float _blend;
    std::string _textureURL;
};

#endif
