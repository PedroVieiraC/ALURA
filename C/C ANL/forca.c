#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

char secretword[20];
char guess_storage[26];
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
    printf("Choose the difficulty. \n(1)Easy (2)Medium (3)Hard\n");
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
    sprintf(secretword, "teste");
}

void missdrawer()
{
    if ((misstryes <= 0 && difficulty == 1) || (misstryes <= 2 && difficulty == 2) || (misstryes <= 4 && difficulty == 3))
    {
        printf("\nprintou porque misstryes %i e difficulty %i\n",misstryes, difficulty);
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
                printf("\nprintou porque misstryes %i e difficulty %i\n",misstryes, difficulty);
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
                printf("\nprintou porque misstryes %i e difficulty %i\n",misstryes, difficulty);
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
                printf("\nprintou porque misstryes %i e difficulty %i\n",misstryes, difficulty);
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
                printf("\nprintou porque misstryes %i e difficulty %i\n",misstryes, difficulty);
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
    printf("misses %i\n", misstryes);
}
// function that manage the game work
void game()
{
    printf("You already gave %i guesses\n", tryes);

    for (int i = 0; i < strlen(secretword); i++)
    {
        // if found, prints the letter, else print the underscore
        if (alrguessed(secretword[i]))
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

    misscounter();

    if (miss())
        tryes++;
}

// function to verify if the guess are in the secret word
int alrguessed(char letter)
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
int misscounter()
{
    int exist = 0;

    for (int j = 0; j < strlen(secretword); j++)
    {
        if (guess_storage[tryes] == secretword[j])
        {
            exist = 1;
        }
    }
    if (!exist)
    {
        printf("se nao existe sobe 1 misstryes %i\n", misstryes);
        misstryes++;
    }
    printf("\n!exist %i e exist %i\n", !exist, exist);

    return exist;
}

// function to see if all the letters of sw was already guessed
int win()
{
    for (int i = 0; i < strlen(secretword); i++)
    {
        if (!alrguessed(secretword[i]))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    // declaração palavra secreta

    int hit = 0;

    start();

    secretwordchoose(secretword);

    do
    {
        game();
        fguess();
        missdrawer();

    } while (!win() && !lose());

    if (win())
    {
        missdrawer();
        printf("YOU WIN!!!\n");
        printf("secret word was %s\n", secretword);
    }
    else
    {
        missdrawer();
        printf("YOU LOSE, TRY AGAIN!\n");
    }

    return 0;
}