#pragma once

#include "TextureManager.h"
#include "Font.h"
#include "Text.h"

class Game
{
public:
	void Init();
	void Frame(float delta);
	void Close();

private:
	TextureRef m_textureRef;
	Font *m_font = nullptr;
	Text *m_text = nullptr;
};