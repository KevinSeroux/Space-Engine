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

#ifndef RENDERER_H
#define RENDERER_H

#ifdef WIN32
#include <GL3/glew.h>
#else
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>
#endif

#include <vector>
#include <iostream>

class Engine; //Protection against circular inclusions

class Renderer
{
 public:
    Renderer();
    ~Renderer();
    void render();
    void renderVAO();
    void renderVBO();
 private:
    GLuint _buffer;
};

#endif
