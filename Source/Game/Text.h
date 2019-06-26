#pragma once

#include "Font.h"
#include "Color.h"

class Text
{
	friend class Renderer;
public:
	~Text();

	void SetText(const Font &font, const std::string &text, Color color, bool blended = true);

private:
	SDL_Texture *m_texture{ nullptr };
	SDL_Rect m_rect{ 0, 0, 0, 0 };
};