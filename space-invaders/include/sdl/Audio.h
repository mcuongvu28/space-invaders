
#pragma once
#include "SDL2\SDL_mixer.h"
#include "typedef.h"

namespace sdl {
	class Audio {
	public:
		Audio(int frequency, uint16 format, int channel, int chunkSize);

		~Audio();

		bool isPlayingMusic() const;

		bool isPlayingChannel(int channel) const;
	};
}
