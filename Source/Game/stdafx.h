#pragma once

#define SE_STRINGIZE( _n ) SE_STRINGIZE_2( _n )
#define SE_STRINGIZE_2( _n ) #_n
#define TODO( _msg ) __pragma(message("" __FILE__ "(" SE_STRINGIZE(__LINE__) ") TODO: " _msg))

//#pragma warning(push, 1)

//-----------------------------------------------------------------------------
// STL Header
#include <exception>
#include <memory>
#include <chrono>
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <unordered_map>

//-----------------------------------------------------------------------------
// 3rd Header
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
//#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#ifdef EMSCRIPTEN
#	include <emscripten.h>
#endif

//#pragma warning(pop)

//-----------------------------------------------------------------------------

//#define GET_TYPE_ID(T)      typeid(T).hash_code()
//#define GET_TYPE_NAME(T)    typeid(T).name()

// Engine Header
#include "Module.h"