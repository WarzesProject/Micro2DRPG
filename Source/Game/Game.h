#pragma once

#include "IScene.h"

class Game
{
public:
	void Init();
	void Frame(float delta);
	void Close();

private:
	void setScene(std::string_view str);

	std::unordered_map<std::string, std::unique_ptr<IScene>> m_scenes;
	std::unique_ptr<IScene> *m_currentScene;
};