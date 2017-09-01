
#include "sdl\SDLMixer.h"
#include "sdl\log.h"
#include "sdl\error.h"

namespace sdl {
	SDLMixer::SDLMixer(int flags) {
		if (Mix_Init(flags) & flags != flags) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize SDL Mixer library. Mix_Init: %s.", getError());
			return;
		}

		printVersion();
	}

	SDLMixer::~SDLMixer() {
		Mix_Quit();
	}

	void SDLMixer::printVersion() {
		SDL_version compiled;
		const SDL_version *linked = Mix_Linked_Version();
		SDL_MIXER_VERSION(&compiled);

		log("SDL Mixer version:\n -compiled: %d.%d.%d\n -linked:   %d.%d.%d\n\n",
			compiled.major, compiled.minor, compiled.patch,
			linked->major, linked->minor, linked->patch);
	}
}