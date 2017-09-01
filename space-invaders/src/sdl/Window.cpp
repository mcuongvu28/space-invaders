
#include "sdl\Window.h"
#include "sdl\log.h"
#include "sdl\error.h"

namespace sdl {
	Window::Window(std::string title, int width, int height, uint32 flags) {
		mWindow = SDL_CreateWindow(title.c_str(), 
								   SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
								   width, height, flags);

		if (mWindow == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to create window. SDL_CreateWindow: %s.", __FUNCTION__, __LINE__, getError());
			clearError();
		}
	}

	Window::~Window() {
		SDL_DestroyWindow(mWindow);
	}

	SDL_Window *Window::getPtr() const {
		if (mWindow == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_WARN);
			warn(SDL_LOG_CATEGORY_APPLICATION, "Function: %s - Line: %d - Message: Return null pointer.", __FUNCTION__, __LINE__);
		}

		return mWindow;
	}
}