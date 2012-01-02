#ifndef MESHMANAHER_H
#define MESHMANAGER_H

#include <vector>
#include "Mesh.h"

class MeshManager
{
    public:
    //SET
    static void addMesh(Mesh &mesh);
    //GET
    static std::vector<Mesh>& getMeshes();
    static const unsigned int& getCountTriangles();
    static float* getVerticesCoords();
 private:
    static std::vector<Mesh> _meshes;
    static unsigned int _countTriangles;
};

#endif
