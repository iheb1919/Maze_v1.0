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
void draw_stuff(SDL_Instance instance, int rect[14][26]);
int * keypress(int x, int y, int s, int rect[14][26]);
int verif(int x, int y, int rect [14][26]);
#endif
