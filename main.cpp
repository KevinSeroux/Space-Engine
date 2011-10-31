#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "Mesh.h"

#define WIDTH 800
#define HEIGHT 600

Mesh myMesh;

void Draw(const int& xPos, const int& yPos, const int& zPos);

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("SDL GL Application", NULL);
    SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_OPENGL);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70,(double)WIDTH/HEIGHT,1,1000);

    SDL_EnableKeyRepeat(10,10);

    SDL_Event events;
    int xPos(3);
    int yPos(4);
    int zPos(2);

    //Variables pour les perfs
    int startTime;
    float time;
    int startTimeFPS = SDL_GetTicks();

    //Notre mesh
    myMesh.ImportObj("Data/cubecolor.obj");

    while(SDL_WaitEvent(&events))
    {
	startTime = SDL_GetTicks();

	switch(events.type)
	{
	case SDL_QUIT:
	    exit(0);
	    break;
	case SDL_KEYDOWN:
	    switch(events.key.keysym.sym)
	    {
	    case SDLK_UP:
		yPos+=1;
		break;
	    case SDLK_DOWN:
		yPos-=1;
		break;
	    case SDLK_LEFT:
		xPos+=1;
		break;
	    case SDLK_RIGHT:
		xPos-=1;
		break;
	    case SDLK_z:
		zPos+=1;
		break;
	    case SDLK_s:
		zPos-=1;
		break;
	    }
	    break;
	}
	Draw(xPos,yPos,zPos);

	time=(SDL_GetTicks()-startTime)*0.001;
	if(SDL_GetTicks() - startTimeFPS >= 1000)
	{
	    std::cout << "Temps : " << time << "  |  FPS : " << floor(1/time) << "  |  Cam : " << xPos << ";" << yPos << ";" << zPos << std::endl;
	}
    }
    return 0;
}

void Draw(const int& xPos, const int& yPos, const int& zPos)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(xPos,yPos,zPos,0,0,0,0,0,1);

    myMesh.Draw();

    glFlush();
    SDL_GL_SwapBuffers();
}
