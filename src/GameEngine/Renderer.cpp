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

    glBindBuffer(GL_ARRAY_BUFFER, _buffer);
    glBufferData(GL_ARRAY_BUFFER,
		 sizeof(MeshManager::getVerticesCoords()),
		 MeshManager::getVerticesCoords(),
		 GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, MeshManager::getCountTriangles());
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
