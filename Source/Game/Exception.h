#pragma once

class SDLException : public std::runtime_error
{
public:
	explicit SDLException(const char *function);

	// returns Name of function which caused an error
	std::string GetSDLFunction() const;

	// returns Stored result of SDL_GetError()
	// see http://wiki.libsdl.org/SDL_GetError
	std::string GetSDLError() const;

private:
	static std::string makeWhat(const char *sdl_function, const char *sdl_error);

	std::string m_sdlFunction;
	std::string m_sdlError;
};