#include "ObjLoader.h"
#include "Engine.h"

Mesh& ObjLoader::load(std::string& file)
{
  _objStream.open(file.c_str());
  if(_objStream)
    {
      Mesh mesh;
      while(getline(_objStream, file))
	{
	  if(file.substr(0,7)=="mtllib ")
	    {
	      _mtlStream.open(file.substr(7, file.size()-7).c_str());
	      if(_mtlStream)
		{
		  while(getline(_mtlStream, file))
		    {
		      _lastMtl = Engine::getInstance()->getMaterialManager().getMaterials().size()-1;

		      if(file.substr(0,7) == "newmtl ")
			{
			  std::string mtlName = file.substr(7, file.size()-7);
			  Material material(mtlName);
			  Engine::getInstance()->getMaterialManager().addMaterial(material);
			}
		      else if(file[0] == 'K')
			{
			  if(file.substr(1,2) == "a ")
			    {
			      sscanf(file.c_str(), "Ka %f %f %f",
				     Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].getAmbientColor()[0],
				     Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].getAmbientColor()[1],
				     Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].getAmbientColor()[2]);
			    }
			  else if(file.substr(1,2) == "d ")
			    {
			      sscanf(file.c_str(), "Kd %f %f %f",
				     Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].getDiffuseColor()[0],
				     Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].getDiffuseColor()[1],
				     Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].getDiffuseColor()[2]);
			    }
			  else if(file.substr(1,2) == "s ")
			    {
			      sscanf(file.c_str(), "Ks %f %f %f",
				     Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].getSpecularColor()[0],
				     Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].getSpecularColor()[1],
				     Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].getSpecularColor()[2]);
			    }
			}
		      else if(file.substr(0,3) == "Ns ")
			{
			  sscanf(file.c_str(), "Ns %f", _x);
			  Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].setShininess(_x);
			}
		      else if(file.substr(0,2) == "d ")
			{
			  sscanf(file.c_str(), "d %f", _x);
			  Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].setBlend(_x);
			}
		    }
		}
	      else
		{
		  Engine::getInstance()->getLogger().log("Unable to open " + file.substr(7, file.size()-1));
		}
	    }
	  else if(file[0] == 'v')
	    {
	      if(file[1] == ' ')
		{
		  Vec3 vertex;
		  sscanf(file.c_str(), "v %f %f %f",
			 vertex[0],
			 vertex[1],
			 vertex[2]);
		  _vertices.push_back(vertex);
		}
	      else if(file.substr(1,2) == "n ")
		{
		  Vec3 normal;
		  sscanf(file.c_str(), "vn %f %f %f",
			 normal[0],
			 normal[1],
			 normal[2]);
		  _normals.push_back(normal);
		}
	      else if(file.substr(1,2) == "t ")
		{
		  Vec2 texture;
		  sscanf(file.c_str(), "vt %f %f",
			 texture[0],
			 texture[1]);
		  _textures.push_back(texture);
		}
	    }
	  else if(file.substr(0,7) == "usemtl ")
	    {
	      for(_lastMtl = 0; Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].getName() != file.substr(7, file.size()-7); _lastMtl++) {}
	    }
	  else if(file.substr(0,2) == "f ")
	    {
	      if(file.find("//")!=std::string::npos)
		{
		  sscanf(file.c_str(), "f %d//%d %d//%d %d//%d",
			 _id[0],_id[2], _id[3],_id[5], _id[6],_id[8]);

		  Vec3 vec1(_vertices[_id[0]-1].getX(), _vertices[_id[0]-1].getY(), _vertices[_id[0]-1].getZ());
		  Vec3 vec2(_normals[_id[0]-1].getX(), _normals[_id[0]-1].getY(), _normals[_id[0]-1].getZ());

		  Vec3 vec3(_vertices[_id[3]-1].getX(), _vertices[_id[3]-1].getY(), _vertices[_id[3]-1].getZ());
		  Vec3 vec4(_normals[_id[5]-1].getX(), _normals[_id[5]-1].getY(), _normals[_id[5]-1].getZ());

		  Vec3 vec5(_vertices[_id[6]-1].getX(), _vertices[_id[6]-1].getY(), _vertices[_id[6]-1].getZ());
		  Vec3 vec6(_normals[_id[8]-1].getX(), _normals[_id[8]-1].getY(), _normals[_id[8]-1].getZ());

		  Vertex vertex1(vec1, vec2);
		  Vertex vertex2(vec3, vec4);
		  Vertex vertex3(vec5, vec6);

		  Triangle triangle(vertex1, vertex2, vertex3, _lastMtl);

		  mesh.addTriangle(triangle);
		}
	      else if(file.find("/")!=std::string::npos)
		{
		  sscanf(file.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d",
			 _id[0],_id[1],_id[2], _id[3],_id[4],_id[5], _id[6],_id[7],_id[8]);

		  Vec3 vec1(_vertices[_id[0]-1].getX(), _vertices[_id[0]-1].getY(), _vertices[_id[0]-1].getZ());
		  Vec2 vec2(_textures[_id[1]-1].getX(), _textures[_id[1]-1].getY());
		  Vec3 vec3(_normals[_id[2]-1].getX(), _normals[_id[2]-1].getY(), _normals[_id[0]-1].getZ());

		  Vec3 vec4(_vertices[_id[3]-1].getX(), _vertices[_id[3]-1].getY(), _vertices[_id[3]-1].getZ());
		  Vec2 vec5(_textures[_id[4]-1].getX(), _textures[_id[4]-1].getY());
		  Vec3 vec6(_normals[_id[5]-1].getX(), _normals[_id[5]-1].getY(), _normals[_id[5]-1].getZ());

		  Vec3 vec7(_vertices[_id[6]-1].getX(), _vertices[_id[6]-1].getY(), _vertices[_id[6]-1].getZ());
		  Vec2 vec8(_textures[_id[7]-1].getX(), _textures[_id[7]-1].getY());
		  Vec3 vec9(_normals[_id[8]-1].getX(), _normals[_id[8]-1].getY(), _normals[_id[8]-1].getZ());

		  Vertex vertex1(vec1, vec3, vec2);
		  Vertex vertex2(vec4, vec6, vec5);
		  Vertex vertex3(vec7, vec9, vec8);

		  Triangle triangle(vertex1, vertex2, vertex3, _lastMtl);

		  mesh.addTriangle(triangle);
		}
	      else
		{
		  sscanf(file.c_str(), "f %d %d %d",
			 _id[0], _id[3], _id[6]);

		  Vec3 vec1(_vertices[_id[0]-1].getX(), _vertices[_id[0]-1].getY(), _vertices[_id[0]-1].getZ());
		  Vec3 vec2(_vertices[_id[3]-1].getX(), _vertices[_id[3]-1].getY(), _vertices[_id[3]-1].getZ());
		  Vec3 vec3(_vertices[_id[6]-1].getX(), _vertices[_id[6]-1].getY(), _vertices[_id[6]-1].getZ());

		  Vertex vertex1(vec1);
		  Vertex vertex2(vec2);
		  Vertex vertex3(vec3);

		  Triangle triangle(vertex1, vertex2, vertex3, _lastMtl);

		  mesh.addTriangle(triangle);
		}
	    }
	}
      return mesh;
    }
  else
    {
      Engine::getInstance()->getLogger().log("Unable to open " + file);
    }
}
