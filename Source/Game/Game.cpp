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
	m_texture = new Texture(GetResourcePath() + "sprite_test.png");
	//m_texture = new Texture(100, 100, { 255,100,20 });

	m_font = new Font(GetResourcePath() + "consola.ttf", 40);
	m_text = new Text();

	m_text->SetText(*m_font, "Hello привет", { 100,255, 255 }, false);
}
//-----------------------------------------------------------------------------
void Game::Frame(float delta)
{
	static auto &renderer = GetModule<Renderer>();
	static auto &input = GetModule<Input>();
	static auto &window = GetModule<Window>();

	//renderer.RenderTexture(0, 10, *m_texture);
	renderer.RenderTexture(100, 100, *m_texture, { 192,0, 64, 50 });

	renderer.RenderText(100, 200, *m_text);

	if (input.KeyPress(KeyboardKey::Escape))
		ExitApp();
		
}
//-----------------------------------------------------------------------------
void Game::Close()
{
	delete m_texture;
	delete m_font;
}
//-----------------------------------------------------------------------------