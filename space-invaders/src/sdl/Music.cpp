
#include "sdl\Music.h"
#include "sdl\log.h"
#include "sdl\error.h"

namespace sdl {
	Music::Music(std::string filename) {
		mMusic = Mix_LoadMUS(filename.c_str());
		if (mMusic == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to load music. Mix_LoadMUS: %s.", getError());
			clearError();
		}
	}

	Music::~Music() {
		if (mMusic != nullptr) {
			Mix_FreeMusic(mMusic);
			mMusic = nullptr;
		}
	}

	int Music::getVolume() const {
		return Mix_VolumeMusic(-1);
	}

	int Music::setVolume(int volume) const {
		return Mix_VolumeMusic(volume);
	}

	bool Music::play(int loops) {
		if (Mix_PlayMusic(mMusic, loops) == -1) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_WARN);
			warn(SDL_LOG_CATEGORY_APPLICATION, "Failed to play music. Mix_PlayMusic: %s.", getError());
			return false;
		}

		return true;
	}

	bool Music::pause() {
		if (Mix_PausedMusic() == 1) return true;
		return false;
	}

	void Music::resume() {
		Mix_ResumeMusic();
	}
}