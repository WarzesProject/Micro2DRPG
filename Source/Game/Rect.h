#pragma once

#include "Point.h"
#include "Optional.h"

class Rect : public SDL_Rect
{
public:
	constexpr Rect() : SDL_Rect{ 0, 0, 0, 0 } {}
	constexpr Rect(const SDL_Rect& rect) : SDL_Rect{ rect.x, rect.y, rect.w, rect.h } {}
	constexpr Rect(const Point& corner, const Point& size) : SDL_Rect{ corner.x, corner.y, size.x, size.y } {}
	constexpr Rect(int x, int y, int w, int h) : SDL_Rect{ x, y, w, h } {}

	static constexpr Rect FromCenter(int cx, int cy, int w, int h) 
	{
		return Rect(cx - w / 2, cy - h / 2, w, h);
	}
	static constexpr Rect FromCenter(const Point& center, const Point& size) 
	{
		return Rect(center - size / 2, size);
	}

	static constexpr Rect FromCorners(int x1, int y1, int x2, int y2) 
	{
		return Rect(x1, y1, x2 - x1 + 1, y2 - y1 + 1);
	}

	static constexpr Rect FromCorners(const Point& p1, const Point& p2) 
	{
		return Rect(p1, p2 - p1 + Point(1, 1));
	}

	constexpr int GetX() const
	{
		return x;
	}

	Rect& SetX(int nx)
	{
		x = nx;
		return *this;
	}

	constexpr int GetY() const
	{
		return y;
	}

	Rect& SetY(int ny)
	{
		y = ny;
		return *this;
	}

	constexpr int GetW() const
	{
		return w;
	}

	Rect& SetW(int nw)
	{
		w = nw;
		return *this;
	}

	constexpr int GetH() const
	{
		return h;
	}

	Rect& SetH(int nh)
	{
		h = nh;
		return *this;
	}

	constexpr int GetX2() const 
	{
		return x + w - 1;
	}

	Rect& SetX2(int x2)
	{
		w = x2 - x + 1;
		return *this;
	}
	constexpr int GetY2() const 
	{
		return y + h - 1;
	}

	Rect& SetY2(int y2)
	{
		h = y2 - y + 1;
		return *this;
	}

	constexpr Point GetTopLeft() const 
	{
		return Point(x, y);
	}

	constexpr Point GetTopRight() const
	{
		return Point(GetX2(), y);
	}

	constexpr Point GetBottomLeft() const 
	{
		return Point(x, GetY2());
	}

	constexpr Point GetBottomRight() const
	{
		return Point(GetX2(), GetY2());
	}

	constexpr Point GetSize() const 
	{
		return Point(w, h);
	}

	constexpr Point GetCentroid() const 
	{
		return Point(x + w / 2, y + h / 2);
	}

	constexpr bool Contains(int px, int py) const 
	{
		return px >= x && py >= y && px <= GetX2() && py <= GetY2();
	}

	constexpr bool Contains(const Point& point) const 
	{
		return point.x >= x && point.y >= y && point.x <= GetX2() && point.y <= GetY2();
	}

	constexpr bool Contains(const Rect& rect) const 
	{
		return rect.x >= x && rect.y >= y && rect.GetX2() <= GetX2() && rect.GetY2() <= GetY2();
	}

	constexpr bool Intersects(const Rect& rect) const
	{
		return !(rect.GetX2() < x || rect.GetY2() < y || rect.x > GetX2() || rect.y > GetY2());
	}

	// Calculate union with another rect
	Rect GetUnion(const Rect& rect) const;
	// Union rect with another rect
	Rect& Union(const Rect& rect);
	// Get a rect extended by specified amount of pixels
	Rect GetExtension(unsigned int amount) const;
	// Get a rect extended by specified amount of pixels
	Rect GetExtension(unsigned int hamount, unsigned int vamount) const;

	// Extend a rect by specified amount of pixels
	Rect& Extend(unsigned int amount);

	// Extend a rect by specified amount of pixels
	Rect& Extend(unsigned int hamount, unsigned int vamount);

	Optional<Rect> GetIntersection(const Rect& rect) const;

	
	/// \brief Calculate the intersection of a rectangle and line segment
	///
	/// \param[in,out] x1 Starting X-coordinate of the line
	/// \param[in,out] y1 Starting Y-coordinate of the line
	/// \param[in,out] x2 Ending X-coordinate of the line
	/// \param[in,out] y2 Ending Y-coordinate of the line
	///
	/// \returns True if there is an intersection, false otherwise
	///
	/// This function is used to clip a line segment to a
	/// rectangle. A line segment contained entirely within the
	/// rectangle or that does not intersect will remain unchanged.
	/// A line segment that crosses the rectangle at either or both
	/// ends will be clipped to the boundary of the rectangle and
	/// the new coordinates saved in x1, y1, x2, and/or y2 as
	/// necessary.
	///
	
	bool IntersectLine(int& x1, int& y1, int& x2, int& y2) const;

	
	/// \brief Calculate the intersection of a rectangle and line segment
	///
	/// \param[in,out] p1 Starting coordinates of the line
	/// \param[in,out] p2 Ending coordinates of the line
	///
	/// \returns True if there is an intersection, false otherwise
	///
	/// This function is used to clip a line segment to a
	/// rectangle. A line segment contained entirely within the
	/// rectangle or that does not intersect will remain unchanged.
	/// A line segment that crosses the rectangle at either or both
	/// ends will be clipped to the boundary of the rectangle and
	/// the new coordinates saved in p1 and/or p2 as necessary.
	///
	
	bool IntersectLine(Point& p1, Point& p2) const;

	constexpr Rect operator+(const Point& offset) const
	{
		return Rect(x + offset.x, y + offset.y, w, h);
	}

	constexpr Rect operator-(const Point& offset) const 
	{
		return Rect(x - offset.x, y - offset.y, w, h);
	}

	Rect& operator+=(const Point& offset)
	{
		x += offset.x;
		y += offset.y;
		return *this;
	}

	Rect& operator-=(const Point& offset) 
	{
		x -= offset.x;
		y -= offset.y;
		return *this;
	}
};

constexpr bool operator==(const Rect& a, const Rect& b) 
{
	return a.x == b.x && a.y == b.y && a.w == b.w && a.h == b.h;
}

constexpr bool operator!=(const Rect& a, const Rect& b)
{
	return !(a == b);
}