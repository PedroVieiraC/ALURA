#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fogeheader.h"
#include "map.h"

void copymap(Map *mapcopy, Map *ogmap)
{
    mapcopy->lines = ogmap->lines;
    mapcopy->columns = ogmap->columns;

    allocmap(mapcopy);

    for (int i = 0; i < ogmap->lines; i++)
    {
        strcpy(mapcopy->matriz[i], ogmap->matriz[i]);
    }
}

int iswall(Map *map, int x, int y)
{
    return map->matriz[x][y] == VERTWALL || map->matriz[x][y] == HORIWALL;
}

int ischarapter(Map *map, char charapter, int x, int y)
{
    return map->matriz[x][y] == charapter;
}

int movelimits(Map *map, int nextx, int nexty)
{
    if (nextx >= map->lines)
        return 0;

    if (nexty >= map->columns)
        return 0;

    return 1;
}

int validmovement(Map *map, char hero, int x, int y)
{

    return movelimits(map, x, y) &&
           !iswall(map, x, y) &&
           !ischarapter(map, hero, x, y);
}

int emptyposition(Map *map, int nextx, int nexty)
{
    return map->matriz[nextx][nexty] == EMPTY;
}

int canmove(char movement)
{
    if (movement == UP ||
        movement == LEFT ||
        movement == RIGHT ||
        movement == DOWN)
    {
        return 1;
    }

    return 0;
}

void moveelement(Map *map, int x, int y, int nextx, int nexty, Charapter *charapter)
{
    char aux = map->matriz[x][y];
    map->matriz[nextx][nexty] = aux;
    map->matriz[x][y] = EMPTY;

    if (charapter == NULL)
        return;

    charapter->x = nextx;
    charapter->y = nexty;
}

void allocmap(Map *map)
{
    // part of code to dynamic alloc the map
    map->matriz = malloc(sizeof(char *) * map->lines);
    for (int i = 0; i < map->lines; i++)
    {
        map->matriz[i] = malloc(sizeof(char) * (map->columns + 1));
    }
}

int foundmap(Map *map, Charapter *charapter, char f)
{
    for (int i = 0; i < map->lines; i++)
    {
        for (int j = 0; j < map->columns; j++)
        {
            if (map->matriz[i][j] == f)
            {
                charapter->x = i;
                charapter->y = j;
                return 1;
            }
        }
    }
    return 0;
}

void readmap(Map *map)
{
    FILE *f;
    f = fopen("map.txt", "r");
    if (!f)
    {
        printf("Can't open the map file\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(map->lines), &(map->columns));

    allocmap(map);

    for (int i = 0; i < map->lines; i++)
    {
        fscanf(f, "%s", map->matriz[i]);
    }
    fclose(f);
}

void freememory(Map *map)
{
    for (int i = 0; i < map->lines; i++)
    {
        free(map->matriz[i]);
    }
    free(map->matriz);
}

void printgame(Map *map)
{
    for (int i = 0; i < map->lines; i++)
    {
        printf("%s\n", map->matriz[i]);
    }
}