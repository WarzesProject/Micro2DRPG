#include "stdafx.h"
#include "Surface.h"

//-----------------------------------------------------------------------------
Surface::LockHandle::LockHandle(Surface *surface) 
	: m_surface(surface) 
{
	if (SDL_MUSTLOCK(m_surface->Get()))
	{
		if (SDL_LockSurface(m_surface->Get()))
			throw SDLException("SDL_LockSurface");
	}
}
//-----------------------------------------------------------------------------
Surface::LockHandle::LockHandle(Surface::LockHandle &&other) noexcept 
	: m_surface(other.m_surface)
{
	other.m_surface = nullptr;
}
//-----------------------------------------------------------------------------
Surface::LockHandle& Surface::LockHandle::operator=(Surface::LockHandle &&other) noexcept
{
	if (&other == this)
		return *this;

	if (m_surface != nullptr) 
	{
		if (SDL_MUSTLOCK(m_surface->Get()))
			SDL_UnlockSurface(m_surface->Get());
	}

	m_surface = other.m_surface;

	other.m_surface = nullptr;

	return *this;
}
//-----------------------------------------------------------------------------
Surface::LockHandle::~LockHandle()
{
	if (m_surface != nullptr) 
	{
		if (SDL_MUSTLOCK(m_surface->Get()))
			SDL_UnlockSurface(m_surface->Get());
	}
}
//-----------------------------------------------------------------------------
void* Surface::LockHandle::GetPixels() const
{
	return m_surface->Get()->pixels;
}
//-----------------------------------------------------------------------------
int Surface::LockHandle::GetPitch() const 
{
	return m_surface->Get()->pitch;
}
//-----------------------------------------------------------------------------
const SDL_PixelFormat& Surface::LockHandle::GetFormat() const 
{
	return *m_surface->Get()->format;
}
//-----------------------------------------------------------------------------