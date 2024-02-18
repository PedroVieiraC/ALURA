#ifndef MAP_H
#define MAP_H

#define HERO '@'
#define EMPTY '.'
#define VERTWALL '|'
#define HORIWALL '-'
#define GHOST 'F'
#define BOMB 'P'


struct map
{
    char **matriz;
    int lines, columns;
};

struct hero
{
    int x, y;
};

struct powerups
{
    int bomb;
    int movecounter;
};


typedef struct map Map;

typedef struct hero Coordinates;

typedef struct powerups Powerups;


void allocmap();
void readmap();
void freememory();

int foundmap(Map *map, Coordinates *charapter, char f);

int iswall(Map *map, int x, int y);
int canmove(char movement);
int movelimits(Map *map, int nextx, int nexty);
int emptyposition(Map *map, int nextx, int nexty);
int validmovement(Map *map, char hero, int x, int y);

int lowerlimit(Map *map);
void randomspawn(Map* map, int dif);
void powerspawn(Map* map, Powerups* powerups);

void movecharapter(Map *map, Coordinates *charapter, int nextx, int nexty);

void copymap(Map* mapcopy,Map* ogmap);

#endif 