#pragma once

#include "Log.h"

template<typename Precision>
class Profile
{
	using clock = std::chrono::high_resolution_clock;
public:
	explicit Profile(const char *name) : m_name{ name }, m_start{ clock::now() } {}
	
	~Profile()
	{
		const auto format = "{} ({} {})";
		auto duration = clock::now() - m_start;

		GetModule<Log>().Logger()->trace(
			fmt::format(
				format,
				m_name,
				std::chrono::duration_cast<Precision>(duration).count(),
				unit()
			)
		);
	}

private:
	inline const char *unit();

	const char *m_name;
	clock::time_point m_start;
};

template<>
inline const char* Profile<std::chrono::seconds>::unit()
{
	return "seconds";
}

template<>
inline const char* Profile<std::chrono::milliseconds>::unit()
{
	return "milliseconds";
}

template<>
inline const char* Profile<std::chrono::microseconds>::unit()
{
	return "microseconds";
}

template<>
inline const char* Profile<std::chrono::nanoseconds>::unit()
{
	return "nanoseconds";
}

#ifdef _DEBUG

#define PROFILE_SECONDS(name, code) {                                           \
    auto __profile__ = Profile<std::chrono::seconds>(name);                     \
    { code }                                                                    \
    }

#define PROFILE_MILLISECONDS(name, code) {                                      \
    auto __profile__ = Profile<std::chrono::milliseconds>(name);                \
    { code }                                                                    \
    }

#define PROFILE_MICROSECONDS(name, code) {                                      \
    auto __profile__ = Profile<std::chrono::microseconds>(name);                \
    { code }                                                                    \
    }
#define PROFILE_NANOSECONDS(name, code) {                                       \
    auto __profile__ = Profile<std::chrono::nanoseconds>(name);                 \
    { code }                                                                    \
    }

#else
#define PROFILE_SECONDS(name, code)       { code }
#define PROFILE_MILLISECONDS(name, code)  { code }
#define PROFILE_MICROSECONDS(name, code)  { code }
#define PROFILE_NANOSECONDS(name, code)   { code }
#endif