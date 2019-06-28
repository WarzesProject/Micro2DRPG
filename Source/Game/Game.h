#pragma once

#include "SceneGame.h"

enum class CurrentScene
{
	None,
	Game
};

class Game
{
public:
	void Init();
	void Frame(float delta);
	void Close();

	void SetScene(CurrentScene scene);

private:
	SceneGame m_game;

	CurrentScene m_currentScene = CurrentScene::None;

};