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
