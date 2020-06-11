#include <SDL2/SDL.h>
#include "header.h"

/**
* main - main work
* Return: always 0.
*/
int main(void)
{
	SDL_Instance instance;
	int y=50;
	int x=50;
	char s=0;

	if (init_instance(&instance) != 0)
		return (1);


	while ("C is awesome")
	{
		  int  *r = keypress(x,y,s);
	  x = r[0];
	  y = r[1];
	  s = r[2];
	  SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
	  SDL_RenderClear(instance.renderer);
		if (poll_events() == 1)
			break;
		/* drawing will be done here */
		draw_stuff(instance);
		SDL_Rect rect2 = {x,y,50,50};
		SDL_RenderFillRect(instance.renderer, &rect2);
		SDL_SetRenderDrawColor(instance.renderer, 0,0,0,0);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
