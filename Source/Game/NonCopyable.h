#pragma once

class NonCopyable
{
protected:
	NonCopyable() = default;
	~NonCopyable() = default;

private:
	NonCopyable(NonCopyable&&) = delete;
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable& operator=(NonCopyable&&) = delete;
	NonCopyable& operator=(const NonCopyable&) = delete;
};