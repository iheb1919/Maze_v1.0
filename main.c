#include <SDL2/SDL.h>
#include "header.h"

void draw_stuff(SDL_Instance instance)
{
	SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawLine(instance.renderer, 10, 10, 100, 100);
}


int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
		return (1);


	while ("C is awesome")
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		draw_stuff(instance);
		SDL_RenderPresent(instance.renderer);
	}
	return (0);
}
