#include "stdafx.h"
#include "TextureManager.h"
#include "Utility.h"

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

	const std::string fullName = GetResourcePath("sprite") + str;

	auto it = m_textures.find(fullName);
	if (it == m_textures.end())
	{
		try
		{
			m_textures[fullName].texture = std::make_shared<Texture>(fullName);
		}
		catch (const SDLException &error)
		{
			TODO("вернуть дефолтную текстуру");
		}
	}

	ref.texture = m_textures[fullName].texture;
	return ref;
}
//-----------------------------------------------------------------------------