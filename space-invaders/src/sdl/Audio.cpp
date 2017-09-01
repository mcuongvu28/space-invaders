
#include "sdl\Audio.h"
#include "sdl\log.h"
#include "sdl\error.h"

namespace sdl {
	Audio::Audio(int frequency, uint16 format, int channel, int chunkSize) {
		if (Mix_OpenAudio(frequency, format, channel, chunkSize) == -1) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to open audio. Mix_OpenAudio: %s.", getError());
			clearError();
		}
	}

	Audio::~Audio() {
		Mix_CloseAudio();
	}
	bool Audio::isPlayingMusic() const {
		if (Mix_PlayingMusic() == 0) return false;
		return true;
	}

	bool Audio::isPlayingChannel(int channel) const {
		if (Mix_Playing(channel) == 0) return false;
		return true;
	}
}