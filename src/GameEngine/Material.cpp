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
