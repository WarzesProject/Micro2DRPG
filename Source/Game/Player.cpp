#include "stdafx.h"
#include "Player.h"
#include "Input.h"
//-----------------------------------------------------------------------------
void Player::Init()
{
	m_sprite.Init("player.png", 32, 48, 4, 4);
}
//-----------------------------------------------------------------------------
void Player::Update(float delta)
{	
	//================================
	// игрок всегда (?) в центре экрана
	//================================
	Point scrPosition = m_pos;
	scrPosition.x += m_camera.GetSize().x/2 - m_sprite.GetSize().x/2;
	scrPosition.y += m_camera.GetSize().y/2 - m_sprite.GetSize().y/2;
		
	//================================
	// определение направления движения
	//================================
	m_isMove = false;
	static auto &input = GetModule<Input>();

	if (input.KeyDown(KeyboardKey::Up))
	{
		m_isMove = true;
		m_dir = Direction::Up;
	}
	if (input.KeyDown(KeyboardKey::Down))
	{
		m_isMove = true;
		m_dir = Direction::Down;
	}
	if (input.KeyDown(KeyboardKey::Left))
	{
		m_isMove = true;
		m_dir = Direction::Left;
	}
	if (input.KeyDown(KeyboardKey::Right))
	{
		m_isMove = true;
		m_dir = Direction::Right;
	}

	//================================
	// вывод спрайта
	//================================
	if (m_isMove) m_sprite.Play();
	else m_sprite.Stop();

	size_t Ypos = 0;
	if (m_dir == Direction::Up)         Ypos = 1;
	else if (m_dir == Direction::Down)  Ypos = 0;
	else if (m_dir == Direction::Right) Ypos = 3;
	else if (m_dir == Direction::Left)  Ypos = 2;

	int speed = 25;
	
	m_sprite.Draw(scrPosition.x, scrPosition.y, Ypos, delta, speed);
}
//-----------------------------------------------------------------------------
void Player::Close()
{
	m_sprite.Free();
}
//-----------------------------------------------------------------------------