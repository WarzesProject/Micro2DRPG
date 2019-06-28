#include "stdafx.h"
#include "Camera.h"
#include "Window.h"

//-----------------------------------------------------------------------------
bool Camera::InView(int x, int y, int h, int w) 
{
	setSize();

	if (m_pos.x >= x + w || m_pos.x + m_size.x <= x) return false;
	if (m_pos.y >= y + h || m_pos.y + m_size.y <= y) return false;
	return true;
}
//-----------------------------------------------------------------------------
void Camera::Move(const Point &deltaPos)
{
	m_pos += deltaPos;
}
//-----------------------------------------------------------------------------
void Camera::setSize()
{
	if (m_size.x != 0 && m_size.y != 0) return;

	auto &window = GetModule<Window>();
	m_size.x = window.GetDrawableWidth();
	m_size.y = window.GetDrawableHeight();
}
//-----------------------------------------------------------------------------