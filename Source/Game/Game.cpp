#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "Input.h"
#include "Window.h"
#include "Utility.h"

//-----------------------------------------------------------------------------
void ExitApp();
//-----------------------------------------------------------------------------
void Game::Init()
{
	//m_texture = new Texture(GetResourcePath() + "sprite_test.png");
	m_texture = new Texture(100, 100, { 255,100,20 });

}
//-----------------------------------------------------------------------------
void Game::Frame(float delta)
{
	static auto &renderer = GetModule<Renderer>();
	static auto &input = GetModule<Input>();
	static auto &window = GetModule<Window>();

	renderer.RenderTexture(0, 10, *m_texture);

	if (input.KeyPress(KeyboardKey::Escape))
		ExitApp();
		
}
//-----------------------------------------------------------------------------
void Game::Close()
{
	delete m_texture;
}
//-----------------------------------------------------------------------------