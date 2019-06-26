#pragma once

#include "Point.h"

class Window : public Module<Window>
{
	friend class Renderer;
public:
	Window(const std::string &title, int width, int height, bool fullscreen);
	~Window();

	Point GetSize() const;
	int Width();
	int Height();

	Point GetDrawableSize() const;
	int GetDrawableWidth() const;
	int GetDrawableHeight() const;

private:
	SDL_Window *m_window{ nullptr };
	int m_width{ 0 };
	int m_height{ 0 };
};