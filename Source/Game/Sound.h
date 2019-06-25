#pragma once

class Sound
{
public:
	explicit Sound(const std::string &file);
	Sound(const void *data, size_t dataSize);
	~Sound();

	void Play(bool loop) const;

private:
	Mix_Chunk *m_chunk{ nullptr };
};