#ifndef MESHMANAGER_H
#define MESHMANAGER_H

#include <vector>
#include "Mesh.h"

class MeshManager
{
    public:
    //SET
    void addMesh(Mesh &mesh);
    //GET
    std::vector<Mesh>& getMeshes();
 private:
    std::vector<Mesh> _meshes;
};

#endif
