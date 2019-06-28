#include "stdafx.h"
#include "Game.h"

//-----------------------------------------------------------------------------
void Game::Init()
{	
	SetScene(CurrentScene::Game);
}
//-----------------------------------------------------------------------------
void Game::Frame(float delta)
{
	if (m_currentScene == CurrentScene::Game)
		m_game.Frame(delta);		
}
//-----------------------------------------------------------------------------
void Game::Close()
{
	m_game.Close();
}
//-----------------------------------------------------------------------------
void Game::SetScene(CurrentScene scene)
{
	if (m_currentScene == scene) return;

	// Close current Scene
	if (m_currentScene == CurrentScene::Game)
		m_game.Close();

	// Set current Scene
	m_currentScene = scene;

	// Init current Scene
	if (m_currentScene == CurrentScene::Game)
		m_game.Init();
}
//-----------------------------------------------------------------------------