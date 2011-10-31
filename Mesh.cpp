#include "Mesh.h"

void Mesh::ImportObj(const std::string url)
{
    std::ifstream stream(url.c_str());
    if(stream)
    {
	std::string line;
	float x,y,z;
	int vNumber[8];
	int nbrMat(0);
	std::vector<Vec3> vertices;
	std::vector<Vec2> textureCoords;

	while(getline(stream,line))
	{
	    if(line.substr(0,7)=="mtllib ")
	    {
		std::string lineMtl("Data/" + line.substr(7,line.size()));
		std::ifstream streamMtl(lineMtl.c_str());
		if(streamMtl)
		{
		    while(getline(streamMtl,lineMtl))
		    {
			if(lineMtl.substr(0,7)=="newmtl ") //Material's name
			    m_materials.push_back(Material(lineMtl.substr(7,lineMtl.size())));
			else if(lineMtl[0]=='K')
			{
			    if(lineMtl[1]=='a') //Ambiant color
			    {
				sscanf(lineMtl.c_str(),"Ka %f %f %f",&x,&y,&z);
				m_materials[m_materials.size()-1].SetAmbientColor(Vec3(x,y,z));
			    }
			    else if(lineMtl[1]=='d') //Diffuse color
			    {
				sscanf(lineMtl.c_str(),"Kd %f %f %f",&x,&y,&z);
				m_materials[m_materials.size()-1].SetDiffuseColor(Vec3(x,y,z));
			    }
			    else if(lineMtl[1]=='s') //Specular color
			    {
				sscanf(lineMtl.c_str(),"Ks %f %f %f",&x,&y,&z);
				m_materials[m_materials.size()-1].SetSpecularColor(Vec3(x,y,z));
			    }
			}
			else if(lineMtl.substr(0,3)=="Ns ") //Brightness
			{
			    sscanf(lineMtl.c_str(),"Ns %f",&x);
			    m_materials[m_materials.size()-1].SetBrightness(x);
			}
			else if(lineMtl[0]=='d') //Transparency
			{
			    sscanf(lineMtl.c_str(),"d %f",&x);
			    m_materials[m_materials.size()-1].SetTransparency(x);
			}
			else if(lineMtl.substr(0,7)=="map_Kd ") //Texture
			    m_materials[m_materials.size()-1].SetTexture(lineMtl.substr(7,line.size()));
		    }
		}
		else
		{
		    Logger::DisplayMessage("Failed to open mtllib file : " + lineMtl + " defined by " + url);
		}
	    }
	    else if(line[0]=='v')
	    {
		if(line[1]=='n')
		{
		    sscanf(line.c_str(),"vn %f %f %f",&x,&y,&z);
		    m_normals.push_back(Vec3(x,y,z));
		}
		else if(line[1]==' ')
		{
		    sscanf(line.c_str(),"v %f %f %f",&x,&y,&z);
		    vertices.push_back(Vec3(x,y,z));
		}
		else if(line[1]=='t')
		{
		    sscanf(line.c_str(),"vt %f %f",&x,&y);
		    textureCoords.push_back(Vec2(x,y));
		}
		else
		    Logger::DisplayMessage("Invalid file : " + line);
	    }
	    else if(line.substr(0,7)=="usemtl ")
	    {
		for(unsigned int i(0); i<= m_materials.size()-1; i++)
		    if(m_materials[i].GetName()==line.substr(7,line.size()))
			nbrMat += 1;
	    }
	    else if(line[0]=='f')
	    {
		if(line.find("//")!=std::string::npos)
		    sscanf(line.c_str(),"f %d//%d %d//%d %d//%d",&vNumber[0],&vNumber[2], &vNumber[3],&vNumber[5], &vNumber[6],&vNumber[8]);
		else if(line.find("/")!=std::string::npos)
		    sscanf(line.c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d", &vNumber[0],&vNumber[1],&vNumber[2], &vNumber[3],&vNumber[4],&vNumber[5], &vNumber[6],&vNumber[7],&vNumber[8]);
		else
		    sscanf(line.c_str(),"f %d %d %d %d", &vNumber[0], &vNumber[3], &vNumber[6]);

		m_triangles.push_back(Triangle(vertices[vNumber[0]-1],vertices[vNumber[3]-1],vertices[vNumber[6]-1],m_materials[nbrMat-1]));
	    }
	}
    }
    else
	Logger::DisplayMessage("Failed to open : " + url);
}

void Mesh::Draw()
{
    glBegin(GL_TRIANGLES);
    for(unsigned int i(0); i<= m_triangles.size()-1; i++)
    {
	glColor3f(m_triangles[i].GetMaterial().GetAmbientColor().GetX(),m_triangles[i].GetMaterial().GetAmbientColor().GetY(),m_triangles[i].GetMaterial().GetAmbientColor().GetZ());
	glVertex3f(m_triangles[i].GetVertex1().GetX(),m_triangles[i].GetVertex1().GetY(),m_triangles[i].GetVertex1().GetZ());
	glVertex3f(m_triangles[i].GetVertex2().GetX(),m_triangles[i].GetVertex2().GetY(),m_triangles[i].GetVertex2().GetZ());
	glVertex3f(m_triangles[i].GetVertex3().GetX(),m_triangles[i].GetVertex3().GetY(),m_triangles[i].GetVertex3().GetZ());
    }
    glEnd();
}
