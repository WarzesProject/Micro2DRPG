#include "stdafx.h"
#include "Renderer.h"
#include "Window.h"
#include "Texture.h"
#include "Text.h"

//-----------------------------------------------------------------------------
Renderer::Renderer()
{
	auto &window = GetModule<Window>();
	const auto sdlWindow = window.m_window;

	const Uint32 flags = SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/;

	m_renderer = SDL_CreateRenderer(sdlWindow, -1, flags);
	if (nullptr == m_renderer)
		throw SDLException("SDL_CreateRenderer");

	valid() = true;
}
//-----------------------------------------------------------------------------
Renderer::~Renderer()
{
	SDL_DestroyRenderer(m_renderer);
}
//-----------------------------------------------------------------------------
void Renderer::Clear()
{
	SetRenderColor(m_clearColor);
	if (SDL_RenderClear(m_renderer) != 0)
		throw SDLException("SDL_RenderClear");
}
//-----------------------------------------------------------------------------
void Renderer::Present()
{
	SDL_RenderPresent(m_renderer);
}
//-----------------------------------------------------------------------------
void Renderer::SetClearColor(Color color)
{
	m_clearColor = color;
}
//-----------------------------------------------------------------------------
void Renderer::SetRenderColor(Color color) const
{
	if (SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a) < 0)
		throw std::runtime_error(SDL_GetError());
}
//-----------------------------------------------------------------------------
void Renderer::RenderTexture(int x, int y, const Texture &texture) const
{
	RenderTexture(x, y, texture, 0.0);
}
//-----------------------------------------------------------------------------
void Renderer::RenderTexture(int x, int y, const Texture &texture, double angle) const
{
	const auto sdlTexture = texture.m_texture;

	SDL_Rect rect{};
	rect.x = x;
	rect.y = y;
	rect.w = texture.Width();
	rect.h = texture.Height();

	const SDL_Point pivot{ 0, 0 };

	SDL_RenderCopyEx(m_renderer, sdlTexture, nullptr, &rect, angle, &pivot, SDL_FLIP_NONE);
}
//-----------------------------------------------------------------------------
void Renderer::RenderTexture(int x, int y, const Texture &texture, const Rect &clip) const
{
	const auto sdlTexture = texture.m_texture;

	const SDL_Rect rect{ x, y, clip.w, clip.h };
	const SDL_Rect sdlClip{ clip.x, clip.y, clip.w, clip.h };
	SDL_RenderCopy(m_renderer, sdlTexture, &sdlClip, &rect);
}
//-----------------------------------------------------------------------------
void Renderer::RenderText(int x, int y, const Text &text) const
{
	const auto sdlTexture = text.m_texture;
	const SDL_Rect rect{ x, y, text.m_rect.w, text.m_rect.h };
	SDL_RenderCopy(m_renderer, sdlTexture, nullptr, &rect);
}
//-----------------------------------------------------------------------------
void Renderer::RenderLine(float x1, float y1, float x2, float y2, Color color) const
{
	SetRenderColor(color);

	if (SDL_RenderDrawLine(m_renderer, (int)x1, (int)y1, (int)x2, (int)y2) < 0)
		throw std::runtime_error(SDL_GetError());
}
//-----------------------------------------------------------------------------
void Renderer::RenderPoint(float x, float y, Color color) const
{
	SetRenderColor(color);

	if (SDL_RenderDrawPoint(m_renderer, (int)x, (int)y) < 0)
		throw std::runtime_error(SDL_GetError());
}
//-----------------------------------------------------------------------------