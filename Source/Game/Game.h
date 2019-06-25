#pragma once

#include "Texture.h"

class Game
{
public:
	void Init();
	void Frame(float delta);
	void Close();

private:
	Texture* m_texture = nullptr;
};