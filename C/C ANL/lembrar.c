#include <stdio.h>


void teste(int *num){
 *num = *num + 1;

}

int main(){
    int numero=5;

    printf("%i\n",numero);
    
    teste(&numero);

    printf("%i\n",numero);

    return 0;
}