#include "stdafx.h"
#include "Texture.h"
#include "Renderer.h"

//-----------------------------------------------------------------------------
Texture::Texture(const std::string &file)
{
	static auto &renderer = GetModule<Renderer>();

	if ((m_texture = IMG_LoadTexture(renderer.GetRender(), file.c_str())) == nullptr)
		throw SDLException("IMG_LoadTexture");

	if (SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect.w, &m_rect.h) < 0)
		throw SDLException("SDL_QueryTexture");
}
//-----------------------------------------------------------------------------
Texture::Texture(int width, int height, Color color)
{
	const auto sdlSurface = std::make_unique<Surface>(width, height, 32, 0, 0, 0, 0);
	const auto sdlSurfaceObject = sdlSurface->Get();
	const auto rgbUint = SDL_MapRGB(sdlSurfaceObject->format, color.r, color.g, color.b);
	sdlSurface->FillRect(NullOpt, rgbUint);
	loadTextureFromSurface(*sdlSurface);
}
//-----------------------------------------------------------------------------
Texture::~Texture()
{
	SDL_DestroyTexture(m_texture);
}
//-----------------------------------------------------------------------------
int Texture::Width() const
{
	return m_rect.w;
}
//-----------------------------------------------------------------------------
int Texture::Height() const
{
	return m_rect.h;
}
//-----------------------------------------------------------------------------
void Texture::loadTextureFromSurface(const Surface &surface)
{
	static auto &renderer = GetModule<Renderer>();

	m_texture = SDL_CreateTextureFromSurface(renderer.GetRender(), surface.Get());
	if (nullptr == m_texture)
		throw std::runtime_error(SDL_GetError());

	if (SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect.w, &m_rect.h) < 0)
		throw SDLException("SDL_QueryTexture");
}
//-----------------------------------------------------------------------------