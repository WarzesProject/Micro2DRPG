#pragma once

#include "Camera.h"
#include "AnimationSprite.h"
#include "CoreGame.h"

class Player
{
public:
	void Init();
	void Update(float delta);
	void Close();

private:
	Camera m_camera;
	Point m_pos;
	Direction m_dir = Direction::Down;
	AnimationSprite m_sprite;
	bool m_isMove = false;
};