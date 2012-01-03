#include "EngineInstance.h"

EngineInstance::EngineInstance(std::string &windowTitle, unsigned int &windowWidth, unsigned int &windowHeight)
{
    _window = 0;
    _glContext = 0;
    _isEnd = false;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
	Logger::displayMessage("Error while SDL initialization : " + VarManager::convertToString(SDL_GetError()));
	delete this;
    }
    //OpenGL 3.1
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    //Double buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //zBuffer
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    _window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			       windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    _glContext = SDL_GL_CreateContext(_window);

#ifdef WIN32
    GLenum initGLEW(glewInit());
    if(initGLEW != GLEW_OK)
    {
	Logger::DisplayMessage("Error while GLEW initialization : " + glewGetErrorString(initGLEW));
	delete this;
    }
#endif

    while(!_isEnd)
    {
	mainLoop();
    }

    delete this;
}

EngineInstance::~EngineInstance()
{
    SDL_GL_DeleteContext(_glContext);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void EngineInstance::mainLoop()
{
    SDL_WaitEvent(&_events);
    if(_events.window.event == SDL_WINDOWEVENT_CLOSE)
	_isEnd = true;

    _startTime = SDL_GetTicks();

    Renderer::render();
    SDL_GL_SwapWindow(_window); //Refresh glContext

    _time=(SDL_GetTicks()-_startTime)*0.001;
    if(SDL_GetTicks()-_startTime >= 1000)
	Logger::displayMessage("Time: " + VarManager::convertToString(time) + "  |  FPS: " +
			       VarManager::convertToString(1/_time));
}
