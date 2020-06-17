#include <SDL2/SDL.h>
#include "header.h"

/**
* poll_events - getting quit event
* Return: 1 if quitted, 0 if not.
*/
int poll_events(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN: {
				/* If 'ESCAPE' is pressed */
				if (event.key.keysym.sym == SDLK_ESCAPE)
					return (1);

				if (event.key.keysym.sym == SDLK_UP)
					p.walkDirection = +1;
				if (event.key.keysym.sym == SDLK_DOWN)
					p.walkDirection = -1;
				if (event.key.keysym.sym == SDLK_RIGHT)
					p.turnDirection = +1;
				if (event.key.keysym.sym == SDLK_RIGHT)
					p.turnDirection = -1;
				break;
			}
			case SDL_KEYUP: {
				if (event.key.keysym.sym == SDLK_UP)
					p.walkDirection = 0;
				if (event.key.keysym.sym == SDLK_DOWN)
					p.walkDirection = 0;
				if (event.key.keysym.sym == SDLK_RIGHT)
					p.turnDirection = 0;
				if (event.key.keysym.sym == SDLK_RIGHT)
					p.turnDirection = 0;
				break;
			}
		}
	}
	return (0);
}
