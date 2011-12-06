#ifndef DRAWER_H
#define DRAWER_H

#include <GL/glew.h>
#include <vector>
#include "MeshManager.h"

class Renderer
{
 public:
    Renderer();
    ~Renderer();
    static void render();
    static void renderMesh();
 private:
    static GLuint _buffer;
};

#endif
