#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include "Vec3.h"

class Material
{
 public:
    Material();
    void setDiffuseColor(Vec3 &diffuseColor);
    void setAmbientColor(Vec3 &ambientColor);
    void setSpecularColor(Vec3 &specularColor);
    void setShininess(float &shininess);
    void setBlend(float &blend);
    void setTextureURL(std::string &textureURL);

    Vec3& getDiffuseColor();
    Vec3& getAmbientColor();
    Vec3& getSpecularColor();
    float& getShininess();
    float& getBlend();
    std::string& getTextureURL();

 private:
    Vec3 _diffuseColor;
    Vec3 _ambientColor;
    Vec3 _specularColor;
    float _shininess;
    float _blend;
    std::string _textureURL;
};

#endif
