#include <SDL2/SDL.h>
#include "header.h"
#include <stdio.h>
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
	while (s == 0)
	{
	  int  *r = keypress(x,y,s);
	  x = r[0];
	  y = r[1];
	  s = r[2];
	  SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
	  SDL_RenderClear(instance.renderer);
	  /* drawing will be done here */
	  draw_stuff(instance);
	  SDL_Rect rect =  {50, 50, 500, 500};
	  SDL_RenderFillRect(instance.renderer, &rect);
	  SDL_SetRenderDrawColor(instance.renderer, 255,255,0,255);
	  SDL_Rect rect2 = {x,y,50,50};
	  SDL_RenderFillRect(instance.renderer, &rect2);
	  SDL_Point a = {50,50}, b={50,100},c={100,75};
	  SDL_SetRenderDrawColor(instance.renderer, 132,124,0,124);
	  SDL_RenderDrawLine(instance.renderer, a.x,a.y,b.x,b.y);
	  SDL_RenderDrawLine(instance.renderer, a.x,a.y,c.x,c.y);
	  SDL_RenderDrawLine(instance.renderer, b.x,b.y,c.x,c.y);
	  SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
