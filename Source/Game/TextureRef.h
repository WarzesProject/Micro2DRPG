#pragma once

#include "Texture.h"

struct TextureRef
{
	void Free() { texture.reset(); }
	std::shared_ptr<Texture> texture;
};