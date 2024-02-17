#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fogeheader.h"
#include "map.h"
#include "ui.h"

void drawp(char draw[4][7], int part)
{
    printf("%s", draw[part]);
}

void printgame(Map *map)
{
    for (int i = 0; i < map->lines; i++)
    {
        for (int size = 0; size < 4; size++)
        {
            for (int j = 0; j < map->columns; j++)
            {
                switch (map->matriz[i][j])
                {
                case GHOST:
                    drawp(gd, size);
                    break;
                case HERO:
                    drawp(hd, size);
                    break;
                case BOMB:
                    drawp(bd, size);
                    break;
                case VERTWALL:
                case HORIWALL:
                    drawp(wd, size);
                    break;
                case EMPTY:
                    drawp(ed, size);
                    break;
                }
            }
            printf("\n");
        }
        // printf("%s\n", map->matriz[i]);
    }
}