#include "Engine.h"

int main()
{
  Engine* instance;
  instance = Engine::getInstance();
  std::string file = "Data/cube.obj";
  instance->getMeshManager().addMesh(instance->getObjLoader().load(file));
  instance->launch();
  instance->exit();

    return 0;
}
