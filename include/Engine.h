#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <SDL2/SDL.h>
#include "MeshManager.h"
#include "MaterialManager.h"
#include "Renderer.h"
#include "VarManager.h"
#include "Logger.h"
#include "ObjLoader.h"

class Engine
{
 public:
  static Engine* getInstance();
  void launch();
  void exit();

  const Renderer& getRenderer() const;
    MeshManager& getMeshManager();
    MaterialManager& getMaterialManager();
    const VarManager& getVarManager() const;
    Logger& getLogger();
    ObjLoader& getObjLoader();

 private:
    Engine(const std::string& title, const unsigned int& width, const unsigned int& height);
    ~Engine();
    void mainLoop();

    static Engine *_instance;
    Renderer _renderer;
    MeshManager _meshManager;
    MaterialManager _materialManager;
    VarManager _varManager;
    Logger _logger;
    ObjLoader _objLoader;

    SDL_Window *_window;
    SDL_GLContext _glContext;
    SDL_Event _events;
    bool _isEnd;

    std::string _title;
    unsigned int _width;
    unsigned int _height;
};

#endif
