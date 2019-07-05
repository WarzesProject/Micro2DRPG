#include "stdafx.h"
#include "Point.h"

//-----------------------------------------------------------------------------
Point& Point::Translate(const int nx, const int ny)
{
	x += nx;
	y += ny;
	return *this;
}
//-----------------------------------------------------------------------------
Point& Point::Translate(const Point &point)
{
	x += point.x;
	y += point.y;
	return *this;
}
//-----------------------------------------------------------------------------
float Point::Distance(const Point &other) const
{
	const float a = (other.x - x);
	const float b = (other.y - y);
	return std::sqrt((a * a) + (b * b));
}
//-----------------------------------------------------------------------------