#include <stdio.h>

#include <stdio.h>

int main()
{
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");
    printf("Tente adivinhar o número!\n");

    int ns = 42, chute;
    scanf("%i", &chute);

    while (chute != ns)
    {
        if (chute <= ns)
        {
            printf("O chute foi menor que o número secreto\nTente novamente: ");
            scanf("%i", &chute);
        }
        else
        {
            printf("O chute foi maior que o número secreto\nTente novamente: ");
            scanf("%i", &chute);
        }
    }
    if (chute == ns)
    {
        printf("Você acertou!\n");
    }
}