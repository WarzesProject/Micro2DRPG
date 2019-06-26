#pragma once

#include "Color.h"
#include "Font.h"
#include "Surface.h"

class Renderer;

class Texture
{
	friend class Renderer;
public:
	Texture(const std::string &file);
	Texture(int width, int height, Color color);
	~Texture();

	int Width() const;
	int Height() const;

private:
	void loadTextureFromSurface(const Surface &surface);

	SDL_Texture *m_texture{ nullptr };
	SDL_Rect m_rect{ 0, 0, 0, 0 };
};