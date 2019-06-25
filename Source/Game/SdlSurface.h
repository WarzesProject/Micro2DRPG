#pragma once

#include "sdlRwops.h"
#include "Color.h"
#include "Font.h"

class SdlSurface
{
public:
	explicit SdlSurface(const std::string &file);
	explicit SdlSurface(const SdlRwops &rwops);
	SdlSurface(int width, int height, int depth);
	SdlSurface(const Font &font, const std::string &text, Color foreground);
	~SdlSurface();

	void *InternalObject() const;

private:
	void *m_surface{ nullptr };
};