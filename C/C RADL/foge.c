#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "map.h"
#include "map.c"
#include "fogeheader.h"

Map map;

Coordinates hero;

Powerups powerups;

int endgame()
{
    Coordinates pos;
    int found = foundmap(&map, &pos, HERO);
    return !found;
}

int whereghost(int x, int y, int *nextx, int *nexty)
{
    int moves[4][2] = {
        {x, y + 1}, // w
        {x - 1, y}, // a
        {x, y - 1}, // s
        {x + 1, y}, // d
    };

    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        int move = rand() % 4;

        if (validmovement(&map, GHOST, moves[move][0], moves[move][1]))
        {
            *nextx = moves[move][0];
            *nexty = moves[move][1];
            return 1;
        }
    }
    return 0;
}

void ghosts()
{
    Map mapcopy;

    copymap(&mapcopy, &map);

    for (int i = 0; i < map.lines; i++)
    {
        for (int j = 0; j < map.columns; j++)
        {
            if (mapcopy.matriz[i][j] == GHOST)
            {

                int nextx, nexty;
                int found = whereghost(i, j, &nextx, &nexty);

                if (found)
                    moveelement(&map, i, j, nextx, nexty, NULL);
            }
        }
    }
    freememory(&mapcopy);
}

void move(char movement)
{

    if (!canmove(movement))
        return;

    int nextx = hero.x;
    int nexty = hero.y;

    switch (movement)
    {
    case UP:

        nextx--;
        break;
    case LEFT:

        nexty--;
        break;
    case DOWN:

        nextx++;
        break;
    case RIGHT:

        nexty++;
        break;
    }

    if (!validmovement(&map, HERO, nextx, nexty))
        return;

    if (ischarapter(&map, BOMB, nextx, nexty))
    {
        powerups.bomb = 1;
    }

    moveelement(&map, hero.x, hero.y, nextx, nexty, &hero);
}

void blows()
{

    for (int i = hero.x - 1; i <= hero.x+1; i++)
    {
        for (int j = hero.y - 1; j <= hero.y+1; j++)
        {
            if(map.matriz[i][j] == '@') j++;

            if (movelimits(&map, i, j))
            {
                if (iswall(&map, i, j))
                {
                    break;
                }
                printf("%i %i\n", i+1, j+1);
            
                 map.matriz[i][j] = EMPTY;
            }
        }
    }
}

void powerup(char command)
{
    if (command == BLOW)
    {
        blows();
    }
}

int main()
{
    readmap(&map);
    foundmap(&map, &hero, HERO);

    do
    {

        printf("bomb %i\n", powerups.bomb);

        printgame(&map);

        char command;
        scanf(" %c", &command);
        move(tolower(command));
        powerup(tolower(command));
        ghosts();

    } while (!endgame(&map));

    printf("colidiu\n");

    freememory(&map);

    return 0;
}