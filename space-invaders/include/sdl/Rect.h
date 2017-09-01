
#pragma once
#include "SDL2\SDL.h"

namespace sdl {
	struct Rect : public SDL_Rect {
		Rect();

		Rect(int x, int y, int w, int h);

		Rect(Rect *rect);

		~Rect();

		void reset();

		Rect &operator=(const Rect &other);
	};
}