
#pragma once
#include "SDL2\SDL.h"
#include "SDL2\SDL_image.h"

namespace sdl {
	class Texture {
	public:
		Texture();

		Texture(SDL_Texture *texture);

		~Texture();

		void destroy();

		void set(SDL_Texture *texture);

		SDL_Texture *get() const;

	private:
		SDL_Texture *mTexture = nullptr;
	};
}
