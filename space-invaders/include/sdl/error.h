
#pragma once
#include <string>
#include "SDL2\SDL.h"

namespace sdl {
	template<typename... Agrs>
	void setError(std::string message, Agrs... agrs) {
		SDL_SetError(message, agrs...);
	}

	const char *getError();

	std::string getStringError();

	void clearError();
}


