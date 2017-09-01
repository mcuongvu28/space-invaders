
#include "sdl\error.h"

namespace sdl {
	const char *getError() {
		return SDL_GetError();
	}
	std::string getStringError() {
		std::string result = SDL_GetError();
		return result;
	}

	void clearError() {
		SDL_ClearError();
	}
}