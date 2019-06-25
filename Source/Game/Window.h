#pragma once

class Window : public Module<Window>
{
	friend class Renderer;
public:
	Window(const std::string &title, int width, int height, bool fullscreen);
	~Window();

	int Width() const;
	int Height() const;

private:
	void setWindowIcon();

	SDL_Window *m_window{ nullptr };
	int m_width{ 0 };
	int m_height{ 0 };
};