#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"


int main(int argc, char *argv[]){
    unsigned char a,*tam = argv[2];
    //printf("%s \n",tam);
    unsigned int size = atoi(tam);
   // printf("%u \n",size);

    int n = valor_tam_vet(argv[1]);
   // printf("--> %d \n",n);
    int vetor[n];
    
    sel_ponteiros(argv[1],vetor);
    //printf("%d--\n",vetor[1]);

    
    print_mpg(argv[1],size,vetor,n);
}