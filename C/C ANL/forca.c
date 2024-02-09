#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "header.h"

char secretword[WORD_SIZE];
char guess_storage[STORAGE_SIZE];
int tryes = 0, misstryes = 0, limit, difficulty;

// function to give welcome to user
void start()
{
    printf("      +---+       \n");
    printf("      |   |       \n");
    printf("      O   |       \n");
    printf("     /|\\  |       \n");
    printf("     / \\  |       \n");
    printf("          |       \n");
    printf("    ========='''] \n");
    printf("Welcome to hangman game!!!\n");
    pressets();
}
// function to set difficult
void pressets()
{
    printf("Choose the difficulty. \n(1)Hard (2)Medium (3)Easy\n");
    scanf("%i", &difficulty);
    switch (difficulty)
    {
    case 1:
        limit = 5;
        break;
    case 2:
        limit = 10;
        break;
    case 3:
        limit = 20;
        break;
    default:
        limit = 1;
        break;
    }
}
// void to choose the secret word
void secretwordchoose()
{

    FILE *f;
    f = fopen("words.txt", "r");

    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    int amword;
    fscanf(f, "%d", &amword);

    srand(time(0));
    int line = rand() % amword;

    for (int i = 0; i < line; i++)
    {
        fscanf(f, "%s", secretword);
    }

    for (int i = 0; i < strlen(secretword); i++)
    {
        secretword[i] = tolower(secretword[i]);
    }

    fclose(f);
    // sprintf(secretword, "teste");
}
void missdrawer()
{
    if ((misstryes <= 0 && difficulty == 1) || (misstryes <= 2 && difficulty == 2) || (misstryes <= 4 && difficulty == 3))
    {
        printf("        +---+             \n");
        printf("        |   |             \n");
        printf("        O   |             \n");
        printf("            |             \n");
        printf("            |             \n");
        printf("            |             \n");
        printf("        =========''', ''' \n");
    }
    else if ((misstryes <= 1 && difficulty == 1) || (misstryes <= 4 && difficulty == 2) || (misstryes <= 8 && difficulty == 3))
    {
        printf("        +---+             \n");
        printf("        |   |             \n");
        printf("        O   |             \n");
        printf("        |   |             \n");
        printf("            |             \n");
        printf("            |             \n");
        printf("        =========''', ''' \n");
    }
    else if ((misstryes <= 2 && difficulty == 1) || (misstryes <= 6 && difficulty == 2) || (misstryes <= 12 && difficulty == 3))
    {
        printf("        +---+             \n");
        printf("        |   |             \n");
        printf("        O   |             \n");
        printf("       /|   |             \n");
        printf("            |             \n");
        printf("            |             \n");
        printf("        =========''', ''' \n");
    }
    else if ((misstryes <= 3 && difficulty == 1) || (misstryes <= 8 && difficulty == 2) || (misstryes <= 16 && difficulty == 3))
    {
        printf("        +---+             \n");
        printf("        |   |             \n");
        printf("        O   |             \n");
        printf("       /|\\  |             \n");
        printf("            |             \n");
        printf("            |             \n");
        printf("        =========''', ''' \n");
    }
    else if ((misstryes <= 4 && difficulty == 1) || (misstryes <= 10 && difficulty == 2) || (misstryes < 20 && difficulty == 3))
    {
        printf("        +---+             \n");
        printf("        |   |             \n");
        printf("        O   |             \n");
        printf("       /|\\  |             \n");
        printf("       /    |             \n");
        printf("            |             \n");
        printf("        =========''', ''' \n");
    }
    else if ((misstryes == 5 && difficulty == 1) || (misstryes == 10 && difficulty == 2) || (misstryes == 20 && difficulty == 3))
    {
        printf("        +---+             \n");
        printf("        |   |             \n");
        printf("        O   |             \n");
        printf("       /|\\  |             \n");
        printf("       / \\  |             \n");
        printf("            |             \n");
        printf("        =========''', ''' \n");
    }
    printf("You already gave %i guesses\n", misstryes);
}
// function that manage the game work
void game()
{
    for (int i = 0; i < strlen(secretword); i++)
    {
        // if found, prints the letter, else print the underscore
        if (correcttry(secretword[i]))
            printf("%c", secretword[i]);
        else
            printf("_");
    }
    printf("\n");
}


