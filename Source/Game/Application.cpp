#include "stdafx.h"
#include "Application.h"
#include "Log.h"

//-----------------------------------------------------------------------------
Application::Application(const ApplicationConfig &config)
{
	m_config = config;

	Log::Create();
}
//-----------------------------------------------------------------------------
Application::~Application()
{
	Log::Destroy();
}
//-----------------------------------------------------------------------------