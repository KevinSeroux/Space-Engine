#define BUFFER_OFFSET(a) ((char*)NULL + (a))

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
		    sizeof(MeshManager::getMeshes()), //taille du tableau
		    MeshManager::getMeshes());
    glVertexPointer(3, GL_FLOAT, 0, 3*sizeof(float), BUFFER_OFFSET(0));
    glNormalPointer(3, GL_FLOAT, 3, 3*sizeof(float), BUFFER_OFFSET(0));

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    //ALGORITHME PAS TERRIBLE
    int nbr(0);

    for(unsigned int i(0); i < MeshManager::getMeshes().size()-1; i++)
    {
	for(unsigned int j(0); j < MeshManager::getMeshes()[j]->getNumberTriangles(); j++)
	{
	    if(!MeshManager::getMeshes()[i]->getTriangles()[j]->getMaterial()->getAmbientColor().isNull())
	    {
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
		glColor3f(MeshManager::getMeshes()[i]->getTriangles()[j].getMaterial()->getAmbientColor()->getX(),
			  MeshManager::getMeshes()[i]->getTriangles()[j].getMaterial()->getAmbientColor()->getY(),
			  MeshManager::getMeshes()[i]->getTriangles()[j].getMaterial()->getAmbientColor()->getZ());
		glDrawArrays(GL_TRIANGLES, 0 + nbr, 6 + nbr);
		nbr += 6;
	    }
	    if(!MeshManager::getMeshes[i]->getTriangles[j]->getMaterial()->getDiffuseColor().isNull())
	    {
		glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
		glColor3f(MeshManager::getMeshes()[i]->getTriangles()[j].getMaterial()->getDiffuseColor()->getX(),
			  MeshManager::getMeshes()[i]->getTriangles()[j].getMaterial()->getDiffuseColor()->getY(),
			  MeshManager::getMeshes()[i]->getTriangles()[j].getMaterial()->getDiffuseColor()->getZ());
		glDrawArrays(GL_TRIANGLES, 0 + nbr, 6 + nbr);
		nbr += 6;
	    }
	    if(!MeshManager::getMeshes[i]->getTriangles[j]->getMaterial()->getSpecularColor().isNull())
	    {
		glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);
		glColor3f(MeshManager::getMeshes()[i]->getTriangles()[j].getMaterial()->getSpecularColor()->getX(),
			  MeshManager::getMeshes()[i]->getTriangles()[j].getMaterial()->getSpecularColor()->getY(),
			  MeshManager::getMeshes()[i]->getTriangles()[j].getMaterial()->getSpecularColor()->getZ());
		glDrawArrays(GL_TRIANGLES, 0 + nbr, 6 + nbr);
		nbr += 6;
	    }
	}
    }

    //FIN ALGORITHME PAS TERRIBLE

    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}
