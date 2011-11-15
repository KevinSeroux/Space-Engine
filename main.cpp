#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include "Mesh.h"
#include "Camera.h"

#define WIDTH 800
#define HEIGHT 600

void Draw();

Camera cam(Vec3(0,0,0),Vec3(0,0,0));
Mesh myMesh;
GLuint texture1;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("SDL GL Application", NULL);
    SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_OPENGL);

    glEnable(GL_DEPTH_TEST); //Activate Z-Buffer
    glEnable(GL_LIGHTING); //Activate lighting
    glEnable(GL_LIGHT0); //Switch on light0

    glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70,(double)WIDTH/HEIGHT,1,1000);

    SDL_EnableKeyRepeat(10,10);

    SDL_Event events;
    float speed = 1;

    //Variables pour les perfs
    int startTime;
    float time;
    int startTimeFPS = SDL_GetTicks();

    //Notre mesh
    myMesh.importObj("Data/ship.obj");

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
	    case SDLK_z:
		cam.setPos(Vec3(cam.getPos().getX(),cam.getPos().getY(),cam.getPos().getZ()-speed));
		break;
	    case SDLK_s:
		cam.setPos(Vec3(cam.getPos().getX(),cam.getPos().getY(),cam.getPos().getZ()+speed));
		break;
	    case SDLK_q:
		cam.setPos(Vec3(cam.getPos().getX()-speed,cam.getPos().getY(),cam.getPos().getZ()));
		break;
	    case SDLK_d:
		cam.setPos(Vec3(cam.getPos().getX()+speed,cam.getPos().getY(),cam.getPos().getZ()));
		break;
	    case SDLK_SPACE:
		cam.setPos(Vec3(cam.getPos().getX(),cam.getPos().getY()+speed,cam.getPos().getZ()));
		break;
	    case SDLK_c:
		cam.setPos(Vec3(cam.getPos().getX(),cam.getPos().getY()-speed,cam.getPos().getZ()));
		break;
	    }
	    break;
	}
	Draw();

	time=(SDL_GetTicks()-startTime)*0.001;
	if(SDL_GetTicks() - startTimeFPS >= 1000)
	{
	    std::cout << "Temps : " << time << "  |  FPS : " << floor(1/time) << "  |  Cam : " << cam.getPos().getX() << ";" << cam.getPos().getY() << ";" << cam.getPos().getZ() << std::endl;
	}
    }
    return 0;
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    cam.place();
    myMesh.draw();

    glFlush();
    SDL_GL_SwapBuffers();
}
