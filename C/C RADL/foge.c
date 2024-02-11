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

void move(char movement)
{
    int x, y;

    for (int i = 0; i < map.lines; i++)
    {
        for (int j = 0; j < map.columns; j++)
        {
            if (map.matriz[i][j] == '@')
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (movement)
    {
    case 'w':
        map.matriz[x - 1][y] = '@';
        map.matriz[x][y] = '.';
        break;
    case 'a':
        map.matriz[x][y - 1] = '@';
        map.matriz[x][y] = '.';
        break;
    case 's':
        map.matriz[x + 1][y] = '@';
        map.matriz[x][y] = '.';
        break;
    case 'd':
        map.matriz[x][y + 1] = '@';
        map.matriz[x][y] = '.';

        break;
    }



    // printf("%d %d\n",x+1,y+1);
}

int main()
{
    readmap(&map);

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