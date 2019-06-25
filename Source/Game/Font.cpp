#include "stdafx.h"
#include "Font.h"

//-----------------------------------------------------------------------------
Font::Font(const std::string &file, int size)
{
	m_font = TTF_OpenFont(file.c_str(), size);
	if (nullptr == m_font)
		throw std::runtime_error(TTF_GetError());
}
//-----------------------------------------------------------------------------
Font::~Font()
{
	TTF_CloseFont(m_font);
}
//-----------------------------------------------------------------------------
void Font::GlyphMetrics(uint16_t glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const
{
	if (TTF_GlyphMetrics(m_font, glyph, minX, maxX, minY, maxY, advance) < 0)
	{
		throw std::runtime_error(TTF_GetError());
	}
}
//-----------------------------------------------------------------------------
void Font::GlyphMinX(uint16_t glyph, int *minX) const
{
	int maxX;
	int minY;
	int maxY;
	int advance;

	GlyphMetrics(glyph, minX, &maxX, &minY, &maxY, &advance);
}
//-----------------------------------------------------------------------------
void Font::GlyphMaxX(uint16_t glyph, int *maxX) const
{
	int minX;
	int minY;
	int maxY;
	int advance;

	return GlyphMetrics(glyph, &minX, maxX, &minY, &maxY, &advance);
}
//-----------------------------------------------------------------------------
void Font::GlyphMinY(uint16_t glyph, int *minY) const
{
	int minX;
	int maxX;
	int maxY;
	int advance;

	return GlyphMetrics(glyph, &minX, &maxX, minY, &maxY, &advance);
}
//-----------------------------------------------------------------------------
void Font::GlyphMaxY(uint16_t glyph, int *maxY) const
{
	int minX;
	int maxX;
	int minY;
	int advance;

	return GlyphMetrics(glyph, &minX, &maxX, &minY, maxY, &advance);
}
//-----------------------------------------------------------------------------
void Font::GlyphAdvance(uint16_t glyph, int *advance) const
{
	int minX;
	int maxX;
	int minY;
	int maxY;

	GlyphMetrics(glyph, &minX, &maxX, &minY, &maxY, advance);
}
//-----------------------------------------------------------------------------
int Font::Ascent() const
{
	return TTF_FontAscent(m_font);
}
//-----------------------------------------------------------------------------
int Font::Descent() const
{
	return TTF_FontDescent(m_font);
}
//-----------------------------------------------------------------------------
int Font::LineSkip() const
{
	return TTF_FontLineSkip(m_font);
}
//-----------------------------------------------------------------------------