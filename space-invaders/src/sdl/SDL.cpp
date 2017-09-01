
#include "sdl\SDL.h"
#include "sdl\log.h"
#include "sdl\error.h"

namespace sdl {
	SDL::SDL(uint32 flags) {
		if (SDL_Init(flags) != 0) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize SDL library. SDL_Init: %s.", getStringError());
			return;
		}

		printVersion();
	}

	SDL::~SDL() {
		SDL_Quit();
	}

	void SDL::printVersion() {
		SDL_version compiled;
		SDL_version linked;

		SDL_VERSION(&compiled);
		SDL_GetVersion(&linked);

		log("SDL version:\n -compiled: %d.%d.%d\n -linked:   %d.%d.%d\n\n",
			compiled.major, compiled.minor, compiled.patch,
			linked.major, linked.minor, linked.patch);

	}
}