#pragma once

#include "Font.h"
#include "Color.h"

class Text
{
	friend class Renderer;
public:
	~Text();
	void Free();

	void SetText(const Font &font, const std::string &text, Color color, bool blended = true);
	void Draw(int x, int y);

private:
	SDL_Texture *m_texture{ nullptr };
	SDL_Rect m_rect{ 0, 0, 0, 0 };
};