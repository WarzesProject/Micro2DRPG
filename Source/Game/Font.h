#pragma once

class Font
{
	friend class SdlSurface;
public:
	Font(const std::string &file, int size);
	~Font();

	void GlyphMetrics(uint16_t glyph, int *minX, int *maxX, int *minY, int *maxY, int *advance) const;

	void GlyphMinX(uint16_t glyph, int *minX) const;
	void GlyphMaxX(uint16_t glyph, int *maxX) const;
	void GlyphMinY(uint16_t glyph, int *minY) const;
	void GlyphMaxY(uint16_t glyph, int *maxY) const;
	void GlyphAdvance(uint16_t glyph, int *advance) const;

	int Ascent() const;
	int Descent() const;
	int LineSkip() const;

private:
	TTF_Font *m_font{ nullptr };
};