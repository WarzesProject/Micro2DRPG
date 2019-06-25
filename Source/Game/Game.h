#pragma once

#include "Renderer.h"
#include "Input.h"
#include "Timer.h"

class Game
{
public:
	void Init();
	void Frame(float delta);
	void Close();
};