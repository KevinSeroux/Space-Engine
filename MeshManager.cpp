#include "MeshManager.h"

void MeshManager::addMesh(Mesh *mesh)
{
    _meshs->push_back(mesh);
}

void MeshManager::exportToDrawer()
{
    for(unsigned int i(0); i < _meshs->size()-1; i++)
	Drawer::addMesh(_meshs[i]);
}
