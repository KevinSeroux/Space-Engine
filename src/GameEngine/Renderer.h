#ifndef DRAWER_H
#define DRAWER_H

#ifdef WIN32
#include <GL3/glew.h>
#else
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>
#endif

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
