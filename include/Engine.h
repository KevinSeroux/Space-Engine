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
    void setWindowParameters(const std::string& title, const unsigned int width, const unsigned int height);
    void launch();
    void exit();

    const Renderer& getRenderer() const;
    MeshManager& getMeshManager();
    MaterialManager& getMaterialManager();
    const VarManager& getVarManager() const;
    Logger& getLogger();
    ObjLoader& getObjLoader();

private:
    Engine();
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
