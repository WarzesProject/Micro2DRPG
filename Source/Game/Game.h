#pragma once

#include "Texture.h"
#include "Font.h"
#include "Text.h"

class Game
{
public:
	void Init();
	void Frame(float delta);
	void Close();

private:
	Texture* m_texture = nullptr;
	Font *m_font = nullptr;
	Text *m_text = nullptr;
};