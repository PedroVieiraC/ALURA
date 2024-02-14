#ifndef MAP_H
#define MAP_H

#define HERO '@'
#define EMPTY '.'
#define VERTWALL '|'
#define HORIWALL '-'
#define GHOST 'F'


struct map
{
    char **matriz;
    int lines, columns;
};

struct charapter
{
    int x, y;
};

typedef struct charapter Charapter;

typedef struct map Map;

void allocmap();
void readmap();
void freememory();
void printgame();
void foundmap(Map *map, Charapter *charapter, char f);
int movelimits(Map *map, int nextx, int nexty);
int emptyposition(Map *map, int nextx, int nexty);
int canmove(char movement);
void movecharapter(Map *map, Charapter *charapter, int nextx, int nexty);

#endif /* MAP_H */