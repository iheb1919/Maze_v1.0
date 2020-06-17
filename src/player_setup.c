#include <SDL2/SDL.h>
#include <stdio.h>
#include "header.h"

/**
 * playerCharacter - sets characteristics of player
 * Return: Nothing
 */
void setupPlayer(void)
{
    p.x = WINDOW_WIDTH / 2;
    p.y = WINDOW_HEIGHT / 2;
    p.width = 1;
    p.height = 1;
    p.turnDirection = 0;
    p.walkDirection = 0;
    p.rotationAngle = PI / 2;
    p.walkSpeed = 100;
    p.turnSpeed = 45 * (PI / 180);
}

/**
 * renderPlayer - renders the player
 * @instance: sdl instance
 * Returns: nothing
 */
void renderPlayer(SDL_Instance instance)
{
    SDL_SetRenderDrawColor(instance.renderer, 255, 255, 255, 255);
    SDL_Rect playerRect = {
        p.x * MINIMAP_SCALE_FACTOR,
        p.y * MINIMAP_SCALE_FACTOR,
        p.width * MINIMAP_SCALE_FACTOR,
        p.height * MINIMAP_SCALE_FACTOR
    };
    SDL_RenderFillRect(instance.renderer, &playerRect);

    SDL_RenderDrawLine(
        instance.renderer,
        MINIMAP_SCALE_FACTOR * p.x,
        MINIMAP_SCALE_FACTOR * p.y,
        MINIMAP_SCALE_FACTOR * (p.x + cos(p.rotationAngle) * 40),
        MINIMAP_SCALE_FACTOR * (p.y + sin(p.rotationAngle) * 40)
    );
}

/**
 * movePlayer - moving player
 * @deltaTime: time
 * Return: nothing
 */
void movePlayer(float deltaTime)
{
    float moveStep, newPlayerX, newPlayerY;
    (void)newPlayerX;
    (void)newPlayerY;

    p.rotationAngle += p.turnDirection * p.turnSpeed * deltaTime;

    moveStep = p.walkDirection * p.walkSpeed;

    newPlayerX = p.x + cos(p.rotationAngle) * moveStep;
    newPlayerY = p.y + sin(p.rotationAngle) * moveStep;
}
