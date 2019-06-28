#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "Input.h"
#include "Window.h"
#include "Utility.h"
#include "AnimationSprite.h"
#include "Sprite.h"

AnimationSprite aniSpr;
Sprite spr;

//-----------------------------------------------------------------------------
void ExitApp();
//-----------------------------------------------------------------------------
void Game::Init()
{
	m_textureRef = TextureManager::GetTexture(GetResourcePath() + "sprite_test.png");
	//m_texture = new Texture(GetResourcePath() + "sprite_test.png");
	//m_texture = new Texture(100, 100, { 255,100,20 });

	m_font = new Font(GetResourcePath() + "consola.ttf", 40);
	m_text = new Text();

	m_text->SetText(*m_font, "Hello привет", { 100,255, 255 }, false);


	static auto &renderer = GetModule<Renderer>();

	renderer.SetClearColor({ 100,0,100 });


	aniSpr.Init(GetResourcePath() + "character2.png", 32, 48, 4, 4);
	spr.Init(GetResourcePath() + "character2.png", { 32,48,32, 48 });

	aniSpr.Play();	
}
//-----------------------------------------------------------------------------
void Game::Frame(float delta)
{
	static auto &renderer = GetModule<Renderer>();
	static auto &input = GetModule<Input>();
	static auto &window = GetModule<Window>();
	
	//renderer.RenderTexture(100, 100, m_textureRef, { 0,0, 64, 50 });
	
	aniSpr.Draw(100,100, 2, delta);
	//spr.Draw(100, 100);

	m_text->Draw(100, 200);

	if (input.KeyPress(KeyboardKey::Escape))
		ExitApp();
		
}
//-----------------------------------------------------------------------------
void Game::Close()
{
	m_textureRef.Free();
	delete m_font;
}
//-----------------------------------------------------------------------------