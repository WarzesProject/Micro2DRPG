#pragma once

class Point : public SDL_Point
{
public:
	constexpr Point() : SDL_Point{ 0, 0 } {}
	constexpr Point(const SDL_Point &point) : SDL_Point{ point.x, point.y } {}
	constexpr Point(int x, int y) : SDL_Point{ x, y } {}
	
	constexpr Point operator-() const 
	{
		return Point(-x, -y);
	}

	constexpr Point operator+(const Point& other) const 
	{
		return Point(x + other.x, y + other.y);
	}

	constexpr Point operator-(const Point& other) const 
	{
		return Point(x - other.x, y - other.y);
	}

	constexpr Point operator/(int value) const
	{
		return Point(x / value, y / value);
	}

	constexpr Point operator/(const Point& other) const
	{
		return Point(x / other.x, y / other.y);
	}
	
	constexpr Point operator%(int value) const
	{
		return Point(x % value, y % value);
	}

	constexpr Point operator%(const Point& other) const
	{
		return Point(x % other.x, y % other.y);
	}

	constexpr Point operator*(int value) const 
	{
		return Point(x * value, y * value);
	}

	constexpr Point operator*(const Point& other) const 
	{
		return Point(x * other.x, y * other.y);
	}

	Point& operator+=(const Point& other) 
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Point& operator-=(const Point& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Point& operator/=(int value)
	{
		x /= value;
		y /= value;
		return *this;
	}

	Point& operator/=(const Point& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Point& operator%=(int value)
	{
		x %= value;
		y %= value;
		return *this;
	}

	Point& operator%=(const Point& other)
	{
		x %= other.x;
		y %= other.y;
		return *this;
	}

	Point& operator*=(int value)
	{
		x *= value;
		y *= value;
		return *this;
	}

	Point& operator*=(const Point& other) 
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Point& Translate(const int x, const int y);
	Point& Translate(const Point &point);

	float Distance(const Point &other) const;
};

constexpr bool operator==(const Point&a, const Point& b)
{
	return a.x == b.x && a.y == b.y;
}

constexpr bool operator!=(const Point& a, const Point& b)
{
	return !(a == b);
}