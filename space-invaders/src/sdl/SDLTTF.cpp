
#include "sdl\SDLTTF.h"
#include "sdl\log.h"
#include "sdl\error.h"

namespace sdl {
	SDLTTF::SDLTTF() {
		if (!TTF_WasInit() && TTF_Init() == -1) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize SDL TTF library. TTF_Init: %s.", getError());
			return;
		}

		printVersion();
	}

	SDLTTF::~SDLTTF() {
		TTF_Quit();
	}

	void SDLTTF::printVersion() {
		SDL_version compiled;
		const SDL_version *linked = TTF_Linked_Version();
		SDL_TTF_VERSION(&compiled);

		log("SDL TTF version:\n -compiled: %d.%d.%d\n -linked:   %d.%d.%d\n\n",
			compiled.major, compiled.minor, compiled.patch,
			linked->major, linked->minor, linked->patch);
	}
}