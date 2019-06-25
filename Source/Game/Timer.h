#pragma once

class Timer : public Module<Timer>
{
public:
	explicit Timer(uint32_t fps);

	void Start();
	void Snapshot();

	float ElapsedMilliseconds() const;
	float EffectiveElapsedMilliseconds() const;

	int fps() const;

	bool IsFixedFps() const;
	int FixedFps() const;
	void EnableFixedFps(uint32_t fps);
	void DisableFixedFps();

	uint32_t TotalFrames() const;

private:
	void delay(uint32_t ms) const;
	uint32_t ticks() const;

	float m_start{ 0 };
	float m_elapsedMilliseconds{ 0 };
	float m_effectiveElapsedMilliseconds{ 0 };

	float m_fpsElapsedMilliseconds{ 0 };
	uint32_t m_fpsTemp{ 0 };
	uint32_t m_fps{ 0 };

	uint32_t m_fixedFps{ 0 };
	float m_fixedFpsDelayTime{ 0 };

	uint32_t m_totalFrames{ 0 };
};