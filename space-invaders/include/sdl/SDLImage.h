
#pragma once
#include "SDL2\SDL.h"
#include "SDL2\SDL_image.h"

namespace sdl {
	class SDLImage {
	public:
		SDLImage(int flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP);

		~SDLImage();

	private:
		void printVersion();
	};
}
