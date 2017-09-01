
#pragma once
#include "SDL2\SDL.h"

namespace sdl {
	struct Point : public SDL_Point {
		Point(int x, int y);
	};
}
