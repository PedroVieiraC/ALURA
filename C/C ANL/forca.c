#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
} Controle;

int main() {
    char palavrasecreta[20];

    sprintf(palavrasecreta, "teste\n");

    int acertou = 0, enforcou = 1;

    do {
        char chute;
        scanf("%c", &chute);

        for(int i=0;i< strlen(palavrasecreta); i++){
            if(palavrasecreta[i] == chute) {
                printf("A posição %d tem essa letra\n",i+1);
            }
        }
    }while(!acertou && !enforcou);



    //printf("%s",palavrasecreta);

    return 0;
}