#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
} Controle;

void welcome(){
    printf("Welcome to hangman game!!!\n");
    printf("      +---+       \n");  
    printf("      |   |       \n");  
    printf("      O   |       \n");  
    printf("     /|\\  |       \n");  
    printf("     / \\  |       \n");  
    printf("          |       \n");  
    printf("    ========='''] \n");
}

char fguess(char guess, char guess_storage[], int *tryes){
        scanf(" %c", &guess);
        guess = tolower(guess);

        guess_storage[*tryes] = guess;
        *tryes = *tryes+1;

    return guess;
}

int main() {
    //declaração palavra secreta
    
    char secretword[20];

    //write in
    sprintf(secretword, "teste");

    int hit = 0, lose = 0;

    char guess_storage[26];
    int tryes = 0;

    //welcome
    welcome();
    
    do {
        for(int i=0;i<strlen(secretword);i++){

            int found=0;

            for(int j=0; j<tryes;j++){
                
                if(guess_storage[j] == secretword[i]){
                    found = 1;
                    break;
                } 

            }
            if(found) printf("%c",secretword[i]);
            else printf("_");



        } printf("\n");

        char guess;
        fguess(guess, guess_storage,&tryes);


        for(int i=0;i<strlen(secretword);i++){
            if(guess == secretword[i]){
                printf("letter %c in %i position\n",guess,i+1);
            }
        }

      
    }while(!hit && !lose);



    //printf("%s",secretword);

    return 0;
}