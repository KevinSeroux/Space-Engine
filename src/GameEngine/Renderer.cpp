#include "Renderer.h"
#include "Engine.h"

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
  glClear(GL_COLOR_BUFFER_BIT);
  Renderer::renderVAO();
}

void Renderer::renderVAO()
{
  for(unsigned int i(0); i < Engine::getInstance()->getMeshManager().getMeshes().size(); i++)
    {
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, Engine::getInstance()->getMeshManager().getMeshes()[i]->getVertices()); //-> problem
      std::cout << "glVertexAttribPointer();" << std::endl;
      glEnableVertexAttribArray(0);
      std::cout << "glEnableVertexAttribArray(0)" << std::endl;
      glDrawArrays(GL_TRIANGLES, 0, Engine::getInstance()->getMeshManager().getMeshes()[i]->getCountTriangles());
      std::cout << "glDrawArrays()" << std::endl;
      glDisableVertexAttribArray(0);
      std::cout << "glDisableVertexAttribArray(0)" << std::endl;
    }
}

void Renderer::renderVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER, _buffer);

    for(unsigned int i(0); i < Engine::getInstance()->getMeshManager().getMeshes().size(); i++)
      {    
	glBufferData(GL_ARRAY_BUFFER,
		     sizeof(float)*Engine::getInstance()->getMeshManager().getMeshes()[i]->getCountTriangles()*3,
		     Engine::getInstance()->getMeshManager().getMeshes()[i]->getVertices(),
		     GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, Engine::getInstance()->getMeshManager().getMeshes()[i]->getCountTriangles());
	glDisableVertexAttribArray(0);
      }
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
