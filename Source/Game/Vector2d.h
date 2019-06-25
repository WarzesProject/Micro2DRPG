#pragma once

template<typename T>
struct Vector2d
{
	Vector2d() = default;
	Vector2d(T x, T y) : x(x), y(y){}

	void Absolute()
	{
		x = fabs(x);
		y = fabs(y);
	}

	void AbsoluteX()
	{
		x = fabs(x);
	}

	void AbsoluteY()
	{
		y = fabs(y);
	}

	float GetLength() const
	{
		return sqrt(x * x + y * y);
	}

	void Invert()
	{
		x = -x;
		y = -y;
	}

	void InvertX()
	{
		x = -x;
	}

	void InvertY()
	{
		y = -y;
	}

	bool IsZero() const
	{
		return static_cast<T>(0) == x && static_cast<T>(0) == y;
	}

	void Negate()
	{
		x = fabs(x) * -1.0f;
		y = fabs(y) * -1.0f;
	}

	void NegateX()
	{
		x = fabs(x) * -1.0f;
	}

	void NegateY()
	{
		y = fabs(y) * -1.0f;
	}

	void Normalize()
	{
		if (IsZero())
			return;

		float n = x * x + y * y;

		if (1.0f == n)
			return;

		n = sqrt(n);
		n = 1.0f / n;

		x *= n;
		y *= n;
	}

	T x = (T)0;
	T y = (T)0;
};

using Vec2f = Vector2d<float>;
using Vec2i = Vector2d<int>;