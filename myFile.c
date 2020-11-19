#include <stdio.h>
#include <stdlib.h>
#include "myLib.h"

struct prefixo start_prefixo = {.mpg1 = 0x00,.mpg2 = 0x00 , .mpg3 = 0x01};

int print_mpg(char * arq,int buff_size, int vetor[],int tam){
    FILE * arq_in = fopen(arq , "rb");
    unsigned char seq,buffer[buff_size * 1000000];    
    int cont = 0,i,inicio = 0,fim = vetor[0];
    char *output;
    if(arq_in == NULL){
        return 1;
    }
    for(i = 0; i < tam; i++){ 
        fim  = vetor[i];
        if(fim - inicio >= buff_size * 1000000){
            cont++;
            sprintf(output,"leon%d.mpg",cont);
            FILE *arq_out = fopen(output,"wb+");
            rewind(arq_in);
            fseek(arq_in,inicio,SEEK_CUR);
            fread(&buffer,vetor[i-1] - inicio,1,arq_in);
            fwrite(&buffer,vetor[i-1] -inicio,1,arq_out);
            inicio = vetor[i-1];
            fclose(arq_out);
        }        
    }    
    cont++;
            sprintf(output,"leon%d.mpg",cont);
            FILE *arq_out = fopen(output,"wb+");
            rewind(arq_in);
            fseek(arq_in,inicio,SEEK_CUR);
            fread(&buffer,(fim -1)  - inicio,1,arq_in);
            fwrite(&buffer,(fim -1) - inicio,1,arq_out);
    fclose(arq_in);

}



int valor_tam_vet(char *arq){

    FILE * arq_in = fopen(arq , "rb");
    int cont = 0;
    unsigned char seq;
    if(arq_in == NULL){
        return 1;
    }
    struct prefixo tmp;
    while(!feof(arq_in) ){
        
    fread(&seq,1,1,arq_in);
    if(seq == 0xB3){
        fseek(arq_in,-4,SEEK_CUR);
        fread(&tmp,sizeof(struct prefixo),1,arq_in);
        if(tmp.mpg1 == start_prefixo.mpg1 && tmp.mpg2 == start_prefixo.mpg2 && tmp.mpg3 == start_prefixo.mpg3 ){
            cont++;
        }
        fseek(arq_in,1,SEEK_CUR);
        }
    }
    return cont;
    fclose(arq_in);
}

void sel_ponteiros(char *arq, int vetor[]){
    FILE * arq_in = fopen(arq , "rb");
    int cont = 0;
    unsigned char seq;
    if(arq_in == NULL){
        printf("File nao encontrado\n");
    }
    struct prefixo tmp;
    while(!feof(arq_in) ){
        
    fread(&seq,1,1,arq_in);
    if(seq == 0xB3){
        fseek(arq_in,-4,SEEK_CUR);
        fread(&tmp,sizeof(struct prefixo),1,arq_in);
        if(tmp.mpg1 == start_prefixo.mpg1 && tmp.mpg2 == start_prefixo.mpg2 && tmp.mpg3 == start_prefixo.mpg3 ){
            vetor[cont] = ftell(arq_in) -4;
            cont++;
        }
        fseek(arq_in,1,SEEK_CUR);
        }
    }
    fclose(arq_in);
}