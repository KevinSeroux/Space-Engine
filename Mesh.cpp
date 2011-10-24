#include "Mesh.h"

void Mesh::AddTriangle(Triangle triangle)
{
    m_triangles.push_back(triangle);
}

void Mesh::ImportObj(const std::string url)
{
    std::ifstream stream(url.c_str());
    if(stream)
    {
	std::string line;
	float x,y,z;
	unsigned int limitX,limitY,limitZ,limitV1,limitV2,limitV3,limitV4;
	unsigned int nbrVertex1,nbrVertex2,nbrVertex3,nbrVertex4;
	std::vector<Vertex> vertices;
	std::stringstream iss;

	while(getline(stream,line))
	{
	    if(line.substr(0,7)=="mtllib ")
	    {
		    
	    }
	    else if(line.substr(0,2)=="v ")
	    {
		for(unsigned int i(0); i<line.size(); i++)
		{
		    if(line[i]==' ')
			limitX=i;

		}
		for(unsigned int i(limitX); i<line.size(); i++)
		{
		    if(line[i]==' ')
			limitY=i;
		}
		for(unsigned int i(limitY); i<line.size(); i++)
		{
		    if(line[i]==' ');
		    limitZ=i;
		}
		iss.str(line.substr(limitX,limitY-limitX));
		iss >> x;
		iss.str(line.substr(limitY,limitZ-limitY));
		iss >> y;
		iss.str(line.substr(limitZ,line.size()-limitZ));
		iss >> z;
		vertices.push_back(Vertex(x,y,z));
	    }
	    else if(line.substr(0,2)=="f ")
	    {
		for(unsigned int i(0); i<line.size(); i++)
		{
		    if(line[i]==' ')
			limitV1=i;
		}
		for(unsigned int i(limitV1); i<line.size(); i++)
		{
		    if(line[i]==' ')
			limitV2=i;
		}
		for(unsigned int i(limitV2); i<line.size(); i++)
		{
		    if(line[i]==' ')
			limitV3=i;
		}
		for(unsigned int i(limitV3); i<line.size(); i++)
		{
		    if(line[i]==' ')
			limitV4=i;
		}
		iss.str(line.substr(limitV1,limitV2-limitV1));
		iss >> nbrVertex1;
		iss.str(line.substr(limitV2,limitV3-limitV2));
		iss >> nbrVertex2;
		if(limitV4==0)
		{
		    iss.str(line.substr(limitV3,line.size()-limitV3));
		    iss >> nbrVertex3;
		}
		else
		{
		    iss.str(line.substr(limitV3,limitV4-limitV3));
		    iss >> nbrVertex3;
		    iss.str(line.substr(limitV4,line.size()-limitV4));
		    iss >> nbrVertex4;
		}
		if(limitV4==0) //Si notre face n'est pas composé de 4 vertex
		    m_triangles.push_back(Triangle(vertices[nbrVertex1-1],vertices[nbrVertex2-1],vertices[nbrVertex3-1]));
		else
		{
		    //Sinon on créer deux triangles pour notre faces de 4 vertex
		    m_triangles.push_back(Triangle(vertices[nbrVertex1-1],vertices[nbrVertex2-1],vertices[nbrVertex3-1]));
		    m_triangles.push_back(Triangle(vertices[nbrVertex2-1],vertices[nbrVertex3-1],vertices[nbrVertex4-1]));
		}
	    }
	}
    }
    else
    {
	ErrorManager::DisplayMessage("Failed to open : " + url);
    }
}

void Mesh::Draw()
{
    glBegin(GL_TRIANGLES);
    for(int i(0); i<=m_triangles.size(); i++)
    {
	m_triangles[i].Draw();
    }
    glEnd();
}
