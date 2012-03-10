#include "MeshManager.h"

//SET

void MeshManager::addMesh(Mesh &mesh)
{
    _meshes.push_back(mesh);
}

//GET

std::vector<Mesh>& MeshManager::getMeshes()
{
    return _meshes;
}
