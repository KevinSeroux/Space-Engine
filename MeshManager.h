#ifndef MESHMANAHER_H
#define MESHMANAGER_H

#include <vector>
#include "Mesh.h"

class MeshManager
{
 public:
    //SET
    static void addMesh(Mesh *mesh);
    //GET
    static std::vector<Mesh*> getMeshes();
 private:
    static std::vector<Mesh*> _meshes;
};

#endif
