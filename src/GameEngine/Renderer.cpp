#include "Renderer.h"

Renderer::Renderer()
{
    glGenBuffers(1,&_buffer);
}

Renderer::~Renderer()
{
    glDeleteBuffers(1,&_buffer);
}

void Renderer::render()
{
    renderMesh();
}

void Renderer::renderMesh()
{
    glClear(GL_COLOR_BUFFER_BIT);


}
