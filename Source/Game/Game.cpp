#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "Utility.h"

//-----------------------------------------------------------------------------
void Game::Init()
{
	m_texture = new Texture(GetModule<Renderer>(), GetResourcePath() + "sprite_test.png");
}
//-----------------------------------------------------------------------------
void Game::Frame(float delta)
{
	GetModule<Renderer>().RenderTexture(10, 10, *m_texture);
}
//-----------------------------------------------------------------------------
void Game::Close()
{
	delete m_texture;
}
//-----------------------------------------------------------------------------