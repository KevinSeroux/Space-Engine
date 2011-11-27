Mesh ObjImporter::importObj(std::string url)
{
    Mesh myMesh;

    std::ifstream stream(url.c_str());
    if(stream)
    {
	std::string line;
	float x,y,z;
	int vNumber[8];

	int nbrMat(0);

	Triangle triangle;
	Vertex vertex1;
	Vertex vertex2;
	Vertex vertex3;

	std::vector<Vec3> vertices;
	std::vector<Vec3> normals;
	std::vector<Vec2> texturePoints;
	std::vector<Material> materials;

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
			    materials.push_back(Material(lineMtl.substr(7,lineMtl.size())));
			else if(lineMtl[0]=='K')
			{
			    if(lineMtl[1]=='a') //Ambiant color
			    {
				sscanf(lineMtl.c_str(),"Ka %f %f %f",&x,&y,&z);
				materials[materials.size()-1].setAmbientColor(Vec3(x,y,z));
			    }
			    else if(lineMtl[1]=='d') //Diffuse color
			    {
				sscanf(lineMtl.c_str(),"Kd %f %f %f",&x,&y,&z);
				materials[materials.size()-1].setDiffuseColor(Vec3(x,y,z));
			    }
			    else if(lineMtl[1]=='s') //Specular color
			    {
				sscanf(lineMtl.c_str(),"Ks %f %f %f",&x,&y,&z);
				materials[materials.size()-1].setSpecularColor(Vec3(x,y,z));
			    }
			}
			else if(lineMtl.substr(0,3)=="Ns ") //Shininess
			{
			    sscanf(lineMtl.c_str(),"Ns %f",&x);
			    materials[materials.size()-1].setShininess(x);
			}
			else if(lineMtl[0]=='d') //Transparency
			{
			    sscanf(lineMtl.c_str(),"d %f",&x);
			    materials[materials.size()-1].setTransparency(x);
			}
			else if(lineMtl.substr(0,7)=="map_Kd ") //Texture
			    materials[materials.size()-1].setTexture(lineMtl.substr(7,line.size()));
		    }
		}
		else
		{
		    Logger::DisplayMessage("Failed to open mtllib file : " + lineMtl + " defined by " + url);
		}
	    }
	    else if(line[0]=='v')
	    {
		if(line[1]=='n') //Normal
		{
		    sscanf(line.c_str(),"vn %f %f %f",&x,&y,&z);
		    normals.push_back(Vec3(x,y,z));
		}
		else if(line[1]==' ') //Vertex
		{
		    sscanf(line.c_str(),"v %f %f %f",&x,&y,&z);
		    vertices.push_back(Vec3(x,y,z));
		}
		else if(line[1]=='t') //Texture point
		{
		    sscanf(line.c_str(),"vt %f %f",&x,&y);
		    texturePoints.push_back(Vec2(x,y));
		}
		else
		    Logger::DisplayMessage("Invalid file : " + line);
	    }
	    else if(line.substr(0,7)=="usemtl ")
	    {
		for(unsigned int i(0); i<= materials.size()-1; i++)
		    if(materials[i].getName()==line.substr(7,line.size()))
			nbrMat += 1;
	    }
	    else if(line[0]=='f')
	    {
		if(line.find("//")!=std::string::npos)
		{
		    sscanf(line.c_str(),"f %d//%d %d//%d %d//%d",&vNumber[0],&vNumber[2], &vNumber[3],&vNumber[5], &vNumber[6],&vNumber[8]);
		    vertex1.setNormal(normals[vNumber[2]-1]);
		    vertex2.setNormal(normals[vNumber[5]-1]);
		    vertex3.setNormal(normals[vNumber[8]-1]);
		}
		else if(line.find("/")!=std::string::npos)
		{
		    sscanf(line.c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d", &vNumber[0],&vNumber[1],&vNumber[2], &vNumber[3],&vNumber[4],&vNumber[5], &vNumber[6],&vNumber[7],&vNumber[8]);
		    vertex1.setTexturePoint(texturePoints[vNumber[1]-1]);
		    vertex1.setNormal(normals[vNumber[2]-1]);
		    vertex2.setTexturePoint(texturePoints[vNumber[4]-1]);
		    vertex2.setNormal(normals[vNumber[5]-1]);
		    vertex3.setTexturePoint(texturePoints[vNumber[7]-1]);
		    vertex3.setNormal(normals[vNumber[8]-1]);
		}
		else
		    sscanf(line.c_str(),"f %d %d %d", &vNumber[0], &vNumber[3], &vNumber[6]);

		vertex1.setCoord(vertices[vNumber[0]-1]);
		vertex2.setCoord(vertices[vNumber[3]-1]);
		vertex3.setCoord(vertices[vNumber[6]-1]);

		triangle.setVertex1(vertex1);
		triangle.setVertex2(vertex2);
		triangle.setVertex3(vertex3);
		triangle.setMaterial(materials[materials.size()-1]);

		_triangles.push_back(triangle);
	    }
	}
    }
    else
	Logger::DisplayMessage("Failed to open : " + url);

    return myMesh;
}
