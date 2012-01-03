#include <SDL/SDL.h>
#include <string>
#include "Logger.h"
#include "Renderer.h"
#include "VarManager.h"

class EngineInstance
{
 public:
    EngineInstance(std::string &windowTitle, unsigned int &windowWidth, unsigned int &windowHeight);
    ~EngineInstance();
    void mainLoop();
 private:
    SDL_WindowID _window;
    SDL_GLContext _glContext;
    SDL_Event _events;
    bool _isEnd;
    int _startTime;
    int _time;
};
