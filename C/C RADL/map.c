#include <stdio.h>
#include <stdlib.h>

#include "fogeheader.h"
#include "map.h"

int emptyposition(Map *map, int nextx, int nexty){
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

void movecharapter(Map* map, Charapter* charapter,int nextx, int nexty){
    map->matriz[nextx][nexty] = HERO;
    map->matriz[charapter->x][charapter->y] = EMPTY;
    charapter->x = nextx;
    charapter->y = nexty;
}

int movelimits(Map *map, int nextx, int nexty)
{
    if (nextx >= map->lines)
        return 0;

    if (nexty >= map->columns)
        return 0;
    
    return 1;
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

void foundmap(Map *map, Charapter *charapter, char f)
{
    for (int i = 0; i < map->lines; i++)
    {
        for (int j = 0; j < map->columns; j++)
        {
            if (map->matriz[i][j] == f)
            {
                charapter->x = i;
                charapter->y = j;
                break;
            }
        }
    }
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