// function to guess a letter in the game
void fguess()
{
    char guess;
    printf("Try a letter: ");
    scanf(" %c", &guess);
    guess = tolower(guess);

    guess_storage[tryes] = guess;

    misscounter(guess);

    if (miss())
        tryes++;
}

// function to verify if the guess are in the secret word
int correcttry(char letter)
{
    int found = 0;
    for (int j = 0; j < tryes; j++)
    {
        if (guess_storage[j] == letter)
        {
            found = 1;
            break;
        }
    }
    return found;
}

// function to see if the misses are the same as the limit
int lose()
{
    return misstryes >= limit;
}

int miss()
{
    int exist = 0;
    for (int i = 0; i < strlen(secretword); i++)
    {
        if (guess_storage[tryes] == secretword[i])
        {
            exist = 1;
        }
    }
    return exist;
}


// function that helps the printer off game
int misscounter(char guess)
{
    int exist = 0;
    // for to looks if the letter are in the word
    for (int j = 0; j < strlen(secretword); j++)
    {
        if (guess_storage[tryes] == secretword[j])
        {
            exist = 1;
        }
    }

    int alrused = 0;
    // for to looks if the letter has already be used
    
    if (!exist && !alrused)
    {
        misstryes++;
    }

    return exist;
}

// function to see if all the letters of sw was already guessed
int win()
{
    for (int i = 0; i < strlen(secretword); i++)
    {
        if (!correcttry(secretword[i]))
        {
            return 0;
        }
    }
    return 1;
}

void endgame()
{
    missdrawer();
    if (win())
    {
    printf("          .-=========-.     \n");
    printf("          \\'-=======-'/    \n");
    printf("          _|   .=.   |_     \n");
    printf("         ((|  {{1}}  |))    \n");
    printf("          \\|   /|\\   |/   \n");
    printf("           \\__ '`' __/     \n");
    printf("             _`) (`_        \n");
    printf("           _/_______\\_     \n");
    printf("          /___________\\    \n");
    printf("            YOU WIN!!!      \n");
    }
    else
    {
printf("   ____  __  __   _   ______     \n");
printf("  / __ \\/ / / /  / | / / __ \\  \n");
printf(" / / / / /_/ /  /  |/ / / / /    \n");
printf("/ /_/ / __  /  / /|  / /_/ /     \n");
printf("\\____/_/ /_/  /_/ |_/\\____/    \n");
printf("    YOU LOSE, TRY AGAIN!         \n");
    }
    printf("secret word was %s\n", secretword);
    addword();
}

void addword(){
    printf("Do you want to add a new word in the game?\n (Y)Yes (N)No\n");
    char choose;

    scanf(" %c",&choose);
    
    if(tolower(choose) == 'y'){
        
        char newword[WORD_SIZE];
        printf("Write the new word\n");
        scanf("%s",newword);

        FILE *f;

        f = fopen("words.txt","r+");

        if(f == 0){
            printf("Impossível abrir o arquivo\n");
            exit(1);
        }

        int qtt;
        fscanf(f,"%i",&qtt);
        qtt++;

        fseek(f,0,SEEK_SET);

        fprintf(f,"%d",qtt);

        fseek(f,0,SEEK_END);

        fprintf(f,"\n%s",newword);
    }
    if(tolower(choose) == 'n'){
        exit(1);
    }
}

int main()
{
    // declaração palavra secreta
    start();

    secretwordchoose(secretword);

    do
    {
        game();
        fguess();
        missdrawer();

    } while (!win() && !lose());

    endgame();

    return 0;
}