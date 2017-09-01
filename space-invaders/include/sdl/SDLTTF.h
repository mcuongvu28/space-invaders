
#pragma once
#include "SDL2\SDL.h"
#include "SDL2\SDL_ttf.h"

namespace sdl {
	class SDLTTF {
	public:
		SDLTTF();

		~SDLTTF();

	private:
		void printVersion();
	};
}