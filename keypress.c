#include <SDL2/SDL.h>
#include "header.h"
#include <stdio.h>
/**
* main - main work
* Return: always 0.
*/
/*int verif (int x, int y, int rect[14][26])
{
	int xx = 0, yy =0;
	for(int i = 0; i < 14; i++)
	{
			for (int j = 0 ; j < 27; j++)
			{
				if (rect[i][j] == 0 && (x == xx && y == yy) )
				{

					return 0;

				}
				else
				{	xx +=50;
					printf("xx = %d\n",xx);}
			}
				xx = 0;
				yy += 50;
					printf("yy = %d\n",yy);

	}
	xx=0;yy=0;
	printf("x = %d\n",x);
	printf("y = %d\n",y);
	

	int i,j=0
	if (rect[x/50][y/50] != 0)

	return 1;
	}*/
int * keypress(int x, int y, int s, int rect[14][26])
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
		    // int a = ;
		    if (rect[x/50][(y-50)/50] != 0)
		    {y = y-50;}
		    printf("%d  %d\n",x,y);
		    printf("i = %d || j= %d  %d\n",x/50 , (y-50)/50, rect[x/50][(y-50)/50]);
              break;
            case SDLK_DOWN:
		     if (rect[x/50][(y+50)/50] != 0)
		     {y = y+50;}
		    printf("%d  %d\n",x,y);
		     printf("i = %d || j= %d  %d\n",x/50 , (y+50)/50,rect[x/50][(y+50)/50]);
              break;
            case SDLK_LEFT:
		    if (rect[(x-50)/50][y/50] != 0)
		    {x = x-50;}
		    printf("i = %d || j= %d  %d\n",(x-50)/50 , y/50,rect[(x-50)/50][y/50]);
		     printf("%d  %d\n",x,y);
              break;
            case SDLK_RIGHT:
		    if (rect[(x+50)/50][y/50] != 0)
		    {x = x+50;}
		     printf("%d  %d\n",x,y);
		    printf("i = %d || j= %d  %d\n",(x+50)/50 , y/50,rect[(x+50)/50][y/50]);
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
