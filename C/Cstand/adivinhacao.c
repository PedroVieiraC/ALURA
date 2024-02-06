#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define limite 5
#define pontos 1000

int main()
{
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");

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

    int nivel, limite;
    printf("Qual o nível de dificuldade?\nDigite (1)Fácil (2)Médio (3)Difícil\n");
    scanf("%i",&nivel);

    switch(nivel){
        case 1: limite = 20;
        break;
        case 2: limite = 10;
        break;
        case 3: limite = 6;
        break;
    }
    
    printf("Tente adivinhar o número!\n");

    acerto = (chute == ns);

    //limitadores são 3 tentativas(contador < limite && ) ou ter acertado
    while (contador < limite && !acerto)
    {
        printf("tentativas %i \n",limite-contador);
        
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
            break;
        }
        //se nao acertou, informa se é maior ou menor
        else
        {
            //aumenta o contador de tentativas
            contador++;
            
            if (chute < ns)
            {
                printf("o chute foi menor que o número!\n");
            }
            else
            {
                printf("o chute foi maior que o número!\n");
            }            
            
            if(contador< limite) printf("tente novamente:\n");
        }
        
        //calcula o módulo da diferença do chute e do número
        diferenca += abs(chute - ns)/2.0;

        
    }

    printf("-----------------\nFIM DE JOGO\n");

    //informa se atingiu o limite de tentativas
    if (contador == limite && !acerto)
        printf("limite de tentativas atingido\n");

    if (acerto)
        printf("Você ganhou!!!\n");
    //calcula o total de pontos
    totalpontos = pontos - diferenca;

    printf("pontos = %.1f\n", totalpontos);

    //confere se o término foi por acerto ou por tentativas
    
    return 0;
}
