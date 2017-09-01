
#pragma once
#include "typedef.h"

namespace sdl {
	class SDL {
	public:
		SDL(uint32 flags = SDL_INIT_EVERYTHING);

		~SDL();

	private:
		void printVersion();
	};
}
