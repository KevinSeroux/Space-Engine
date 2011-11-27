#ifndef MESHMANAHER_H
#define MESHMANAGER_H

#include <vector>
#include "Mesh.h"
#include "Drawer.h"

class MeshManager
{
 public:
    static void addMesh(Mesh *mesh);
    static void exportToDrawer();
 private:
    std::vector<Mesh*> *_meshs;
};

#endif
