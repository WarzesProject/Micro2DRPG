#pragma once

#include "CoreInput.h"
#include "Vector2d.h"

class Input : public Module<Input>
{
public:
	Input();

	void Update();

	bool KeyDown(KeyboardKey key) const;
	bool KeyUp(KeyboardKey key) const;
	bool KeyPress(KeyboardKey key) const;

	bool MouseDown(MouseButton button) const;
	bool MouseUp(MouseButton button) const;
	bool MouseClick(MouseButton button) const;
	bool MouseMove() const;
	const Vec2i& MousePosition() const;

	bool Quit() const;

private:
	int getKey(KeyboardKey key) const;
	int getButton(MouseButton button) const;

	std::vector<bool> m_keyboardKeysDown = std::vector<bool>(SDL_NUM_SCANCODES, false);
	std::vector<bool> m_keyboardKeysPress = std::vector<bool>(SDL_NUM_SCANCODES, false);

	// Hard coded max mouse button number, SDL does not provide the info
	// We only support the three basic mouse buttons: left, middle and right
	// Need to set it to 4 instead of 3, because the first button starts at 1, not 0
	const uint32_t MaxMouseButtons{ 4 };
	std::vector<bool> m_mouseButtonsDown = std::vector<bool>(MaxMouseButtons, false);
	std::vector<bool> m_mouseButtonsClick = std::vector<bool>(MaxMouseButtons, false);

	mutable Vec2i m_mousePos;

	bool m_mouseMove{ false };

	bool m_quit{ false };
};