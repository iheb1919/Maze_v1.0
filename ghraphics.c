#include <SDL2/SDL.h>
#include "header.h"

/**
* draw_stuff - draws a line
* @instance: sdl instance
*/
void draw_stuff(SDL_Instance instance, int rect[14][26])
{
	SDL_Rect rec;
	rec.x = 0;
	rec.y = 0;
	rec.w = 50;
	rec.h = 50;
	/*int y=100;
	int x=500;
	char s=0;
	 int  *r = keypress(x,y,s);
	  x = r[0];
	  y = r[1];
	  s = r[2];*/
	SDL_SetRenderDrawColor(instance.renderer, 250,0,0,0);
	for(int i = 0; i < 14; i++)
	{
			for (int j = 0 ; j < 27; j++)
			{
				if (rect[i][j] == 0 )
				{	SDL_RenderFillRect(instance.renderer,&rec);
					rec.x += 50;
				}
				else
					rec.x +=50;
			}
				rec.x =0;
				rec.y += 50;

	}
/*	SDL_Rect rect2 = {x,y,50,50};
	SDL_RenderFillRect(instance.renderer, &rect2);*/
}
