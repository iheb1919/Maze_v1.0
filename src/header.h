#ifndef _DEMO_H_
#define _DEMO_H_

#include <SDL2/SDL.h>

#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

#define MINIMAP_SCALE_FACTOR 1.0

#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)

#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS WINDOW_WIDTH

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

extern const int map[MAP_NUM_ROWS][MAP_NUM_COLS];

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

struct Player
{
	float x;
	float y;
	float width;
	float height;
	int turnDirection;
	int walkDirection;
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
};

extern struct Player p;

/* Functions */
int init_instance(SDL_Instance *);
int poll_events(void);
void renderMap(SDL_Instance instance);
void setupPlayer(void);
void renderPlayer(SDL_Instance instance);
void movePlayer(float deltaTime);
void update(int ticksLastFrame);
#endif
