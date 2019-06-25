#pragma once

struct ApplicationConfig
{
	std::string title{ "Game" };
	
	uint32_t width{ 640 };
	uint32_t height{ 480 };
	bool fullscreen{ false };

	uint32_t fps{ 60 };
};