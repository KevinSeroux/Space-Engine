#include "Engine.h"

Engine *Engine::_instance = 0;

Engine::Engine(const std::string& title = "", const unsigned int& width = 800, const unsigned int& height = 600)
{
  _title = title;
  _width = width;
  _height = height;
}

Engine::~Engine()
{
  SDL_GL_DeleteContext(_glContext);
  SDL_DestroyWindow(_window);
  SDL_Quit();
  if(_instance != 0)
    delete _instance;
}

void Engine::launch()
{
  _window = 0;
    _glContext = 0;
    _isEnd = false;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      _logger.log("Error while SDL initialization : " + _varManager.convertToString(SDL_GetError()));
      delete this;
    }
    //OpenGL 3.1
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    //Double buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //zBuffer
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    _window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			       _width, _height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    _glContext = SDL_GL_CreateContext(_window);

#ifdef WIN32
    GLenum initGLEW(glewInit());
    if(initGLEW != GLEW_OK)
    {
      _logger.log("Error while GLEW initialization : " + glewGetErrorString(initGLEW));
      delete this;
    }
#endif

    while(!_isEnd)
    {
	mainLoop();
    }
}

void Engine::exit()
{
  delete this;
}

Engine* Engine::getInstance()
{
  if(_instance == 0)
    _instance = new Engine;
  return _instance;
}

void Engine::mainLoop()
{
    _renderer.render();

    SDL_GL_SwapWindow(_window); //Refresh glContext

    SDL_WaitEvent(&_events);
    if(_events.window.event == SDL_WINDOWEVENT_CLOSE)
	_isEnd = true;
}

const Renderer& Engine::getRenderer() const
{
  return _renderer;
}

MeshManager& Engine::getMeshManager()
{
  return _meshManager;
}

MaterialManager& Engine::getMaterialManager()
{
  return _materialManager;
}

const VarManager& Engine::getVarManager() const
{
  return _varManager;
}

Logger& Engine::getLogger()
{
  return _logger;
}

ObjLoader& Engine::getObjLoader()
{
  return _objLoader;
}
