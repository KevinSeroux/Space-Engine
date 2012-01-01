#include "MaterialManager.h"

//SET

void MaterialManager::addMaterial(Material &material)
{
    _materials.push_back(material);
}

void MaterialManager::deleteMaterial(const unsigned char& index)
{
    _materials.erase(_materials.begin()+index);
}

//GET

std::vector<Material&> MaterialManager::getMaterials()
{
    return _materials;
}
