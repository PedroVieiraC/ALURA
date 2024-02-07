#include <stdio.h>

int main(){

    char a = 'a';
    char teste[5] = {'v','i','n','t','e'};

    int dez = 10;
    int ara[3] = {24,23,40};

    printf("%c\n\%s\n",a,teste);

    printf("\n%i\n",dez);
    for(int i=0;i<sizeof(ara)/sizeof(int);i++){
        printf("%i\n",ara[i]);
    }

    return 0;
}