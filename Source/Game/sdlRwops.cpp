#include "stdafx.h"
#include "sdlRwops.h"

//-----------------------------------------------------------------------------
SdlRwops::SdlRwops(const void *data, size_t dataSize)
{
	m_rwops = SDL_RWFromConstMem(data, (int)dataSize);
	if (nullptr == m_rwops)
		throw std::runtime_error(SDL_GetError());
}
//-----------------------------------------------------------------------------
void* SdlRwops::InternalObject() const
{
	return m_rwops;
}
//-----------------------------------------------------------------------------