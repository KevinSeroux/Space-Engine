#include <SDL.h>
#include <string>

class EngineInstance
{
 public:
    EngineInstance(std::string &windowTitle, int &windowWidth, int &windowHeight);
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
