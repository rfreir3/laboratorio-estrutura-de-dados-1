/*Q1-Aloque dinamicamente um vetor de inteiros de tamanho 10 e preencha cada elemento do vetor com
o seu respectivo ´ındice (vetor[i] = i). Em seguida, imprima o vetor.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vet=(int*)malloc(10*sizeof(int));//Reservando espaço na memória para o vetor;
    
    for(int i=0;i<10;i++){
        vet[i]=i;
        printf("vet[%d]=%d\n", vet[i], vet[i]);
    }
    //==========================================
    //preenchendo vetor com seu índice;
    return(0);
}
