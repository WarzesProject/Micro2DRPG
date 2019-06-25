#pragma once

enum class CursorType
{
	Default,
	Hand,
};

class Cursor : public Module<Cursor>
{
public:
	Cursor();
	~Cursor();
	void SetCursor(CursorType cursor);
	void ShowCursor(bool visible);

private:
	SDL_Cursor *m_cursor{ nullptr };
};