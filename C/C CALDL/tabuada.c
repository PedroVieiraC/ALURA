#include <stdio.h>

int main(){

    printf("Digite um número\n");
    int nd;
    scanf("%i",&nd);

    for(int i=1;i<11;i++){
        printf("%ix%i=%i\n",nd,i,nd*i);
    }

    return 0;
}