
#pragma once
#include "SDL2\SDL.h"
#include "SDL2\SDL_mixer.h"

namespace sdl {
	class SDLMixer {
	public:
		SDLMixer(int flags = MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG);

		~SDLMixer();

	private:
		void printVersion();
	};
}