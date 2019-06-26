#pragma once

#include "AppConfig.h"
#include "SDLApp.h"

class Application : private SDLApp
{
public:
	Application(const ApplicationConfig &config);
	~Application();

	bool Running() const;
	float BeginFrame();
	void EndFrame();

private:
	ApplicationConfig m_config;
	bool m_running{ true };
};

void ExitApp();