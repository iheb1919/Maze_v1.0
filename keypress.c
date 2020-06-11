#include <SDL2/SDL.h>
#include "header.h"
#include <stdio.h>
/**
* main - main work 
* Return: always 0.
*/
int * keypress(int x, int y, int s)
{
  int * r = malloc (sizeof(int) * 3);
  SDL_Event event;
  while (SDL_PollEvent(&event)!=0)
    {
      switch(event.type)
        {
        case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
            {
            case SDLK_UP:
              y = y-5;
              break;
            case SDLK_DOWN:
              y = y+5;
              break;
            case SDLK_LEFT:
              x = x-5;
              break;
            case SDLK_RIGHT:
              x = x+5;
              break;
            case SDLK_ESCAPE:
              s = 1;
              break;
                    }
                }
            }
  r[0]=x;
  r[1]=y;
  r[2]=s;
  return (r);
}
