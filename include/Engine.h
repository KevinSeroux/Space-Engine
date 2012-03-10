#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <SDL2/SDL.h>
#include "MeshManager.h"
#include "MaterialManager.h"
#include "Renderer.h"
#include "VarManager.h"
#include "Logger.h"

class Engine
{
 public:
  static Engine& getInstance();

    const Renderer& getRenderer() const;
    MeshManager& getMeshManager();
    MaterialManager& getMaterialManager();
    const VarManager& getVarManager() const;
    const Logger& getLogger() const;
 private:
    Engine(const std::string &windowTitle, const unsigned int &windowWidth, const unsigned int &windowHeight);
    ~Engine();

    void mainLoop();

    static Engine _instance;
    Renderer _renderer;
    MeshManager _meshManager;
    MaterialManager _materialManager;
    VarManager _varManager;
    Logger _logger;

    SDL_Window *_window;
    SDL_GLContext _glContext;
    SDL_Event _events;
    bool _isEnd;
    int _startTime;
    int _time;
};

#endif
