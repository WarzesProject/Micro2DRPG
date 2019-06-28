#pragma once

#include "Color.h"
#include "Rect.h"
#include "TextureRef.h"

class Text;

class Renderer : public Module<Renderer>
{
public:
	Renderer();
	~Renderer();

	void Clear();
	void Present();

	void SetClearColor(Color color);
	void SetRenderColor(Color color) const;

	void RenderTexture(int x, int y, const Texture &texture) const;
	void RenderTexture(int x, int y, const Texture &texture, double angle) const;
	void RenderTexture(int x, int y, const Texture &texture, const Rect &clip) const;
	void RenderTexture(int x, int y, const TextureRef &texture) const;
	void RenderTexture(int x, int y, const TextureRef &texture, double angle) const;
	void RenderTexture(int x, int y, const TextureRef &texture, const Rect &clip) const;
	void RenderText(int x, int y, const Text &text) const;

	void RenderLine(float x1, float y1, float x2, float y2, Color color) const;
	void RenderPoint(float x, float y, Color color) const;

	SDL_Renderer* GetRender() const
	{
		return m_renderer;
	}

private:
	SDL_Renderer *m_renderer{ nullptr };
	Color m_clearColor{ Color(0, 0, 0) };
};