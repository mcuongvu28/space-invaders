
#pragma once
#include "SDL2\SDL.h"
#include "Window.h"
#include "Texture.h"
#include "Rect.h"
#include "Font.h"
#include "Color.h"

namespace sdl {
	class Renderer {
	public:
		Renderer(Window *window, int index = -1, uint32 flags = 0);

		~Renderer();

		SDL_Renderer *get() const;

		Texture *loadTexture(std::string filename);

		bool renderTexture(Texture *texture, Rect *srcRect, Rect *desRect);

		bool renderText(Texture *texture, Font *font, std::string text, Color color);

		void present();

		void clear();

	private:
		SDL_Renderer *mRenderer = nullptr;
	};
}
