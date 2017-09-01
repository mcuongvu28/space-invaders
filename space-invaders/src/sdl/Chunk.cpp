
#include "sdl\Chunk.h"
#include "sdl\log.h"
#include "sdl\error.h"

namespace sdl {
	Chunk::Chunk(std::string filename, int channel) {
		mChunk = Mix_LoadWAV(filename.c_str());
		if (mChunk == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to load WAV. Mix_LoadWAV: %s.", getError());
			clearError();
		}
	}

	Chunk::~Chunk() {
		if (mChunk != nullptr) {
			Mix_FreeChunk(mChunk);
			mChunk = nullptr;
		}	
	}

	int Chunk::getVolume() const {
		return Mix_VolumeChunk(mChunk, -1);
	}
	int Chunk::setVolume(int volume) const {
		return Mix_VolumeChunk(mChunk, volume);
	}

	int Chunk::getChannel() const {
		return mChannel;
	}

	void Chunk::setChannel(int channel) {
		mChannel = channel;
	}
	void Chunk::play(int loops) {
		if (Mix_PlayChannel(mChannel, mChunk, loops) == -1) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to play channel: %d. Mix_PlayChannel: %s.", mChannel, getError());
			clearError();
		}
	}
	
	bool Chunk::pause() {
		if (Mix_Paused(mChannel) == 1) return true;
		return false;
	}

	void Chunk::resume() {
		Mix_Resume(mChannel);
	}
}