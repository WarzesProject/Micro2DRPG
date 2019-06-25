#pragma once

struct Color
{
	Color() = default;
	Color(uint8_t nr, uint8_t ng, uint8_t nb) : r(nr), g(ng), b(nb), a(255) {}
	Color(uint8_t nr, uint8_t ng, uint8_t nb, uint8_t na) : r(nr), g(ng), b(nb), a(na) {}

	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;
	uint8_t a = 0;
};