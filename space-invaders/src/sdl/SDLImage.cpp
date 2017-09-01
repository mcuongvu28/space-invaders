
#include "sdl\SDLImage.h"
#include "sdl\log.h"
#include "sdl\error.h"

namespace sdl {
	SDLImage::SDLImage(int flags) {
		if (IMG_Init(flags) & flags != flags) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize SDL Image library. IMG_Init: %s.", getError());
			return;
		}

		printVersion();
	}

	SDLImage::~SDLImage() {
		IMG_Quit();
	}

	void SDLImage::printVersion() {
		SDL_version compiled;
		const SDL_version *linked = IMG_Linked_Version();
		SDL_IMAGE_VERSION(&compiled);

		log("SDL Image version:\n -compiled: %d.%d.%d\n -linked:   %d.%d.%d\n\n",
			compiled.major, compiled.minor, compiled.patch,
			linked->major, linked->minor, linked->patch);
	}
}