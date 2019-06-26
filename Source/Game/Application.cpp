#include "stdafx.h"
#include "Application.h"
#include "Log.h"
#include "Profile.h"
#include "Timer.h"
#include "Input.h"
#include "Window.h"
#include "Renderer.h"

//-----------------------------------------------------------------------------
bool isExitApp = false;
void ExitApp()
{
	isExitApp = true;
}
//-----------------------------------------------------------------------------
Application::Application(const ApplicationConfig &config)
{
	srand(static_cast<uint32_t>(time(nullptr)));

	m_config = config;
	Log::Create();	
	SDLApp::init();
	Timer::Create(m_config.fps, false);
	Input::Create();
	Window::Create(m_config.title, m_config.width, m_config.height, m_config.fullscreen);
	Renderer::Create();
}
//-----------------------------------------------------------------------------
Application::~Application()
{
	Renderer::Destroy();
	Window::Destroy();
	Input::Destroy();
	Timer::Destroy();
	Log::Destroy();
	SDLApp::close();
}
//-----------------------------------------------------------------------------
bool Application::Running() const
{
	return m_running && !isExitApp;
}
//-----------------------------------------------------------------------------
float Application::BeginFrame()
{
	static Timer &timer = GetModule<Timer>();
	static Input &input = GetModule<Input>();
	static Renderer &renderer = GetModule<Renderer>();

	timer.Start();
	const auto deltaMultiplier = 0.001f;
	const auto delta = timer.ElapsedMilliseconds() * deltaMultiplier;

	renderer.Clear();
	input.Update();
	return delta;
}
//-----------------------------------------------------------------------------
void Application::EndFrame()
{
	static Timer &timer = GetModule<Timer>();
	static Input &input = GetModule<Input>();
	static Renderer &renderer = GetModule<Renderer>();

	renderer.Present();

	if (input.Quit())
		m_running = false;

	timer.Snapshot();
}
//-----------------------------------------------------------------------------