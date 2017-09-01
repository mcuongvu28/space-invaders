
#pragma once
#include <string>
#include "SDL2\SDL_mixer.h"

namespace sdl {
	class Chunk {
	public:
		Chunk(std::string filename, int channel = -1);

		~Chunk();

		int getVolume() const;

		int setVolume(int volume) const;

		int getChannel() const;

		void setChannel(int channel);

		void play(int loops);

		bool pause();

		void resume();

	private:
		int		  mChannel;
		Mix_Chunk *mChunk;
	};
}
