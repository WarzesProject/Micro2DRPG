#pragma once

class Log : public Module<Log>
{
public:
	Log();

	inline std::shared_ptr<spdlog::logger>& Logger()
	{
		return m_logger;
	}

private:
	std::shared_ptr<spdlog::logger> m_logger;
};

#ifdef EMSCRIPTEN
#	ifdef DEBUG
#		define LOG_TRACE(...)  EM_ASM(console.debug(__VA_ARGS__);)
#	else
#		define LOG_TRACE
#	endif
#	define LOG_INFO(...)   EM_ASM(console.info(__VA_ARGS__);)
#	define LOG_ERROR(...)  EM_ASM(console.error(__VA_ARGS__);)
#else
#	ifdef _DEBUG
#		define LOG_TRACE(...)  GetModule<Log>().Logger()->trace(__VA_ARGS__)
#	else
#		define LOG_TRACE(...)
#	endif
#	define LOG_INFO(...)   GetModule<Log>().Logger()->info(__VA_ARGS__)
#	define LOG_ERROR(...)  GetModule<Log>().Logger()->error(__VA_ARGS__)
#endif