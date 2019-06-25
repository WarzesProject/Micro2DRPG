#include "stdafx.h"
#include "Utility.h"

//-----------------------------------------------------------------------------
std::string GetResourcePath(const std::string &subDir)
{
#ifdef _WIN32
	const char PATH_SEP = '\\';
#else
	const char PATH_SEP = '/';
#endif
	static std::string baseRes;
	if (baseRes.empty())
	{
		char *basePath = SDL_GetBasePath();
		if (basePath)
		{
			baseRes = basePath;
			SDL_free(basePath);
		}
		else
			throw std::runtime_error("Error getting resource path: " + std::string(SDL_GetError()));

		size_t pos = baseRes.rfind("bin");
		baseRes = baseRes.substr(0, pos+4) + "data" + PATH_SEP;
	}
	return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
}
//-----------------------------------------------------------------------------
std::string GetStoragePath()
{
	TODO("SDL_GetPrefPath()");
	return "";
}
//-----------------------------------------------------------------------------