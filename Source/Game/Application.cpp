#include "stdafx.h"
#include "Application.h"
#include "Log.h"
#include "Profile.h"
#include "Timer.h"
#include "Cursor.h"
#include "Input.h"
#include "Window.h"
#include "Renderer.h"
#include "EcsManager.h"

//-----------------------------------------------------------------------------
Application::Application(const ApplicationConfig &config)
{
	srand(static_cast<uint32_t>(time(nullptr))); // NOLINT

	m_config = config;
	Log::Create();
	
	initSDL();

	Timer::Create(m_config.fps);
	Cursor::Create();
	Input::Create();
	Window::Create(m_config.title, m_config.width, m_config.height, m_config.fullscreen);
	Renderer::Create();
	EcsManager::Create();
}
//-----------------------------------------------------------------------------
Application::~Application()
{
	EcsManager::Destroy();
	Renderer::Destroy();
	Window::Destroy();
	Input::Destroy();
	Cursor::Destroy();
	Timer::Destroy();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
	Log::Destroy();
}
//-----------------------------------------------------------------------------
bool Application::Running() const
{
	return m_running;
}
//-----------------------------------------------------------------------------
float Application::BeginFrame()
{
	static Timer &timer = GetModule<Timer>();
	static Input &input = GetModule<Input>();
	static Renderer &renderer = GetModule<Renderer>();
	static EcsManager &ecsMgr = GetModule<EcsManager>();

	timer.Start();
	const auto deltaMultiplier = 0.001f;
	const auto delta = timer.ElapsedMilliseconds() * deltaMultiplier;

	renderer.Clear();
	input.Update();
	ecsMgr.Frame(delta);
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
void Application::initSDL()
{
#ifdef EMSCRIPTEN
	if (SDL_Init(SDL_INIT_EVERYTHING & ~(SDL_INIT_TIMER | SDL_INIT_HAPTIC)) < 0)
#else
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
#endif
		throw std::runtime_error(SDL_GetError());

	if (TTF_Init() < 0)
		throw std::runtime_error(TTF_GetError());

	if (0 == Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG))
		throw std::runtime_error(Mix_GetError());

	if (-1 == Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))
		throw std::runtime_error(Mix_GetError());
}
//-----------------------------------------------------------------------------