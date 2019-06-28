#pragma once

#include "Rect.h"
#include "TextureRef.h"

class Sprite
{
public:
	void Init(const std::string &name, const Rect &clip = { 0,0,0,0 });

	void Draw(int x, int y);

private:
	Rect m_clip = { 0,0,0,0 };
	TextureRef m_texture;
};