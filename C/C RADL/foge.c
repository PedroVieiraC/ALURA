#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "map.h"
#include "map.c"
#include "fogeheader.h"

Map map;

Charapter charapter;

int endgame()
{
    Charapter pos;
    int found = foundmap(&map, &charapter, HERO);
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

    int nextx = charapter.x;
    int nexty = charapter.y;

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

    moveelement(&map, charapter.x, charapter.y, nextx, nexty, &charapter);
}

int main()
{
    readmap(&map);
    foundmap(&map, &charapter, HERO);

    do
    {
        printgame(&map);

        char command;
        scanf(" %c", &command);
        move(tolower(command));
        ghosts();
    } while (!endgame(&map));

    printf("colidiu\n");

    freememory(&map);

    return 0;
}