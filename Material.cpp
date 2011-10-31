#include "Material.h"

//SET

Material::Material(std::string name)
{
    m_name = name;
}

Material::Material() {}

void Material::SetDiffuseColor(Vec3 diffuseColor)
{
    m_diffuseColor = diffuseColor;
}

void Material::SetAmbientColor(Vec3 ambientColor)
{
    m_ambientColor = ambientColor;
}

void Material::SetSpecularColor(Vec3 specularColor)
{
    m_specularColor = specularColor;
}

void Material::SetBrightness(float a)
{
    m_brightness = a;
}

void Material::SetTransparency(float a)
{
    m_transparency = a;
}

void Material::SetTexture(std::string urlTexture)
{
    m_texture = urlTexture;
}

//GET

std::string Material::GetName()
{
    return m_name;
}

Vec3 Material::GetDiffuseColor()
{
    return m_diffuseColor;
}

Vec3 Material::GetAmbientColor()
{
    return m_ambientColor;
}

Vec3 Material::GetSpecularColor()
{
    return m_specularColor;
}

float Material::GetBrightness()
{
    return m_brightness;
}

float Material::GetTransparency()
{
    return m_transparency;
}

std::string Material::GetTexture()
{
    return m_texture;
}
