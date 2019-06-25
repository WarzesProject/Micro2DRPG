#pragma once

#include "Color.h"

class Texture;

class Renderer : public Module<Renderer>
{
	friend class Texture;
public:
	Renderer();
	~Renderer();

	void Clear();
	void Present();

	void SetClearColor(Color color);
	void SetRenderColor(Color color) const;

	void RenderTexture(int x, int y, const Texture &texture) const;
	void RenderTexture(int x, int y, const Texture &texture, double angle) const;
	void RenderLine(float x1, float y1, float x2, float y2, Color color) const;
	void RenderPoint(float x, float y, Color color) const;

	int Width() const;
	int Height() const;

private:
	SDL_Renderer *m_renderer{ nullptr };

	mutable Color m_clearColor{ Color(0, 0, 0) };

	int m_width;
	int m_height;
};