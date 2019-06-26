#include "stdafx.h"
#include "Window.h"

//-----------------------------------------------------------------------------
Window::Window(const std::string &title, int width, int height, bool fullscreen)
{
	SDL_WindowFlags flags;
	int x;
	int y;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
		x = 0;
		y = 0;
	}
	else
	{
		flags = SDL_WINDOW_HIDDEN;
		x = SDL_WINDOWPOS_CENTERED;
		y = SDL_WINDOWPOS_CENTERED;
	}

	m_window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
	if (nullptr == m_window)
		throw SDLException("SDL_CreateWindow");

	SDL_GetWindowSize(m_window, &m_width, &m_height);

	SDL_ShowWindow(m_window);

	valid() = true;
}
//-----------------------------------------------------------------------------
Window::~Window()
{
	SDL_DestroyWindow(m_window);
}
//-----------------------------------------------------------------------------
Point Window::GetSize() const
{
	int w, h;
	SDL_GetWindowSize(m_window, &w, &h);
	return Point(w, h);
}
//-----------------------------------------------------------------------------
int Window::Width()
{
	SDL_GetWindowSize(m_window, &m_width, nullptr);
	return m_width;
}
//-----------------------------------------------------------------------------
int Window::Height()
{
	SDL_GetWindowSize(m_window, nullptr, &m_height);
	return m_height;
}
//-----------------------------------------------------------------------------
Point Window::GetDrawableSize() const 
{
	int w, h;
	SDL_GL_GetDrawableSize(m_window, &w, &h);
	return Point(w, h);
}
//-----------------------------------------------------------------------------
int Window::GetDrawableWidth() const
{
	int w;
	SDL_GL_GetDrawableSize(m_window, &w, nullptr);
	return w;
}
//-----------------------------------------------------------------------------
int Window::GetDrawableHeight() const
{
	int h;
	SDL_GL_GetDrawableSize(m_window, nullptr, &h);
	return h;
}
//-----------------------------------------------------------------------------