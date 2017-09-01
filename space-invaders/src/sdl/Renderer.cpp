
#include "sdl\Renderer.h"
#include "sdl\log.h"
#include "sdl\error.h"

namespace sdl {
	Renderer::Renderer(Window *window, int index, uint32 flags) {
		mRenderer = SDL_CreateRenderer(window->getPtr(), index, flags);
		if (mRenderer == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to create renderer. SDL_CreateRenderer: %s.", getError());
			clearError();
		}
	}

	Renderer::~Renderer() {
		if (mRenderer != nullptr) {
			SDL_DestroyRenderer(mRenderer);
			mRenderer = nullptr;
		}
	}

	SDL_Renderer *Renderer::get() const {
		if (mRenderer == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_WARN);
			warn(SDL_LOG_CATEGORY_APPLICATION, "Return null pointer.");
		}

		return mRenderer;
	}

	Texture *Renderer::loadTexture(std::string filename) {
		SDL_Texture *texture = IMG_LoadTexture(mRenderer, filename.c_str());

		if (texture == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_WARN);
			warn(SDL_LOG_CATEGORY_APPLICATION, "Return null pointer.");
			return nullptr;
		}

		Texture *result = new Texture(texture);
		return result;
	}

	bool Renderer::renderTexture(Texture *texture, Rect *srcRect, Rect *desRect) {
		int result = SDL_RenderCopy(mRenderer, texture->get(), (SDL_Rect*)srcRect, (SDL_Rect*)desRect);
		if (result == 0) {
			return true;
		}

		return false;
	}

	bool Renderer::renderText(Texture *texture, Font *font, std::string text, Color color) {

		SDL_Surface *surface = TTF_RenderText_Solid(font->get(), text.c_str(), color);
		if (surface == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to create surface. TTF_RenderText_Solid: %s.", getError());
			return false;
		}

		SDL_Texture *lTexture = SDL_CreateTextureFromSurface(mRenderer, surface);
		if (lTexture == nullptr) {
			printFuncInfo(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR);
			error(SDL_LOG_CATEGORY_APPLICATION, "Failed to create texture. SDL_CreateTextureFromSurface: %s.", getError());
			return false;
		}

		texture->destroy();
		texture->set(lTexture);

		SDL_FreeSurface(surface);

		return true;
	}

	void Renderer::present() {
		SDL_RenderPresent(mRenderer);
	}

	void Renderer::clear() {
		SDL_RenderClear(mRenderer);
	}
}