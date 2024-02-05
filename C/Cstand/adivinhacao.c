#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define limite 3
//#define ns 42
#define pontos 1000

int main()
{
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("Tente adivinhar o número!\n");

    //dá um valor aleatório ao número
    int ns;
    srand(time(0));
    ns = rand()%100;

    //chute = tentativa, contador = contador de tentativas
    int chute, acerto, contador;
    contador = 0;

    //total de pontos são os pontos finais e diferença é abs chute - numero secreto
    double totalpontos;
    double diferenca;

    acerto = (chute == ns);

    //limitadores são 3 tentativas(contador < limite && ) ou ter acertado
    while (!acerto)
    {

        scanf("%i", &chute);
        acerto = (ns == chute);

        //conferir se o número digitado é negativo
        if (chute < 0)
        {
            while (chute < 0)
            {
                printf("não é permitido números negativos. Redigite: ");
                scanf("%i", &chute);
            }
        }

        //confere se acertou
        if (acerto)
        {
            printf("Você ganhou!\n");
            // return 0;
        }
        //se nao acertou, informa se é maior ou menor
        else
        {
            if (chute < ns)
            {
                printf("o chute foi menor que o número!\n");
            }
            else
            {
                printf("o chute foi maior que o número!\n");
            }
            printf("tente novamente:\n");
            
        }
        
        //calcula o módulo da diferença do chute e do número
        diferenca += abs(chute - ns)/2.0;

        //aumenta o contador de tentativas
        contador++;
        
        //printf("tentativas %i \n",limite-contador);
    }

    //informa se atingiu o limite de tentativas
    //if (contador == limite && !acerto)
    //    printf("limite de tentativas atingido\n");

    //calcula o total de pontos
    totalpontos = pontos - diferenca;

    printf("pontos = %.1f\n", totalpontos);

    //confere se o término foi por acerto ou por tentativas
    
    return 0;
}
