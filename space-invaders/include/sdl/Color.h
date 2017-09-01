
#pragma once
#include "SDL.h"
#include "typedef.h"

namespace sdl {
	struct Color : public SDL_Color {
		Color();

		Color(uint8 r, uint8 g, uint8 b, uint8 a);
	};
}
