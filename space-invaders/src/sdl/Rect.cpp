
#include "sdl\Rect.h"

namespace sdl {
	Rect::Rect() {
		reset();
	}

	Rect::Rect(int x, int y, int w, int h) {
		SDL_Rect::x = x;
		SDL_Rect::y = y;
		SDL_Rect::w = w;
		SDL_Rect::h = h;
	}

	Rect::Rect(Rect *rect) {
		SDL_Rect::x = rect->x;
		SDL_Rect::y = rect->y;
		SDL_Rect::w = rect->w;
		SDL_Rect::h = rect->h;
	}

	Rect::~Rect() {
		reset();
	}


	void Rect::reset() {
		SDL_Rect::x = 0;
		SDL_Rect::y = 0;
		SDL_Rect::w = 0;
		SDL_Rect::h = 0;
	}

	Rect &Rect::operator=(const Rect &other) {
		if (this == &other) return *this;
		// TODO: Finish case other == null
		if (&other == nullptr) { }
		SDL_Rect::x = other.x;
		SDL_Rect::y = other.y;
		SDL_Rect::w = other.w;
		SDL_Rect::h = other.h;


		return *this;
	}
}