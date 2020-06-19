#include <SDL2/SDL.h>
#include "header.h"

/**
 * generate3DProjection - creating 3d projection
 * Return: Nothing
 */
void generate3DProjection(void)
{
    int i, y;
    float perpDistance, distanceProjPlane, projectedWallHeight;
    int wallStripHeight, wallTopPixel, wallBottomPixel;

    for (i = 0; i < NUM_RAYS; i++)
    {
        perpDistance = rays[i].distance * cos(rays[i].rayAngle - p.rotationAngle);
        distanceProjPlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
        projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;

        wallStripHeight = (int)projectedWallHeight;

        wallTopPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
        wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

        wallBottomPixel = (WINDOW_HEIGHT / 2) + (wallStripHeight / 2);
        wallBottomPixel = wallBottomPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottomPixel;

        /* render the wall from wallTopPixel to wallBottomPixel */
        for (y = 0; y < wallTopPixel; y++)
            colorBuffer[(WINDOW_WIDTH * y) + i] = 0xFF333333;

        for (y = wallTopPixel; y < wallBottomPixel; y++)
            colorBuffer[(WINDOW_WIDTH * y) + i] = rays[i].wasHitVertical ? 0xFFFFFFFF : 0xFFCCCCCC;

        for (y = wallBottomPixel; y < WINDOW_HEIGHT; y++)
            colorBuffer[(WINDOW_WIDTH * y) + i] = 0xFF777777;

        /* This For Having No Sky and Replacing It With Taller Walls */
        /*for (y = 0; y < wallTopPixel; y++)
        {
            colorBuffer[(WINDOW_WIDTH * y) + i] = rays[i].wasHitVertical ? 0xFFFFFFFF : 0xFFCCCCCC;
        }*/
    }
}
