#include "stdafx.h"
#include "Exception.h"

//-----------------------------------------------------------------------------
SDLException::SDLException(const char *function)
	: std::runtime_error(makeWhat(function, SDL_GetError()))
	, m_sdlFunction(function)
	, m_sdlError(SDL_GetError())
{
}
//-----------------------------------------------------------------------------
std::string SDLException::GetSDLFunction() const
{
	return m_sdlFunction;
}
//-----------------------------------------------------------------------------
std::string SDLException::GetSDLError() const
{
	return m_sdlError;
}
//-----------------------------------------------------------------------------
std::string SDLException::makeWhat(const char *function, const char *sdlError)
{
	std::string tmp(function);
	tmp += " failed: ";
	tmp += sdlError;
	return tmp;
}
//-----------------------------------------------------------------------------