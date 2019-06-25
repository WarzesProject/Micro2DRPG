#include "stdafx.h"
#include "Application.h"
#include "Profile.h"

//-----------------------------------------------------------------------------
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib") // remove??
#pragma comment(lib, "SDL2_ttf.lib")
#pragma comment(lib, "SDL2_mixer.lib")
#pragma comment(lib, "SDL2_image.lib")
//-----------------------------------------------------------------------------
#ifdef EMSCRIPTEN
App *appPtr;
void Loop()
{
	const auto delta = appPtr.BeginFrame();
	//...
	appPtr.EndFrame();
}
#endif
//-----------------------------------------------------------------------------
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	try
	{
		ApplicationConfig config;
		Application app(config);

#ifdef EMSCRIPTEN
		appPtr = &app;
		emscripten_set_main_loop(Loop, 0, 1);
#else
		while (app.Running())
		{
			const auto delta = app.BeginFrame();
			//...
			app.EndFrame();
		}
#endif
	}
	catch (const std::runtime_error &error)
	{
		std::cout << error.what() << std::endl;
	}
	catch (...)
	{

	}

	return 0;
}
//-----------------------------------------------------------------------------