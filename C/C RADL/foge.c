#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "map.h"
#include "map.c"
#include "fogeheader.h"

Map map;

Charapter charapter;

int endgame()
{
    int end = 0;
    // scanf("%i", &end);
    return end;
}

void ghosts(){
    
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

    if (!movelimits(&map, nextx, nexty))
        return;

    if (!emptyposition(&map, nextx, nexty))
        return;

    movecharapter(&map, &charapter, nextx, nexty);
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

    } while (!endgame(&map));

    freememory(&map);

    return 0;
}