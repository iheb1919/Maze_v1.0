#include <SDL2/SDL.h>
#include "header.h"

/**
 * update - updating
 * Return: nothing
 */
void update(void)
{
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TIME_LENGTH));

    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

    ticksLastFrame = SDL_GetTicks();

    movePlayer(deltaTime);
}

