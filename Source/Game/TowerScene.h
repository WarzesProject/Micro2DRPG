#pragma once

#include "IScene.h"
#include "Text.h"
#include "Point.h"

struct TowerPoint
{
	Text text;
	bool visible = false;
};

class TowerScene : public IScene
{
public:
	TowerScene();
	~TowerScene() final;
	void Frame(float delta) final;

private:
	std::vector<std::unique_ptr<TowerPoint>> m_points;
};