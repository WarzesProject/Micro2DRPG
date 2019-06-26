#include "stdafx.h"
#include "Surface.h"

//-----------------------------------------------------------------------------
Surface::Surface(SDL_Surface *surface) : m_surface(surface) 
{
	assert(surface);
}
//-----------------------------------------------------------------------------
Surface::Surface(int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
{
	if ((m_surface = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, depth, Rmask, Gmask, Bmask, Amask)) == nullptr)
		throw SDLException("SDL_CreateRGBSurface");
}
//-----------------------------------------------------------------------------
Surface::Surface(void *pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask) 
{
	if ((m_surface = SDL_CreateRGBSurfaceFrom(pixels, width, height, depth, pitch, Rmask, Gmask, Bmask, Amask)) == nullptr)
		throw SDLException("SDL_CreateRGBSurfaceFrom");
}
//-----------------------------------------------------------------------------
Surface::Surface(const std::string& path)
{
	if ((m_surface = IMG_Load(path.c_str())) == nullptr)
		throw SDLException("IMG_Load");
}
//-----------------------------------------------------------------------------
Surface::~Surface() 
{
	if (m_surface != nullptr)
		SDL_FreeSurface(m_surface);
}
//-----------------------------------------------------------------------------
Surface::Surface(Surface&& other) noexcept : m_surface(other.m_surface) 
{
	other.m_surface = nullptr;
}
//-----------------------------------------------------------------------------
Surface& Surface::operator=(Surface&& other) noexcept 
{
	if (&other == this)
		return *this;
	if (m_surface != nullptr)
		SDL_FreeSurface(m_surface);
	m_surface = other.m_surface;
	other.m_surface = nullptr;
	return *this;
}
//-----------------------------------------------------------------------------
SDL_Surface* Surface::Get() const
{
	return m_surface;
}
//-----------------------------------------------------------------------------
Surface Surface::Convert(const SDL_PixelFormat& format)
{
	SDL_Surface* surface = SDL_ConvertSurface(m_surface, &format, 0);
	if (surface == nullptr)
		throw SDLException("SDL_ConvertSurface");
	return Surface(surface);
}
//-----------------------------------------------------------------------------
Surface Surface::Convert(Uint32 pixel_format) 
{
	SDL_Surface* surface = SDL_ConvertSurfaceFormat(m_surface, pixel_format, 0);
	if (surface == nullptr)
		throw SDLException("SDL_ConvertSurfaceFormat");
	return Surface(surface);
}
//-----------------------------------------------------------------------------
void Surface::Blit(const Optional<Rect>& srcrect, Surface& dst, const Rect& dstrect)
{
	SDL_Rect tmpdstrect = dstrect; // 4th argument is non-const; does it modify rect?
	if (SDL_BlitSurface(m_surface, srcrect ? &*srcrect : nullptr, dst.Get(), &tmpdstrect) != 0)
		throw SDLException("SDL_BlitSurface");
}
//-----------------------------------------------------------------------------
void Surface::BlitScaled(const Optional<Rect>& srcrect, Surface& dst, const Optional<Rect>& dstrect)
{
	SDL_Rect tmpdstrect; // 4th argument is non-const; does it modify rect?
	if (dstrect)
		tmpdstrect = *dstrect;
	if (SDL_BlitScaled(m_surface, srcrect ? &*srcrect : nullptr, dst.Get(), dstrect ? &tmpdstrect : nullptr) != 0)
		throw SDLException("SDL_BlitScaled");
}
//-----------------------------------------------------------------------------
Surface::LockHandle Surface::Lock() 
{
	return LockHandle(this);
}
//-----------------------------------------------------------------------------
Rect Surface::GetClipRect() const
{
	SDL_Rect rect;
	SDL_GetClipRect(m_surface, &rect);
	return Rect(rect);
}
//-----------------------------------------------------------------------------
Uint32 Surface::GetColorKey() const 
{
	Uint32 key;
	if (SDL_GetColorKey(m_surface, &key) != 0)
		throw SDLException("SDL_GetColorKey");
	return key;
}
//-----------------------------------------------------------------------------
Uint8 Surface::GetAlphaMod() const 
{
	Uint8 alpha;
	if (SDL_GetSurfaceAlphaMod(m_surface, &alpha) != 0)
		throw SDLException("SDL_GetSurfaceAlphaMod");
	return alpha;
}
//-----------------------------------------------------------------------------
SDL_BlendMode Surface::GetBlendMode() const
{
	SDL_BlendMode blendMode;
	if (SDL_GetSurfaceBlendMode(m_surface, &blendMode) != 0)
		throw SDLException("SDL_GetSurfaceBlendMode");
	return blendMode;
}
//-----------------------------------------------------------------------------
Color Surface::GetColorAndAlphaMod() const
{
	Color color;
	GetColorMod(color.r, color.g, color.b);
	color.a = GetAlphaMod();
	return color;
}
//-----------------------------------------------------------------------------
void Surface::GetColorMod(Uint8& r, Uint8& g, Uint8& b) const
{
	if (SDL_GetSurfaceColorMod(m_surface, &r, &g, &b) != 0)
		throw SDLException("SDL_GetSurfaceColorMod");
}
//-----------------------------------------------------------------------------
Surface& Surface::SetClipRect(const Optional<Rect>& rect) 
{
	if (SDL_SetClipRect(m_surface, rect ? &*rect : nullptr) != SDL_TRUE)
		throw SDLException("SDL_SetClipRect");
	return *this;
}
//-----------------------------------------------------------------------------
Surface& Surface::SetColorKey(bool flag, Uint32 key) 
{
	if (SDL_SetColorKey(m_surface, flag, key) != 0)
		throw SDLException("SDL_SetColorKey");
	return *this;
}
//-----------------------------------------------------------------------------
Surface& Surface::SetAlphaMod(Uint8 alpha)
{
	if (SDL_SetSurfaceAlphaMod(m_surface, alpha) != 0)
		throw SDLException("SDL_SetSurfaceAlphaMod");
	return *this;
}
//-----------------------------------------------------------------------------
Surface& Surface::SetBlendMode(SDL_BlendMode blendMode)
{
	if (SDL_SetSurfaceBlendMode(m_surface, blendMode) != 0)
		throw SDLException("SDL_SetSurfaceBlendMode");
	return *this;
}
//-----------------------------------------------------------------------------
Surface& Surface::SetColorMod(Uint8 r, Uint8 g, Uint8 b)
{
	if (SDL_SetSurfaceColorMod(m_surface, r, g, b) != 0)
		throw SDLException("SDL_SetSurfaceColorMod");
	return *this;
}
//-----------------------------------------------------------------------------
Surface& Surface::SetColorAndAlphaMod(const Color& color)
{
	return SetColorMod(color.r, color.g, color.b).SetAlphaMod(color.a);
}
//-----------------------------------------------------------------------------
Surface& Surface::SetRLE(bool flag) 
{
	if (SDL_SetSurfaceRLE(m_surface, flag ? 1 : 0) != 0)
		throw SDLException("SDL_SetSurfaceRLE");
	return *this;
}
//-----------------------------------------------------------------------------
Surface& Surface::FillRect(const Optional<Rect>& rect, Uint32 color) 
{
	if (SDL_FillRect(m_surface, rect ? &*rect : nullptr, color) != 0)
		throw SDLException("SDL_FillRect");
	return *this;
}
//-----------------------------------------------------------------------------
Surface& Surface::FillRects(const Rect* rects, int count, Uint32 color)
{
	std::vector<SDL_Rect> sdl_rects;
	sdl_rects.reserve(static_cast<size_t>(count));
	for (const Rect* r = rects; r != rects + count; ++r)
		sdl_rects.emplace_back(*r);

	if (SDL_FillRects(m_surface, sdl_rects.data(), count, color) != 0)
		throw SDLException("SDL_FillRects");
	return *this;
}
//-----------------------------------------------------------------------------
int Surface::GetWidth() const
{
	return m_surface->w;
}
//-----------------------------------------------------------------------------
int Surface::GetHeight() const 
{
	return m_surface->h;
}
//-----------------------------------------------------------------------------
Point Surface::GetSize() const
{
	return Point(m_surface->w, m_surface->h);
}
//-----------------------------------------------------------------------------
Uint32 Surface::GetFormat() const
{
	return m_surface->format->format;
}
//-----------------------------------------------------------------------------