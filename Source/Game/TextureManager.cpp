#include "stdafx.h"
#include "TextureManager.h"

//-----------------------------------------------------------------------------
TextureManager::TextureManager()
{
	valid() = true;
}
//-----------------------------------------------------------------------------
TextureManager::~TextureManager()
{
	m_textures.clear();
}
//-----------------------------------------------------------------------------
TextureRef TextureManager::GetTexture(const std::string &str)
{
	static auto &manager = GetModule<TextureManager>();
	return manager.getTexture(str);
}
//-----------------------------------------------------------------------------
TextureRef TextureManager::getTexture(const std::string &str)
{
	TextureRef ref;

	auto it = m_textures.find(str);
	if (it == m_textures.end())
	{
		try
		{
			m_textures[str].texture = std::make_shared<Texture>(str);
		}
		catch (const SDLException &error)
		{
			TODO("вернуть дефолтную текстуру");
		}
	}

	ref.texture = m_textures[str].texture;
	return ref;
}
//-----------------------------------------------------------------------------