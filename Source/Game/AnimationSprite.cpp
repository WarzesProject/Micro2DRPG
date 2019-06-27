#include "stdafx.h"
#include "AnimationSprite.h"
#include "TextureManager.h"
#include "Renderer.h"

void AnimationSprite::SetTexture(const std::string &name)
{
	m_texture = TextureManager::GetTexture(name);
}

void AnimationSprite::SetFrames(const Rect &clip, int column, int line)
{
	const int widthTex = m_texture.texture->Width();
	const int heightTex = m_texture.texture->Height();

	const int widthSprite = clip.w;
	const int heightSprite = clip.h;

	column = std::min(column, widthTex / widthSprite);
	line = std::min(line, heightTex / heightSprite);

	m_frames.resize(line);
	for (int i = 0; i < line; i++)
		m_frames[i].resize(column);

	for (int x = 0; x < line; x++)
	{
		for (int y = 0; y < column; y++)
		{
			m_frames[x][y].clip = { x * widthSprite, y * heightSprite, widthSprite, heightSprite };
		}
	}
}

void AnimationSprite::Draw(size_t line)
{
	static auto &renderer = GetModule<Renderer>();

	//for (int i = 0; i < m_frames[line].size(); i++)
	{
		renderer.RenderTexture(100, 100, m_texture, m_frames[m_curFrameSet][line].clip);
	}

	m_curFrameSet++;
	if (m_curFrameSet >= m_frames.size())
		m_curFrameSet = 0;
}