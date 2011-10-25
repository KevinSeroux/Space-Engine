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
	int vNumber[11];
	std::vector<Vertex> vertices;

	while(getline(stream,line))
	{
	    if(line.substr(0,7)=="mtllib ")
	    {
		std::string urlMtllib("Data/" + line.substr(7,line.size()));
		std::ifstream streamMtllib(urlMtllib.c_str());
		if(streamMtllib)
		{
		}
		else
		{
		    ErrorManager::DisplayMessage("Failed to open mtllib file : " + urlMtllib + " defined by " + url);
		}
	    }
	    else if(line[0]=='v')
	    {
		if(line[1]=='n')
		{
		    //Si c'est une normale (normals) (éclairage)
		}
		else if(line[1]==' ')
		{
		    sscanf(line.c_str(),"v %f %f %f",&x,&y,&z);
		    vertices.push_back(Vertex(x,y,z));
		}
		else if(line[1]!='t')
		    ErrorManager::DisplayMessage("Invalid file : " + line);
	    }
	    else if(line[0]=='f')
	    {
		if(line.find("//")!=std::string::npos)
		    sscanf(line.c_str(),"f %d//%d %d//%d %d//%d %d//%d",&vNumber[0],&vNumber[2], &vNumber[3],&vNumber[5], &vNumber[6],&vNumber[8], &vNumber[9],&vNumber[11]);
		else if(line.find("/")!=std::string::npos)
		    sscanf(line.c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", &vNumber[0],&vNumber[1],&vNumber[2], &vNumber[3],&vNumber[4],&vNumber[5], &vNumber[6],&vNumber[7],&vNumber[8], &vNumber[9],&vNumber[10],&vNumber[11]);
		else
		    sscanf(line.c_str(),"f %d %d %d %d", &vNumber[0], &vNumber[3], &vNumber[6], &vNumber[9]);
		if(vNumber[9]==0)
		{
		    std::cout << "C01 :-> " << vertices[vNumber[0]-1].GetXYZ() << " | C02 :-> " << vertices[vNumber[3]-1].GetXYZ() << " | C03 :-> " << vertices[vNumber[3]-1].GetXYZ() << std::endl;
		    m_triangles.push_back(Triangle(vertices[vNumber[0]-1],vertices[vNumber[3]-1],vertices[vNumber[6]-1])); 
		}
		else
		{
		    std::cout << "C01 :-> " << vertices[vNumber[0]-1].GetXYZ() << " | CO2 :-> " << vertices[vNumber[3]-1].GetXYZ() << " | C03 :-> " << vertices[vNumber[6]-1].GetXYZ() << std::endl;
		    m_triangles.push_back(Triangle(vertices[vNumber[0]-1],vertices[vNumber[3]-1],vertices[vNumber[6]-1]));
		    std::cout << "CO2 :-> " << vertices[vNumber[3]-1].GetXYZ() << " | C03 :-> " << vertices[vNumber[6]-1].GetXYZ() << " | C04 :-> " << vertices[vNumber[9]-1].GetXYZ() << std::endl;
		    m_triangles.push_back(Triangle(vertices[vNumber[3]-1],vertices[vNumber[6]-1],vertices[vNumber[9]-1]));
		}
	    }
	}
    }
    else
	ErrorManager::DisplayMessage("Failed to open : " + url);
}

void Mesh::Draw()
{
    for(int i(0); i<=m_triangles.size(); i++)
    {
	m_triangles[i].Draw();
    }
    glEnd();
}
