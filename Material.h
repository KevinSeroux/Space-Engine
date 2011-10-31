#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "Vec3.h"

class Material
{
 public:
    Material(std::string name);
    Material();
    void SetDiffuseColor(Vec3 diffuseColor);
    void SetAmbientColor(Vec3 ambientColor);
    void SetSpecularColor(Vec3 specularColor);
    void SetBrightness(float a);
    void SetTransparency(float a);
    void SetTexture(std::string urlTexture);

    std::string GetName();
    Vec3 GetDiffuseColor();
    Vec3 GetAmbientColor();
    Vec3 GetSpecularColor();
    float GetBrightness();
    float GetTransparency();
    std::string GetTexture();

 private:
    std::string m_name;
    Vec3 m_diffuseColor;
    Vec3 m_ambientColor;
    Vec3 m_specularColor;
    float m_brightness;
    float m_transparency;
    std::string m_texture;
};

#endif
