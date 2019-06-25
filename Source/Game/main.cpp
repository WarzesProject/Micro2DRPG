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
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	try
	{
		ApplicationConfig config;
		Application app(config);
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