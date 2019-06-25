#pragma once

class SdlRwops
{
public:
	SdlRwops(const void *data, size_t dataSize);

	void* InternalObject() const;

private:
	void *m_rwops{ nullptr };
};