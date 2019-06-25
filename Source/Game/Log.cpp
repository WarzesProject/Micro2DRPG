#include "stdafx.h"
#include "Log.h"
#include <spdlog/sinks/stdout_color_sinks.h>

//-----------------------------------------------------------------------------
Log::Log()
{
	spdlog::set_pattern("%^[%D %T.%e] [%P] [%t] [%n] [%l] %v%$");
	m_logger = spdlog::stdout_color_mt("DEFAULT");
	m_logger->set_level(spdlog::level::trace);

	valid() = true;
}
//-----------------------------------------------------------------------------