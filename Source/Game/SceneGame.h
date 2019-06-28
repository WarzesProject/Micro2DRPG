#pragma once

#include "Player.h"

class SceneGame
{
public:
	void Init();
	void Frame(float delta);
	void Close();

private:
	Player m_player;
};