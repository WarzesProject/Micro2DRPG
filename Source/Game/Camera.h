#pragma once

#include "Point.h"

class Camera
{
public:
	Point GetPos() const { return m_pos; }
	void SetPos(const Point &pos) { m_pos = pos; }
	
	bool InView(int x, int y, int h, int w);
	void Move(const Point &deltaPos);

private:
	void setSize();
	Point m_pos;
	Point m_size;
};