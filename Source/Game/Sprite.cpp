#include "stdafx.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "Renderer.h"

//-----------------------------------------------------------------------------
void Sprite::Init(const std::string &name, const Rect &clip)
{
	m_texture = TextureManager::GetTexture(name);
	m_clip = clip;
}
//-----------------------------------------------------------------------------
void Sprite::Draw(int x, int y)
{
	static auto &renderer = GetModule<Renderer>();

	if (m_clip.w == 0 && m_clip.h == 0)
		renderer.RenderTexture(x, y, m_texture);
	else
		renderer.RenderTexture(x, y, m_texture, m_clip);
}
//-----------------------------------------------------------------------------