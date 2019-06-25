#pragma once

#include "AppConfig.h"

class Application
{
public:
	Application(const ApplicationConfig &config);
	~Application();

	bool Running() const;
	float BeginFrame();
	void EndFrame();

private:
	void initSDL();

	ApplicationConfig m_config;
	bool m_running{ true };
};