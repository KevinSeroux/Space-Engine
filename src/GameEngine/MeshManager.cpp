#include "MeshManager.h"

//SET

void MeshManager::addMesh(Mesh &mesh)
{
    _countTriangles += mesh.getNumberTriangles();
    _meshes.push_back(mesh);
}

//GET

std::vector<Mesh>& MeshManager::getMeshes()
{
    return _meshes;
}

const unsigned int& MeshManager::getCountTriangles()
{
    return _countTriangles;
}

float* MeshManager::getVerticesCoords()
{
    float* vertices;
    unsigned int index(0);
    for(unsigned int i(0); i < _meshes.size()-1; i++)
    {
	for(unsigned int j(0); j < _meshes[i].getNumberTriangles()-1; j++)
	{
	    vertices[index] = _meshes[i].getTriangles()[j].getVertex1().getCoord().getX();
	    vertices[index+1] = _meshes[i].getTriangles()[j].getVertex1().getCoord().getY();
	    vertices[index+2] = _meshes[i].getTriangles()[j].getVertex1().getCoord().getZ();

	    vertices[index+3] = _meshes[i].getTriangles()[j].getVertex2().getCoord().getX();
	    vertices[index+4] = _meshes[i].getTriangles()[j].getVertex2().getCoord().getY();
	    vertices[index+5] = _meshes[i].getTriangles()[j].getVertex2().getCoord().getZ();

	    vertices[index+6] = _meshes[i].getTriangles()[j].getVertex3().getCoord().getX();
	    vertices[index+7] = _meshes[i].getTriangles()[j].getVertex3().getCoord().getY();
	    vertices[index+8] = _meshes[i].getTriangles()[j].getVertex3().getCoord().getZ();

	    index += 9;
	}
    }
    return vertices;
}
