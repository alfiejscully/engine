#include "Keyboard.h"

bool Keyboard::getKey(int keyCode)
{
	return true;
}

bool Keyboard::getKeyDown(int keyCode)
{
	return true;
}

bool Keyboard::getKeyUp(int keyCode)
{
	return true;
}

void Keyboard::PollEvents()
{
	SDL_Event event = { 0 };

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_quit = true;
		}
	}
}
