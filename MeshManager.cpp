#include "MeshManager.h"

//SET

void MeshManager::addMesh(Mesh *mesh)
{
    _meshes.push_back(mesh);
}

//GET

std::vector<Mesh*> MeshManager::getMeshes()
{
    return _meshes;
}

void MeshManager::sortTrianglesByMaterial()
{
    std::vector<Triangle*> triangles;
    for(unsigned int i(0); i < _meshes.size()-1; i++)
    {
	for(unsigned int j(0); j < _meshes()[i]->getNumberTriangles; j++)
	{
	    triangles.push_back(_meshes()[i]->getTriangles()[j]);
	}
    }
    std::sort(triangles.begin(),triangles.end(),sortByMaterial());
}

bool MeshManager::sortByMaterial(const Triangle& triangle1, const Triangle& triangle2)
{
    if(triangle1.getMaterial() == triangle2.getMaterial())
	return true;
    else
	return false;
} 

void MeshManager::getVertices()
{
    int index(0);

    for(unsigned int i(0); i < _meshes.size()-1; i++)
    {
	for(unsigned int j(0); j < (_meshes.size()*_meshes[i]->getNumberTriangles()*9)-1; j++)
	{
	    _vertices[index] = _meshes[i]->getTriangles[j]->getVertex1()->getCoord()->getX();
	    _vertices[index+1] = _meshes[i]->getTriangles[j]->getVertex1()->getCoord()->getY();
	    _vertices[index+2] = _meshes[i]->getTriangles[j]->getVertex1()->getCoord()->getZ();
	    _vertices[index+3] = _meshes[i]->getTriangles[j]->getVertex2()->getCoord()->getX();
	    _vertices[index+4] = _meshes[i]->getTriangles[j]->getVertex2()->getCoord()->getY();
	    _vertices[index+5] = _meshes[i]->getTriangles[j]->getVertex2()->getCoord()->getZ();
	    _vertices[index+6] = _meshes[i]->getTriangles[j]->getVertex3()->getCoord()->getX();
	    _vertices[index+7] = _meshes[i]->getTriangles[j]->getVertex3()->getCoord()->getY();
	    _vertices[index+8] = _meshes[i]->getTriangles[j]->getVertex3()->getCoord()->getZ();

	    _normals[index] = _meshes[i]->getTriangles[j]->getVertex1()->getNormal()->getX();
	    _normals[index+1] = _meshes[i]->getTriangles[j]->getVertex1()->getNormal()->getY();
	    _normals[index+2] = _meshes[i]->getTriangles[j]->getVertex1()->getNormal()->getZ();
	    _normals[index+3] = _meshes[i]->getTriangles[j]->getVertex2()->getNormal()->getX();
	    _normals[index+4] = _meshes[i]->getTriangles[j]->getVertex2()->getNormal()->getY();
	    _normals[index+5] = _meshes[i]->getTriangles[j]->getVertex2()->getNormal()->getZ();
	    _normals[index+6] = _meshes[i]->getTriangles[j]->getVertex3()->getNormal()->getX();
	    _normals[index+7] = _meshes[i]->getTriangles[j]->getVertex3()->getNormal()->getY();
	    _normals[index+8] = _meshes[i]->getTriangles[j]->getVertex3()->getNormal()->getZ();
	    
	    index += 9;
	}
    }
}

float* MeshManager::getVerticesCoords()
{
    return _vertices;
}

float* MeshManager::getVerticesNormals()
{
    return _normals;
}
