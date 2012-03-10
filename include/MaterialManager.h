#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include <vector>
#include "Material.h"

class MaterialManager
{
 public:
    //SET
    void addMaterial(Material &material);
    void deleteMaterial(const unsigned char& index);
    //GET
    std::vector<Material>& getMaterials();
 private:
    std::vector<Material> _materials;
};

#endif
