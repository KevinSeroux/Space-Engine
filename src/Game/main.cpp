#include "Engine.h"
#include "Mesh.h"
#include <iostream>

int main()
{
  Engine* instance = Engine::getInstance();
  std::string file = "Data/cube.obj";
  Mesh *mesh = instance->getObjLoader().load(file);
  instance->getMeshManager().addMesh(mesh);
  instance->launch();
  instance->exit();

  return 0;
}
