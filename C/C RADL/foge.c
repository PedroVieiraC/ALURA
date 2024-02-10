#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "fogeheader.h"

char **map;
int lines, columns;

typedef struct
{
    int x, y;

} charapter;

void allocmap()
{
    // part of code to dynamic alloc the map
    map = malloc(sizeof(char *) * lines);
    for (int i = 0; i < lines; i++)
    {
        map[i] = malloc(sizeof(char) * (columns + 1));
    }
}

void readmap()
{
    FILE *f;
    f = fopen("map.txt", "r");
    if (!f)
    {
        printf("Can't open the map file\n");
        exit(1);
    }

    fscanf(f, "%d %d", &lines, &columns);

    allocmap();

    for (int i = 0; i < lines; i++)
    {
        fscanf(f, "%s", map[i]);
    }
    fclose(f);
}

void freememory()
{
    for (int i = 0; i < lines; i++)
    {
        free(map[i]);
    }
    free(map);
}

void printgame()
{
    for (int i = 0; i < lines; i++)
    {
        printf("%s\n", map[i]);
    }
}

int endgame()
{
    int end = 0;
    // scanf("%i", &end);
    return end;
}

void move(char movement)
{
    int x, y;

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (map[i][j] == '@')
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
        map[x - 1][y] = '@';
        map[x][y] = '.';
        break;
    case 'a':
        map[x][y - 1] = '@';
        map[x][y] = '.';
        break;
    case 's':
        map[x + 1][y] = '@';
        map[x][y] = '.';
        break;
    case 'd':
        map[x][y + 1] = '@';
        map[x][y] = '.';

        break;
    }



    // printf("%d %d\n",x+1,y+1);
}

int main()
{
    readmap();

    do
    {
        printgame();

        char command;
        scanf(" %c", &command);
        move(tolower(command));

    } while (!endgame());

    freememory();

    return 0;
}