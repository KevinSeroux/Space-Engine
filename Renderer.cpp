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
		 sizeof(MeshManager::getMeshes()),
		 NULL,
		 GL_STREAM_DRAW);

    glBufferSubData(GL_ARRAY_BUFFER,
		    0, //Quand on démarre la lecture dans le VBO
		    sizeof(MeshManager::getCoords()), //taille du tableau
		    MeshManager::getMeshes()::getCoords());
    glBufferSubData(GL_ARRAY_BUFFER,
		    sizeof(MeshManager::getCoords()),
		    sizeof(MeshManager::getNormals()),
		    MeshManager::getNormals());
    glVertexPointer(3, GL_FLOAT, 3, 0);
    glNormalPointer(3, GL_FLOAT, 3, 3);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    unsigned int index(0);
    unsigned int count(1);

    for(unsigned int i(0); i < MaterialManager::getMaterials().size(); i++)
    {
	count = MaterialManager::getTrianglesIndexed[i];

	if(i > 0) //If material
	{
	    if(MaterialManager::getMaterials()[i]->getAmbientColor() !=
	       MaterialManager::getMaterials()[i-1]->getAmbientColor())
	    {
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
		glColor3f(MaterialManager::getMaterials()[i]->getAmbientColor()->getX(),
			MaterialManager::getMaterials()[i]->getAmbientColor()->getY(),
			MaterialManager::getMaterials()[i]->getAmbientColor()->getZ());
	    }
	    if(MaterialManager::getMaterials()[i]->getDiffuseColor() !=
	       MaterialManager::getMaterials()[i-1]->getDiffuseColor())
	    {
		glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
		glColor3f(MaterialManager::getMaterials()[i]->getDiffuseColor()->getX(),
			MaterialManager::getMaterials()[i]->getDiffuseColor()->getY(),
			MaterialManager::getMaterials()[i]->getDiffuseColor()->getZ());
	    }
	    if(MaterialManager::getMaterials()[i]->getSpecularColor() !=
	       MaterialManager::getMaterials()[i-1]->getSpecularColor())
	    {
		glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
		glColor3f(MaterialManager::getMaterials()[i]->getSpecularColor()->getX(),
			MaterialManager::getMaterials()[i]->getSpecularColor()->getY(),
			MaterialManager::getMaterials()[i]->getSpecularColor()->getZ());
	    }
	    if(MaterialManager::getMaterials()[i]->getShininess !=
	       MaterialManager::getMaterials()[i-1]->getShininess)
	    {
		glMaterial(GL_FRONT_AND_BACK,GL_SHININESS,MaterialManager::getMaterials()[i]->getShininess);
	    }
	}
	glDrawArrays(GL_TRIANGLES,3*index,3*count);

	index = count;
    }

    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}
