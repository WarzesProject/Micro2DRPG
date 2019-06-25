#pragma once

#define SE_STRINGIZE( _n ) SE_STRINGIZE_2( _n )
#define SE_STRINGIZE_2( _n ) #_n
#define TODO( _msg ) __pragma(message("" __FILE__ "(" SE_STRINGIZE(__LINE__) ") TODO: " _msg))

//#pragma warning(push, 1)

//-----------------------------------------------------------------------------
// STL Header
#include <exception>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

//-----------------------------------------------------------------------------
// 3rd Header
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <GL/glew.h>

#include <glm/glm.hpp>

//#pragma warning(pop)