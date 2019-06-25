#pragma once

template<typename T>
struct Rect
{
	Rect() = default;
	Rect(T nx, T ny, T nw, T nh) : x(nx), y(ny), w(nw), h(nh) {}

	T x = (T)0;
	T y = (T)0;
	T w = (T)0;
	T h = (T)0;
};

using Recti = Rect<int>;
using Rectf = Rect<float>;