#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include <vector>
#include "Material.h"

class MaterialManager
{
 public:
    //SET
    static void addMaterial(Material &material);
    static void deleteMaterial(const unsigned char& index);
    //GET
    static std::vector<Material&> getMaterials();
 private:
    static std::vector<Material&> _materials;
};

#endif
