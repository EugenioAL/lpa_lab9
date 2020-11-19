  
#ifndef _myLib 
#define _myLib

struct prefixo
{
    unsigned char mpg1;
    unsigned char mpg2;
    unsigned char mpg3;
};

int print_mpg(char * arq,int buff_size, int vetor[],int tam);

int valor_tam_vet(char *arq);

void sel_ponteiros(char *arq, int vetor[]);
#endif