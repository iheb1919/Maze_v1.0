#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
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
 * mapHasWallAt - detects wall collision
 * @x: position x
 * @y: position y
 * Return: 0 if true, 1 if false
 */
int mapHasWallAt(float x, float y)
{
    int mapGridIndexX, mapGridIndexY;

    if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) {
        return (FALSE);
    }
    mapGridIndexX = floor(x / TILE_SIZE);
    mapGridIndexY = floor(y / TILE_SIZE);
    return (map[mapGridIndexY][mapGridIndexX] != 0);
}

/**
 * movePlayer - moving player
 * @deltaTime: time
 * Return: nothing
 */
void movePlayer(void)
{
    float moveStep, newPlayerX, newPlayerY;
    (void)newPlayerX;
    (void)newPlayerY;

    p.rotationAngle += p.turnDirection * p.turnSpeed / 25;

    moveStep = p.walkDirection * p.walkSpeed;

    newPlayerX = p.x + cos(p.rotationAngle) * moveStep / 25;
    newPlayerY = p.y + sin(p.rotationAngle) * moveStep / 25;

    if (!mapHasWallAt(newPlayerX, newPlayerY))
    {
        p.x = newPlayerX;
        p.y = newPlayerY;
    }
}
