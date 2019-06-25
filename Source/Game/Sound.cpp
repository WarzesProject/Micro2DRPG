#include "stdafx.h"
#include "Sound.h"
#include "sdlRwops.h"

//-----------------------------------------------------------------------------
Sound::Sound(const std::string &file)
{
	m_chunk = Mix_LoadWAV(file.c_str());
	if (nullptr == m_chunk)
		throw std::runtime_error(Mix_GetError());
}
//-----------------------------------------------------------------------------
Sound::Sound(const void *data, size_t dataSize)
{
	const auto sdlRwops = std::make_unique<SdlRwops>(data, dataSize);

	m_chunk = Mix_LoadWAV_RW((SDL_RWops *)sdlRwops->InternalObject(), 1);
	if (nullptr == m_chunk)
		throw std::runtime_error(Mix_GetError());
}
//-----------------------------------------------------------------------------
Sound::~Sound()
{
	Mix_FreeChunk(m_chunk);
}
//-----------------------------------------------------------------------------
void Sound::Play(bool loop) const
{
	Mix_PlayChannel(MIX_DEFAULT_CHANNELS, m_chunk, loop ? 1 : 0);
}
//-----------------------------------------------------------------------------