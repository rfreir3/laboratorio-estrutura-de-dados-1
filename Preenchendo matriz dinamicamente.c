/*Q2-Aloque dinamicamente uma matriz de inteiros 3x3 e preencha cada elemento da matriz com o seu
respectivo ´ındice (matriz[i][j] = i*3 + j). Em seguida, imprima a matriz.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int linha=3, coluna=3;
    int**M=(int**)malloc(linha*sizeof(int*));//Alocando vetor que guarda os ponteiros de outros vetores (que corresponde as linhas da matriz);
    
    for(int linhas=0;linhas<linha;linhas++){
        M[linha]=(int*)malloc(coluna*sizeof(int));
    }
    //============================================
    //alocando vetores que são guardados dentro dos vetores que correspondem as linhas da matriz(os quais correspondem as colunas da matriz);
    
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            M[i][j]=i*3+j;
            printf("M[%d][%d]=%d\n", i, j, M[i][j]);
        }
    }
    //==============================================
    //armazenando valores dentro da matriz;
    
    for(int i=0;i<linha;i++){
            free(M[i]);
    }
    //=======================
    //liberando espaços da memória das colunas dentro das linhas;
    
    free(M);
    //======
    //liberando linhas;
    
    return(0);
}
