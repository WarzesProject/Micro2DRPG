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
#if 1
	static auto *renderer = GetModule<Renderer>().GetRender();

	TODO("попробовать настроить поле с SDL_TEXTUREACCESS_TARGET и с SDL_PIXELFORMAT_RGBA8888");

	m_texture = SDL_CreateTexture(renderer,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET,
		width, height);
	if (m_texture == nullptr)
		throw SDLException("IMG_LoadTexture");

	if (SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect.w, &m_rect.h) < 0)
		throw SDLException("SDL_QueryTexture");

	SDL_SetRenderTarget(renderer, m_texture);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, nullptr);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_SetRenderTarget(renderer, nullptr);
#else // через Surface
	TODO("переделать в SDL_CreateTexture");

	const auto sdlSurface = std::make_unique<Surface>(width, height, 32, 0, 0, 0, 0);
	const auto sdlSurfaceObject = sdlSurface->Get();
	const auto rgbUint = SDL_MapRGB(sdlSurfaceObject->format, color.r, color.g, color.b);
	sdlSurface->FillRect(NullOpt, rgbUint);
	loadTextureFromSurface(*sdlSurface);
#endif
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
//void Texture::loadTextureFromSurface(const Surface &surface)
//{
//	static auto &renderer = GetModule<Renderer>();
//
//	m_texture = SDL_CreateTextureFromSurface(renderer.GetRender(), surface.Get());
//	if (nullptr == m_texture)
//		throw std::runtime_error(SDL_GetError());
//
//	if (SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect.w, &m_rect.h) < 0)
//		throw SDLException("SDL_QueryTexture");
//}
//-----------------------------------------------------------------------------