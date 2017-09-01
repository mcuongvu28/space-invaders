
#pragma once
#include <string>
#include "SDL2\SDL_mixer.h"

namespace sdl {
	class Music {
	public:
		Music(std::string filename);

		~Music();

		int getVolume() const;

		int setVolume(int volume) const;

		bool play(int loops);

		bool pause();

		void resume();

	private:
		Mix_Music *mMusic = nullptr;
	};
}
