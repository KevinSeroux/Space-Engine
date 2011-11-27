#include "Material.h"

//SET

Material::Material(std::string name)
{
    _name = name;
}

Material::Material() {}

void Material::setDiffuseColor(Vec3 *diffuseColor)
{
    _diffuseColor = diffuseColor;
}

void Material::setAmbientColor(Vec3 *ambientColor)
{
    _ambientColor = ambientColor;
}

void Material::setSpecularColor(Vec3 *specularColor)
{
    _specularColor = specularColor;
}

void Material::setShininess(float a)
{
    _shininess = a;
}

void Material::setBlend(float a)
{
    _blend = a;
}

void Material::setTexture(std::string urlTexture)
{
    _texture = urlTexture;
}

//GET

std::string Material::getName()
{
    return _name;
}

Vec3* Material::getDiffuseColor()
{
    return _diffuseColor;
}

Vec3* Material::getAmbientColor()
{
    return _ambientColor;
}

Vec3* Material::getSpecularColor()
{
    return _specularColor;
}

float Material::getShininess()
{
    return _shininess;
}

float Material::getBlend()
{
    return _blend;
}

std::string Material::getTexture()
{
    return _texture;
}
