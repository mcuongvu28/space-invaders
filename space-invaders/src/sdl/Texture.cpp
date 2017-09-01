
#include "sdl\Texture.h"
#include "sdl\log.h"

namespace sdl {
	Texture::Texture() {

	}

	Texture::Texture(SDL_Texture *texture) {
		mTexture = texture;
	}

	Texture::~Texture() {
		destroy();
	}

	void Texture::destroy() {
		if (mTexture != nullptr) {
			SDL_DestroyTexture(mTexture);
			mTexture = nullptr;
		}
	}

	void Texture::set(SDL_Texture *texture) {
		if (texture == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_WARN);
			warn(SDL_LOG_CATEGORY_APPLICATION, "The texture parameter is null pointer. Cannot set new texture value.");
			return;
		}

		destroy();
		mTexture = texture;
	}

	SDL_Texture *Texture::get() const {
		if (mTexture == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_WARN);
			warn(SDL_LOG_CATEGORY_APPLICATION, "Return null pointer.");
		}

		return mTexture;
	}
}