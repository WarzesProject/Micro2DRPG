#pragma once

#include "Rect.h"
#include "TextureRef.h"

struct Frame
{
	Rect clip = { 0,0,0,0 };
};

struct FrameSet
{
	std::vector<Frame> frames;
	uint32_t curFrame = 0;
};

class AnimationSprite
{
public:

	void SetTexture(const std::string &name);

	void SetFrames(const Rect &clip, int column, int line);

	void Draw(size_t line);

private:
	TextureRef m_texture;
	std::vector<std::vector<Frame>> m_frames;
	uint32_t m_curFrameSet = 0;
};