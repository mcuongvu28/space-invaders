
#pragma once
#include <string>
#include <functional>
#include "SDL2\SDL.h"

#define printFuncInfo(category, priority) message(category, priority, \
										      "FILE=%s FUNC=%s LINE=%d", __FILE__, __FUNCTION__, __LINE__);

namespace sdl {

	typedef SDL_LogPriority LogPriority;

	template<typename... Args>
	void log(std::string message, Args... args) {
		SDL_Log(message.c_str(), args...);
	}

	template<typename... Args>
	void critical(int category, std::string message, Args... args) {
		SDL_LogCritical(category, message.c_str(), args...);
	}

	template<typename... Args>
	void debug(int category, std::string message, Args... args) {
		SDL_LogDebug(category, message.c_str(), args...);
	}

	template<typename... Args>
	void error(int category, std::string message, Args... args) {
		SDL_LogError(category, message.c_str(), args...);
	}

	template<typename... Args>
	void info(int category, std::string message, Args... args) {
		SDL_LogInfo(category, message.c_str(), args...);
	}

	template<typename... Args>
	void message(int category, LogPriority priority, std::string message, Args... args) {
		SDL_LogMessage(category, priority, message.c_str(), args...);
	}

	template<typename... Args>
	void verbose(int category, std::string message, Args... args) {
		SDL_LogVerbose(category, message.c_str(), args...);
	}

	template<typename... Args>
	void warn(int category, std::string message, Args... args) {
		SDL_LogWarn(category, message.c_str(), args...);
	}
}

