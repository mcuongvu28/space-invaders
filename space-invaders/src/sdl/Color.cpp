
#include "sdl\Color.h"

namespace sdl {
	Color::Color() {
		SDL_Color::r = (uint8)0;
		SDL_Color::g = (uint8)0;
		SDL_Color::b = (uint8)0;
		SDL_Color::a = (uint8)0;
	}

	Color::Color(uint8 r, uint8 g, uint8 b, uint8 a) {
		SDL_Color::r = r;
		SDL_Color::g = g;
		SDL_Color::b = b;
		SDL_Color::a = a;
	}
}