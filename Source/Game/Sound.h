#pragma once

class Sound
{
public:
	explicit Sound(const std::string &file);
	~Sound();

	void Play(bool loop) const;

private:
	Mix_Chunk *m_chunk{ nullptr };
};