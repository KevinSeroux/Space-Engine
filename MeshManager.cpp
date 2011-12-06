#include "MeshManager.h"

//GET

void MeshManager::addMesh(Mesh *mesh)
{
    _meshes.push_back(mesh);
}

//SET

std::vector<Mesh*> MeshManager::getMeshes()
{
    return _meshes;
}
