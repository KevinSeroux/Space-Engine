/*------------------------------------------------------------------------------
| Copyright (C) 2012 Seroux Kévin                                              |
|                                                                              |
| This program is free software; you can redistribute it and/or                |
| modify it under the terms of the GNU Lesser General Public                   |
| License as published by the Free Software Foundation; either                 |
| version 2.1 of the License, or (at your option) any later version.           |
|                                                                              |
| This program is distributed in the hope that it will be useful,              |
| but WITHOUT ANY WARRANTY; without even the implied warranty of               |
| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU             |
| Lesser General Public License for more details.                              |
|                                                                              |
| You should have received a copy of the GNU Lesser General Public             |
| License along with this program; if not, write to the Free Software          |
| Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA |
------------------------------------------------------------------------------*/

#include "ObjLoader.h"
#include "Engine.h"

Mesh* ObjLoader::load(std::string& file)
{
  bool isFind = false;
  unsigned char placeDir;
  for(placeDir = file.size()-1; placeDir > 0 && isFind == false; placeDir--)
    {
      if(file[placeDir] == '/')
	isFind = true;
    }
  std::string dir = file.substr(0, placeDir+2);

  _objStream.open(file.c_str());
  if(_objStream)
    {
      while(getline(_objStream, file))
	{
	  if(file.substr(0,7)=="mtllib ")
	    {
	      std::string mtlFile = dir + file.substr(7, file.size()-7);
	      _mtlStream.open(mtlFile.c_str());
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
			      float x,y,z;
			      sscanf(file.c_str(), "Ka %f %f %f", &x, &y, &z);
			      Vec3 vec3(x,y,z);
			      Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].setAmbientColor(vec3);
			    }
			  else if(file.substr(1,2) == "d ")
			    {
			      float x,y,z;
			      sscanf(file.c_str(), "Kd %f %f %f", &x, &y, &z);
			      Vec3 vec3(x,y,z);
			      Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].setDiffuseColor(vec3);
			    }
			  else if(file.substr(1,2) == "s ")
			    {
			      float x,y,z;
			      sscanf(file.c_str(), "Ks %f %f %f", &x, &y, &z);
			      Vec3 vec3(x,y,z);
			      Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].setSpecularColor(vec3);
			    }
			}
		      else if(file.substr(0,3) == "Ns ")
			{
			      float x;
			      sscanf(file.c_str(), "Ns %f", &x);
			      Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].setShininess(x);
			}
		      else if(file.substr(0,2) == "d ")
			{
			  float x;
			  sscanf(file.c_str(), "d %f", &x);
			  Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].setBlend(x);
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
		  float x,y,z;
		  sscanf(file.c_str(), "v %f %f %f", &x, &y, &z);
		  Vec3 vec3(x,y,z);
		  _vertices.push_back(vec3);
		}
	      else if(file.substr(1,2) == "n ")
		{
		  float x,y,z;
		  sscanf(file.c_str(), "vn %f %f %f", &x, &y, &z);
		  Vec3 vec3(x,y,z);
		  _normals.push_back(vec3);
		}
	      else if(file.substr(1,2) == "t ")
		{
		  float x,y;
		  sscanf(file.c_str(), "vt %f %f", &x, &y);
		  Vec2 vec2(x,y);
		  _textures.push_back(vec2);
		  std::cout << "vt " << x << " " << y << std::endl;
		}
	    }
	  else if(file.substr(0,7) == "usemtl ")
	    {
	      for(_lastMtl = 0; file.substr(7,file.size()-7) != Engine::getInstance()->getMaterialManager().getMaterials()[_lastMtl].getName(); _lastMtl++) {}
	    }
	  else if(file.substr(0,2) == "f ")
	    {
	      if(file.find("//")!=std::string::npos)
		{
		  unsigned int i[6];
		  sscanf(file.c_str(), "f %d//%d %d//%d %d//%d", &i[0],&i[1], &i[2],&i[3], &i[4],&i[5]);

		  Vec3 vec1(_vertices[i[0]-1].getX(), _vertices[i[0]-1].getY(), _vertices[i[0]-1].getZ());
		  Vec3 vec2(_normals[i[1]-1].getX(), _normals[i[1]-1].getY(), _normals[i[1]-1].getZ());

		  Vec3 vec3(_vertices[i[2]-1].getX(), _vertices[i[2]-1].getY(), _vertices[i[2]-1].getZ());
		  Vec3 vec4(_normals[i[3]-1].getX(), _normals[i[3]-1].getY(), _normals[i[3]-1].getZ());

		  Vec3 vec5(_vertices[i[4]-1].getX(), _vertices[i[4]-1].getY(), _vertices[i[4]-1].getZ());
		  Vec3 vec6(_normals[i[5]-1].getX(), _normals[i[5]-1].getY(), _normals[i[5]-1].getZ());

		  Vertex vertex1(vec1, vec2);
		  Vertex vertex2(vec3, vec4);
		  Vertex vertex3(vec5, vec6);

		  _triangles.push_back(Triangle(vertex1, vertex2, vertex3, _lastMtl));
		}
	      else if(file.find("/")!=std::string::npos)
		{
		  unsigned int i[9];
		  sscanf(file.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &i[0],&i[1],&i[2], &i[3],&i[4],&i[5], &i[6],&i[7],&i[8]);

		  Vec3 vec1(_vertices[i[0]-1].getX(), _vertices[i[0]-1].getY(), _vertices[i[0]-1].getZ());
		  Vec2 vec2(_textures[i[1]-1].getX(), _textures[i[1]-1].getY());
		  Vec3 vec3(_normals[i[2]-1].getX(), _normals[i[2]-1].getY(), _normals[i[0]-1].getZ());

		  Vec3 vec4(_vertices[i[3]-1].getX(), _vertices[i[3]-1].getY(), _vertices[i[3]-1].getZ());
		  Vec2 vec5(_textures[i[4]-1].getX(), _textures[i[4]-1].getY());
		  Vec3 vec6(_normals[i[5]-1].getX(), _normals[i[5]-1].getY(), _normals[i[5]-1].getZ());

		  Vec3 vec7(_vertices[i[6]-1].getX(), _vertices[i[6]-1].getY(), _vertices[i[6]-1].getZ());
		  Vec2 vec8(_textures[i[7]-1].getX(), _textures[i[7]-1].getY());
		  Vec3 vec9(_normals[i[8]-1].getX(), _normals[i[8]-1].getY(), _normals[i[8]-1].getZ());

		  Vertex vertex1(vec1, vec3, vec2);
		  Vertex vertex2(vec4, vec6, vec5);
		  Vertex vertex3(vec7, vec9, vec8);

		  _triangles.push_back(Triangle(vertex1, vertex2, vertex3, _lastMtl));
		}
	      else
		{
		  unsigned int x,y,z;
		  sscanf(file.c_str(), "f %d %d %d", &x, &y, &z);

		  Vec3 vec1(_vertices[x-1].getX(), _vertices[x-1].getY(), _vertices[x-1].getZ());
		  Vec3 vec2(_vertices[y-1].getX(), _vertices[y-1].getY(), _vertices[y-1].getZ());
		  Vec3 vec3(_vertices[z-1].getX(), _vertices[z-1].getY(), _vertices[z-1].getZ());

		  Vertex vertex1(vec1);
		  Vertex vertex2(vec2);
		  Vertex vertex3(vec3);

		  _triangles.push_back(Triangle(vertex1, vertex2, vertex3, _lastMtl));
		}
	    }
	}
      Mesh *mesh = new Mesh(_triangles);
      _triangles.clear();
      _vertices.clear();
      _normals.clear();
      _textures.clear();
      return mesh;
    }
  else
    {
      Engine::getInstance()->getLogger().log("Unable to open " + file);
    }
}
