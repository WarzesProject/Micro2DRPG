#include "stdafx.h"
#include "Text.h"
#include "Renderer.h"

//-----------------------------------------------------------------------------
Text::~Text()
{
	Free();
}
//-----------------------------------------------------------------------------
void Text::Free()
{
	if (m_texture)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}
}
//-----------------------------------------------------------------------------
void Text::SetText(const Font &font, const std::string &text, Color color, bool blended)
{
	Free();

	const auto sdlFont = font.m_font;
	const SDL_Color sdlForeground{ color.r, color.g, color.b, color.a };

	SDL_Surface *surface = nullptr;
	if (blended)
		surface = TTF_RenderUTF8_Blended(sdlFont, text.c_str(), sdlForeground);
	else
		surface = TTF_RenderUTF8_Solid(sdlFont, text.c_str(), sdlForeground);
	
	m_texture = SDL_CreateTextureFromSurface(GetModule<Renderer>().GetRender(), surface);

	SDL_FreeSurface(surface);

	if (nullptr == m_texture)
		throw std::runtime_error(SDL_GetError());

	if (SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect.w, &m_rect.h) < 0)
		throw SDLException("SDL_QueryTexture");
}
//-----------------------------------------------------------------------------
void Text::Draw(int x, int y)
{
	static auto &renderer = GetModule<Renderer>();
	renderer.RenderText(x, y, *this);
}
//-----------------------------------------------------------------------------