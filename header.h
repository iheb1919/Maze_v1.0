#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
int poll_events(void);
void draw_stuff(SDL_Instance instance);
int * keypress(int x, int y, int s);
#endif
