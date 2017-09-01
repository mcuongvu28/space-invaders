
#include <cstdio>
#include <iostream>
#include <string>
#include "sdl\header.h"

int main(int argc, char* argv[]) {
	sdl::SDL *sdl = new sdl::SDL();
	sdl::SDLImage *sdlImage = new sdl::SDLImage(IMG_INIT_JPG | IMG_INIT_PNG);
	sdl::SDLTTF *ttf = new sdl::SDLTTF(); 
	sdl::SDLMixer *mixer = new sdl::SDLMixer();

	sdl::Window *window = new sdl::Window("Untitled", 800, 600);
	sdl::Renderer *renderer = new sdl::Renderer(window, -1, SDL_RENDERER_ACCELERATED);

	return 0;
}

