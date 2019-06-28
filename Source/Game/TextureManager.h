#pragma once

#include "TextureRef.h"

class TextureManager : public Module<TextureManager>
{
public:
	TextureManager();
	~TextureManager();

	static TextureRef GetTexture(const std::string &str);
	
private:
	TextureRef getTexture(const std::string &str);

	std::unordered_map<std::string, TextureRef> m_textures;
};