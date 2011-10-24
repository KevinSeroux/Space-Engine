#include "Mesh.h"

Mesh::AddTriangle(const Triangle& triangle)
{
    m_triangles->push_back(1,triangle);
}

Mesh::ImportObj(const std::string& url)
{
    ifstream stream(url);
    if(stream)
    {
	std::string line;
	float x,y,z;
	unsigned byte limitX,limitY,limitZ,limitV1,limitV2,limitV3,limitV4;
	unsigned byte nbrVertex1,nbrVertex2,nbrVertex3;
	vector<Vertex> vertices;

	while(getline(stream,line)
	    {
		if(line.substr(0,7)=="mtllib ")
		{
		    
		}
		else if(line.substr(0,2)=="v ")
		{
		    for(unsigned byte i(0); i<line.size(); i++)
		    {
			if(line[i]==' ')
			    limitX=i;

		    }
		    for(unigned byte i(limitX); i<line.size(); i++)
		    {
			if(line[i]==' ')
			    limitY=i;
		    }
		    for(unigned byte i(limitY); i<line.size(); i++)
		    {
			if(line[i]==' ');
			limitZ=i;
		    }
		    std::isstringstream iss;
		    iss.string(line.substr(limitX,limitY-limitX));
		    iss >> x;
		    iss.string(line.substr(limitY,limitZ-limitY));
		    iss >> y;
		    iss.string(line.substr(limitZ,line.size()-limitZ));
		    iss >> z;
		    vertices.push_back(1,new Vertex(x,y,z));
		}
		else if(line.substr(0,2)=="f ")
		{
		    for(unsigned byte i(0); i<line.size(); i++)
		    {
			if(line[i]==' ')
			    limitV1=i;
		    }
		    for(unsigned byte i(limitV1); i<line.size(); i++)
		    {
			if(line[i]==' ')
			    limitV2=i;
		    }
		    for(unsigned byte i(limitV2); i<line.size(); i++)
		    {
			if(line[i]==' ')
			    limitV3=i;
		    }
		    for(unsigned byte i(limitV3); i<line.size(); i++)
		    {
			if(line[i]==' ')
			    limitV4=i;
		    }
		    std::isstringstream iss;
		    iss.string(line.substr(limitV1,limitV2-limitV1));
		    iss >> nbrVertex1;
		    iss.string(line.substr(limitV2,limitV3-limitV2));
		    iss >> nbrVertex2;
		    if(limitV4!=NULL)
		    {
			iss.string(line.substr(limitV3,limitV4-limitV3));
			iss >> nbrVertex3;
		    }
		    else
		    {
			iss.string(line.substr(limitV3,line.size()-limitV3));
			iss >> nbrVertex3;
		    }
		    if(limitV4==NULL) //Si notre face n'est pas composé de 4 vertex
			m_triangles->push_back(1,new Triangles(vertices[nbrVertex1-1],vertices[nbrVertex2-1],vertices[nbrVertex3-1]));
		    else
		    {
			//Sinon on créer deux triangles pour notre faces de 4 vertex
			m_triangles->push_back(1,new Triangles(vertices[nbrVertex1-1],vertices[nbrVertex2-1],vertices[nbrVertex3-1]));
			m_triangles->push_back(1,new Triangles(vertices[nbrVertex2-1],vertices[nbrVertex3-1],vertices[nbrVertex4-1]));
		    }
		}
	    }
	    }
	else
	{
	    ErrorManager::DisplayMessage("Failed to opening : " + url);
	}
    }
}

Mesh::Draw()
{
    glBegin(GL_TRIANGLES);
    for(int i(0); m_triangles[i]; i++)
    {
	m_triangles[i]->Draw();
    }
    glEnd();
}
