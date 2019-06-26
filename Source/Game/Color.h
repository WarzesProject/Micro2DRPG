#pragma once

class Color : public SDL_Color
{
public:
	constexpr Color() : SDL_Color{ 0, 0, 0, 0 } {}
	constexpr Color(const SDL_Color& color) : SDL_Color{ color.r, color.g, color.b, color.a } {}
	constexpr Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = SDL_ALPHA_OPAQUE) : SDL_Color{ r, g, b, a } {}

	constexpr Uint8 GetRed() const
	{
		return r;
	}

	Color& SetRed(int nr)
	{
		r = nr;
		return *this;
	}

	constexpr Uint8 GetGreen() const 
	{
		return g;
	}

	Color& SetGreen(int ng) 
	{
		g = ng;
		return *this;
	}

	constexpr Uint8 GetBlue() const 
	{
		return b;
	}

	Color& SetBlue(int nb) 
	{
		b = nb;
		return *this;
	}

	constexpr Uint8 GetAlpha() const
	{
		return a;
	}

	Color& SetAlpha(int na)
	{
		a = na;
		return *this;
	}
};


constexpr bool operator==(const Color& a, const Color& b) 
{
	return a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a;
}

constexpr bool operator!=(const Color& a, const Color& b)
{
	return !(a == b);
}