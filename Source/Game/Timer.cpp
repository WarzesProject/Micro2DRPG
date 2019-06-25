#include "stdafx.h"
#include "Timer.h"

TODO("фиксация фпс не особо нужна, есть vsync");
//-----------------------------------------------------------------------------
Timer::Timer(uint32_t fps, bool enableFixedFps)
{
	EnableFixedFps(fps);
	if (!enableFixedFps)
		DisableFixedFps();

	valid() = true;
}
//-----------------------------------------------------------------------------
void Timer::Start()
{
	m_start = ticks();
}
//-----------------------------------------------------------------------------
void Timer::Snapshot()
{
	++m_totalFrames;

	m_elapsedMilliseconds = ticks() - m_start;
	m_effectiveElapsedMilliseconds = m_elapsedMilliseconds;
	float delayTime = 0;

	if (0 < m_fixedFps && m_elapsedMilliseconds < m_fixedFpsDelayTime)
	{
		delayTime = m_fixedFpsDelayTime - m_elapsedMilliseconds;
		m_elapsedMilliseconds += delayTime;
	}

	if (1000 < m_fpsElapsedMilliseconds)
	{
		m_fps = m_fpsTemp;
		m_fpsElapsedMilliseconds = 0;
		m_fpsTemp = 0;
	}
	else
	{
		m_fpsElapsedMilliseconds += m_elapsedMilliseconds;
		++m_fpsTemp;
	}

	if (0 < delayTime)
	{
		delay((uint32_t)delayTime);
	}
}
//-----------------------------------------------------------------------------
float Timer::ElapsedMilliseconds() const
{
	return m_elapsedMilliseconds;
}
//-----------------------------------------------------------------------------
float Timer::EffectiveElapsedMilliseconds() const
{
	return m_effectiveElapsedMilliseconds;
}
//-----------------------------------------------------------------------------
int Timer::fps() const
{
	return m_fps;
}
//-----------------------------------------------------------------------------
bool Timer::IsFixedFps() const
{
	return 0 < m_fixedFps;
}
//-----------------------------------------------------------------------------
int Timer::FixedFps() const
{
	return m_fixedFps;
}
//-----------------------------------------------------------------------------
void Timer::EnableFixedFps(uint32_t fps)
{
	if (0 >= fps)
	{
		fps = 60; // Defaulting to 60 fps
	}

	m_fixedFps = fps;
	m_fixedFpsDelayTime = 1000.0f / fps;
}
//-----------------------------------------------------------------------------
void Timer::DisableFixedFps()
{
	m_fixedFps = 0;
}
//-----------------------------------------------------------------------------
uint32_t Timer::TotalFrames() const
{
	return m_totalFrames;
}
//-----------------------------------------------------------------------------
void Timer::delay(uint32_t ms) const
{
#ifndef EMSCRIPTEN
	SDL_Delay(ms);
#else
	(void)ms;
#endif
}
//-----------------------------------------------------------------------------
uint32_t Timer::ticks() const
{
	return SDL_GetTicks();
}
//-----------------------------------------------------------------------------