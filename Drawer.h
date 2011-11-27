#ifndef DRAWER_H
#define DRAWER_H

#include <GL/glew.h>
#include <vector>
#include "Mesh.h"

class Drawer
{
 public:
    static void addMesh(Mesh *mesh);
    static void draw();
 private:
    std::vector<Mesh*> *_meshs;
    GLuint _buffer;
};

#endif
