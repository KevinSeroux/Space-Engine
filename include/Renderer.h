#ifndef RENDERER_H
#define RENDERER_H

#ifdef WIN32
#include <GL3/glew.h>
#else
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>
#endif

#include <vector>
#include <iostream>
#include "Engine.h"

class Renderer
{
 public:
    Renderer();
    ~Renderer();
    void render();
    void renderVAO();
    void renderVBO();
 private:
    GLuint _buffer;
};

#endif
