
#pragma once
#include <string>
#include "SDL2\SDL_ttf.h"

namespace sdl {
	class Font {
	public:
		Font(std::string filename, int size);

		~Font();

		TTF_Font *get() const;

	private:
		TTF_Font *mFont;
	}; 
}
