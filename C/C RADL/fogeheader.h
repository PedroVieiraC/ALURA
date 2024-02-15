#define UP 'w'
#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'

int endgame();
void move(char movement);
int canmove(char movement);
void ghosts();
int whereghost(int x, int y, int* nextx, int* nexty);
