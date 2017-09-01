
#include "sdl\Point.h"

namespace sdl {
	Point::Point(int x, int y) {
		SDL_Point::x = x;
		SDL_Point::y = y;
	}
}