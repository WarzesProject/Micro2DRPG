#include "stdafx.h"
#include "AnimationSprite.h"
#include "TextureManager.h"
#include "Renderer.h"

//-----------------------------------------------------------------------------
void AnimationSprite::Init(const std::string &name, int spriteWidth, int spriteHeight, int countX, int countY)
{
	m_texture = TextureManager::GetTexture(name);
	m_spriteSize = { spriteWidth, spriteHeight };

	const int widthTex = m_texture.texture->Width();
	const int heightTex = m_texture.texture->Height();

	countX = std::min(countX, widthTex / spriteWidth);
	countY = std::min(countY, heightTex / spriteHeight);

	m_frames.resize(countX);
	for (int i = 0; i < countX; i++)
		m_frames[i].resize(countY);

	for (int x = 0; x < countX; x++)
	{
		for (int y = 0; y < countY; y++)
		{
			m_frames[x][y].clip = { x * spriteWidth, y * spriteHeight, spriteWidth, spriteHeight };
		}
	}
}
//-----------------------------------------------------------------------------
void AnimationSprite::Free()
{
	m_animated = false;
	m_currentFrame = 0;
	m_elapsed = 0.0f;
	m_frames.clear();
	m_texture.Free();
}
//-----------------------------------------------------------------------------
void AnimationSprite::Play()
{
	m_animated = true;
}
//-----------------------------------------------------------------------------
void AnimationSprite::Stop()
{
	m_animated = false;
	m_currentFrame = 0;
	m_elapsed = 0.0f;
}
//-----------------------------------------------------------------------------
void AnimationSprite::Draw(int x, int y, size_t Yset, float delta, int animSpeed)
{
	if (m_frames[m_currentFrame].size() <= Yset) return;

	static auto &renderer = GetModule<Renderer>();
	renderer.RenderTexture(x, y, m_texture, m_frames[m_currentFrame][Yset].clip);
	
	if (m_animated)
	{
		m_elapsed += delta;
		if (m_elapsed > (float)animSpeed / 100.0f)
		{
			m_currentFrame++;
			if (m_currentFrame >= m_frames.size())
				m_currentFrame = 0;

			m_elapsed = 0;
		}
	}	
}
//-----------------------------------------------------------------------------