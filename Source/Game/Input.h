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

	std::vector<bool> m_mouseButtonsDown = std::vector<bool>(4, false);
	std::vector<bool> m_mouseButtonsClick = std::vector<bool>(4, false);

	mutable Vec2i m_mousePos;

	bool m_mouseMove{ false };

	bool m_quit{ false };
};