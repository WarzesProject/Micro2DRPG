#include "stdafx.h"
#include "TowerScene.h"
#include "Global.h"

//-----------------------------------------------------------------------------
TowerScene::TowerScene()
{

	m_points.push_back(std::make_unique<TowerPoint>());
	m_points[0]->visible = true;
	m_points[0]->text.SetText(*Global::baseFont44, "Гильдия", { 255, 255, 255 });

	m_points.push_back(std::make_unique<TowerPoint>());
	m_points[1]->visible = true;
	m_points[1]->text.SetText(*Global::baseFont44, "Алтарь", { 255, 255, 255 });

	m_points.push_back(std::make_unique<TowerPoint>());
	m_points[2]->visible = true;
	m_points[2]->text.SetText(*Global::baseFont44, "В путь", { 255, 255, 255 });
}
//-----------------------------------------------------------------------------
TowerScene::~TowerScene()
{
	for (auto &it : m_points)
		it.reset();
}
//-----------------------------------------------------------------------------
void TowerScene::Frame(float delta)
{
	int x = 100;
	int y = 100;
	for (auto &it : m_points)
	{
		if (it->visible)
		{
			it->text.Draw(x, y);
			y += 46;
		}		
	}

}
//-----------------------------------------------------------------------------