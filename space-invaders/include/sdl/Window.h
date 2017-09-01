
#pragma once
#include <string>
#include "SDL2\SDL.h"
#include "typedef.h"

namespace sdl {
	class Window {
	public:
		Window(std::string title, int width, int height, uint32 flags = 0);

		~Window();

		SDL_Window *getPtr() const;

	private:
		SDL_Window *mWindow = nullptr;
	};
}
