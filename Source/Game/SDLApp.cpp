#include "stdafx.h"
#include "SDLApp.h"

//-----------------------------------------------------------------------------
void SDLApp::init()
{
#ifdef EMSCRIPTEN
	if (SDL_Init(SDL_INIT_EVERYTHING & ~(SDL_INIT_TIMER | SDL_INIT_HAPTIC)) != )
#else
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
#endif
		throw SDLException("SDL_Init");

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
		throw SDLException("IMG_Init");

	if (TTF_Init() != 0)
		throw SDLException("TTF_Init");

	if (0 == Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG))
		throw SDLException("Mix_Init");

	if (-1 == Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024))
		throw SDLException("Mix_OpenAudio");


	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
}
//-----------------------------------------------------------------------------
void SDLApp::close()
{
	// see https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer.html#SEC10
	while (Mix_Init(0))
		Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
//-----------------------------------------------------------------------------