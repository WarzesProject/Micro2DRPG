#pragma once

#include "Rect.h"
#include "TextureRef.h"

struct Frame
{
	Rect clip = { 0,0,0,0 };
};

class AnimationSprite
{
public:
	void Init(const std::string &name, int spriteWidth, int spriteHeight, int countX, int countY);

	void Play();
	void Stop();

	void Draw(int x, int y, size_t Yset, float delta, int animSpeed = 25);

private:
	TextureRef m_texture;
	std::vector<std::vector<Frame>> m_frames;
	uint32_t m_currentFrame = 0;
	float m_elapsed = 0;
	bool m_animated = false;

};