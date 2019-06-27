#pragma once

#include "Rect.h"
#include "Color.h"

struct SDL_Surface;
struct SDL_PixelFormat;

class Surface 
{
public:
	explicit Surface(SDL_Surface *surface);
	Surface(int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
	Surface(void *pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
	explicit Surface(const std::string &filename);
	
	Surface(const Surface&) = delete;
	Surface(Surface &&other) noexcept;
	
	virtual ~Surface();

	Surface& operator=(const Surface&) = delete;
	Surface& operator=(Surface&& other) noexcept;
	
	SDL_Surface* Get() const;

	Surface Convert(const SDL_PixelFormat &format);
	Surface Convert(Uint32 pixel_format);

	void Blit(const Optional<Rect> &srcrect, Surface &dst, const Rect &dstrect);
	void BlitScaled(const Optional<Rect> &srcrect, Surface &dst, const Optional<Rect> &dstrect);
	
	Rect GetClipRect() const;
	Uint32 GetColorKey() const;
	Uint8 GetAlphaMod() const;
	SDL_BlendMode GetBlendMode() const;
	Color GetColorAndAlphaMod() const;
	void GetColorMod(Uint8& r, Uint8& g, Uint8& b) const;

	Surface& SetClipRect(const Optional<Rect> &rect = NullOpt);
	Surface& SetColorKey(bool flag, Uint32 key);
	Surface& SetAlphaMod(Uint8 alpha = 255);
	Surface& SetBlendMode(SDL_BlendMode blendMode);
	Surface& SetColorMod(Uint8 r = 255, Uint8 g = 255, Uint8 b = 255);
	Surface& SetColorAndAlphaMod(const Color& color);
	Surface& SetRLE(bool flag);

	Surface& FillRect(const Optional<Rect> &rect, Uint32 color);
	Surface& FillRects(const Rect* rects, int count, Uint32 color);

	int GetWidth() const;
	int GetHeight() const;
	Point GetSize() const;
	Uint32 GetFormat() const;

private:
	SDL_Surface *m_surface = nullptr;
};