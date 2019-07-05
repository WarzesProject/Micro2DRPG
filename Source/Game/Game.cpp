#include "stdafx.h"
#include "Game.h"
#include "TowerScene.h"
#include "Global.h"
#include "Utility.h"

Text t1, t2;

//-----------------------------------------------------------------------------
void Game::Init()
{
	Global::baseFont44.reset(new Font(GetResourcePath() + "consola.ttf", 44));
	setScene("TowerScene");

	//t1.SetText(*Global::baseFont44, "Ыhell1", {   0,255,255 });
	//t2.SetText(*Global::baseFont44, "Ыhell2", { 255,255,255 });
}
//-----------------------------------------------------------------------------
void Game::Frame(float delta)
{	
	(*m_currentScene)->Frame(delta);
	//t1.Draw(100, 100);
	//t2.Draw(100, 200);
}
//-----------------------------------------------------------------------------
void Game::Close()
{
	m_scenes.clear();
	Global::baseFont44.reset();
}
//-----------------------------------------------------------------------------
void Game::setScene(std::string_view str)
{
	m_scenes[str.data()].reset(new TowerScene);

	m_currentScene = &m_scenes[str.data()];
}
//-----------------------------------------------------------------------------