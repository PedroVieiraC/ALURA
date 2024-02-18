#ifndef FOGE_H
#define FOGE_H

#define UP 'w'
#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'
#define BLOW 'b'

int endgame();
void move(char movement);

int canmove(char movement);
void ghosts();
int whereghost(int x, int y, int* nextx, int* nexty);


void playagain();
int main();

void powerup(char command);
void blows();

#endif