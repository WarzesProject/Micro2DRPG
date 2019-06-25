#pragma once

#include "AppConfig.h"

class Application
{
public:
	Application(const ApplicationConfig &config);
	~Application();

private:

	ApplicationConfig m_config;
};