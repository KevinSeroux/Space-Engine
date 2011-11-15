#include "Material.h"

//SET

Material::Material(std::string name)
{
    m_name = name;
}

Material::Material() {}

void Material::setDiffuseColor(Vec3 diffuseColor)
{
    m_diffuseColor = diffuseColor;
}

void Material::setAmbientColor(Vec3 ambientColor)
{
    m_ambientColor = ambientColor;
}

void Material::setSpecularColor(Vec3 specularColor)
{
    m_specularColor = specularColor;
}

void Material::setShininess(float a)
{
    m_shininess = a;
}

void Material::setTransparency(float a)
{
    m_transparency = a;
}

void Material::setTexture(std::string urlTexture)
{
    m_texture = urlTexture;
}

//GET

std::string Material::getName()
{
    return m_name;
}

Vec3 Material::getDiffuseColor()
{
    return m_diffuseColor;
}

Vec3 Material::getAmbientColor()
{
    return m_ambientColor;
}

Vec3 Material::getSpecularColor()
{
    return m_specularColor;
}

float Material::getShininess()
{
    return m_shininess;
}

float Material::getTransparency()
{
    return m_transparency;
}

std::string Material::getTexture()
{
    return m_texture;
}
