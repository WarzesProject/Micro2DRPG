#include "stdafx.h"
#include "Text.h"
#include "Surface.h"
#include "Renderer.h"

//-----------------------------------------------------------------------------
void Text::SetText(const Font &font, const std::string &text, Color color, bool blended)
{
	if (m_texture)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}		

	const auto sdlFont = font.m_font;
	const SDL_Color sdlForeground{ color.r, color.g, color.b, color.a };

	SDL_Surface *sdlSurf = nullptr;
	if (blended)
		sdlSurf = TTF_RenderUTF8_Blended(sdlFont, text.c_str(), sdlForeground);
	else
		sdlSurf = TTF_RenderUTF8_Solid(sdlFont, text.c_str(), sdlForeground);
	
	auto surface = std::make_unique<Surface>(sdlSurf);

	static auto &renderer = GetModule<Renderer>();

	m_texture = SDL_CreateTextureFromSurface(renderer.GetRender(), surface->Get());
	if (nullptr == m_texture)
		throw std::runtime_error(SDL_GetError());

	if (SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect.w, &m_rect.h) < 0)
		throw SDLException("SDL_QueryTexture");
}
//-----------------------------------------------------------------------------