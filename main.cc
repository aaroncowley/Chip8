#include <map>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

//#include "chip8.hh"


/* important globals */
static const int width = 640;
static const int height = 320;
static const int opcodesPerSecond = 400;


bool CreateWindow() {
    /* gimme muh window */
	if( SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
		return false; 
	} else if(SDL_CreateWindow("CRUS4D3R CHIP-8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
	                           width, height, SDL_WINDOW_OPENGL) == NULL) {
		return false; 
	} 

    /* openGL init stuff */
	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1.0, 1.0);
	glClearColor(0, 0, 0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glShadeModel(GL_FLAT);

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glDisable(GL_DITHER);
	glDisable(GL_BLEND);

	return true;
}



int main(int argc, char **argv) {
    CreateWindow();
    // testing for window creation this will go away 
    std::this_thread::sleep_for(std::chrono::seconds(10));
    //
    SDL_Quit(); 
}
