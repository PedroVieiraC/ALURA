#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fogeheader.h"
#include "map.h"
#include "ui.h"

#define SIZELIMIT 4

char gd[4][7] = {
    {" .-.  "},
    {"| OO| "},
    {"|   | "},
    {"'^^^' "}};

char wd[4][7] = {
    {"......"},
    {"......"},
    {"......"},
    {"......"}};

char hd[4][7] = {
    {" .--. "},
    {"/ _.-'"},
    {"\\  '-."},
    {" '--' "}};

char bd[4][7] = {
    {"      "},
    {" .-.  "},
    {" |B|  "},
    {" '-'  "}};

char ed[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}};

void drawp(char draw[4][7], int part)
{
    printf("%s", draw[part]);
}

void printgame(Map *map)
{
    for (int i = 0; i < map->lines; i++)
    {
        for (int size = 0; size < SIZELIMIT; size++)
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
    }
}

void died()
{
    printf("\033[0;41m\n"); // black background
    printf("                     _                         \n");
    printf("                    | |                        \n");
    printf(" _   _  ___  _   _  | | ___  ___  ___          \n");
    printf("| | | |/ _ \\| | | | | |/ _ \\/ __|/ _ \\      \n");
    printf("| |_| | (_) | |_| | | | (_) \\__ \\  __/       \n");
    printf(" \\__, |\\___/ \\__,_| |_|\\___/|___/\\___|    \n");
    printf("  __/ |                                        \n");
    printf(" |___/                                         \n");
    printf(" A ghost found you, try again\n");
    printf("\033[0m\n"); // Reseta para a cor padrão
}

void won()
{
    printf("\033[0;40m\n"); // black background
    printf("                              _         _ \n");
    printf("                             (_)       | |\n");
    printf(" _   _  ___  _   _  __      ___ _ __   | |\n");
    printf("| | | |/ _ \\| | | | \\ \\ /\\ / / | '_ \\  | |\n");
    printf("| |_| | (_) | |_| |  \\ V  V /| | | | | |_|\n");
    printf(" \\__, |\\___/ \\__,_|   \\_/\\_/ |_|_| |_| (_)\n");
    printf("  __/ |\n");
    printf(" |___/\n");
    printf("\033[0m\n"); // Reseta para a cor padrão
}

void welcome()
{
    printf(" _    _ _____ _     _____ ________  ___ _____   _         \n");
    printf("| |  | |  ___| |   /  __ \\  _  |  \\/  ||  ___| | |      \n");
    printf("| |  | | |__ | |   | /  \\/ | | | .  . || |__   | |       \n");
    printf("| |\\/| |  __|| |   | |   | | | | |\\/| ||  __|  | |      \n");
    printf("\\  /\\  / |___| |___| \\__/\\ \\_/ / |  | || |___  |_|   \n");
    printf(" \\/  \\/ \\____/\\_____\\____/\\___/\\_|  |_/\\____/  (_)\n");
    printf("                                                          \n");

    for (int i = 0; i < 4; i++)
        printf("%s %s\n", hd[i], gd[i]);
    printf("This is foge game!\n(1)Play\n(2)Rules\n(3)Exit\n");

    int menu;
    scanf("%i", &menu);

    if (menu == 1)
        return;
    if (menu == 2)
        rules();
    if(menu == 3)
        exit(1);
}

void rules()
{
    printf("\n\033[0;40m HOW THE GAME WORKS?\033[0m\n\nThe game ends when the pacman dies or when all the ghosts dies.\n");
    printf("There's two ways to kill a ghost. Passing through or demolishing the bomb");

    printf("\n\n\033[0;40m KEYS\033[0m\n");
    printf("UP: W\nLEFT: A\nDOWN: S\nRIGHT: D\nBOMB: B\n");

    printf("There is 3 types of interactives parts in game.\n");
    
    printf("\n\033[0;40mTHE HERO\033[0m\n");
    for (int i = 0; i < 4; i++)
        printf("%s\n", hd[i]);

    printf("\n\033[0;40mTHE GHOST\033[0m\n");
    for (int i = 0; i < 4; i++)
        printf("%s\n", gd[i]);

    printf("\n\033[0;40mTHE BOMB\033[0m");
    for (int i = 0; i < 4; i++)
        printf("%s\n", bd[i]);
        
    printf("\nPress any key to back to menu\n");
    char any;
    scanf(" %c", &any);
    welcome();
}

int dif(){
    printf("Choose the difficulty\n (1)Easy (2)Medium (3)HARD\n");
    int dif;
    scanf("%i", &dif);
    return dif;
}