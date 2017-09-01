
#include "sdl\Font.h"
#include "sdl\log.h"
#include "sdl\error.h"

namespace sdl {
	Font::Font(std::string filename, int size) {
		mFont = TTF_OpenFont(filename.c_str(), size);
		if (mFont == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to open font. TTF_OpenFont: %s.", getError());
			clearError();
		}
	}
	Font::~Font() {
		if (mFont != nullptr) {
			TTF_CloseFont(mFont);
			mFont = nullptr;
		}
	}

	TTF_Font *Font::get() const {
		if (mFont == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_WARN);
			warn(SDL_LOG_CATEGORY_APPLICATION, "Return null pointer.");
		}

		return mFont;
	}
}