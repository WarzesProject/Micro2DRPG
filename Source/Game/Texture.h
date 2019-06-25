#pragma once

#include "Color.h"
#include "Font.h"
#include "SdlSurface.h"

class Renderer;

class Texture
{
	friend class Renderer;
public:
	Texture(const Renderer &renderer, const std::string &file);
	Texture(const Renderer &renderer, int width, int height, Color color);
	Texture(const Renderer &renderer, const Font &font, const std::string &text, Color foreground);
	~Texture();

	int Width() const;
	int Height() const;

private:
	void loadTextureFromSurface(const Renderer& renderer, const SdlSurface &surface);

	SDL_Texture *m_texture{ nullptr };
	SDL_Rect m_rect{ 0, 0, 0, 0 };
};