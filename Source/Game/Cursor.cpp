#include "stdafx.h"
#include "Cursor.h"

//-----------------------------------------------------------------------------
Cursor::Cursor()
{
	valid() = true;
}
//-----------------------------------------------------------------------------
Cursor::~Cursor()
{
	SDL_FreeCursor(m_cursor);
}
//-----------------------------------------------------------------------------
void Cursor::SetCursor(CursorType cursor)
{
	SDL_SystemCursor id;
	switch (cursor)
	{
	case CursorType::Hand:
		id = SDL_SYSTEM_CURSOR_HAND;
		break;

	case CursorType::Default:
		id = SDL_SYSTEM_CURSOR_ARROW;
		break;
	}

	if (nullptr != m_cursor)
		SDL_FreeCursor(m_cursor);

	m_cursor = SDL_CreateSystemCursor(id);
	SDL_SetCursor(m_cursor);
}
//-----------------------------------------------------------------------------
void Cursor::ShowCursor(bool visible)
{
	SDL_ShowCursor(visible ? SDL_ENABLE : SDL_DISABLE);
}
//-----------------------------------------------------------------------------