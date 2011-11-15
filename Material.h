#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "Vec3.h"

class Material
{
 public:
    Material(std::string name);
    Material();
    void setDiffuseColor(Vec3 diffuseColor);
    void setAmbientColor(Vec3 ambientColor);
    void setSpecularColor(Vec3 specularColor);
    void setShininess(float a);
    void setTransparency(float a);
    void setTexture(std::string urlTexture);

    std::string getName();
    Vec3 getDiffuseColor();
    Vec3 getAmbientColor();
    Vec3 getSpecularColor();
    float getShininess();
    float getTransparency();
    std::string getTexture();

 private:
    std::string m_name;
    Vec3 m_diffuseColor;
    Vec3 m_ambientColor;
    Vec3 m_specularColor;
    float m_shininess;
    float m_transparency;
    std::string m_texture;
};

#endif
