/*Questão 1) A Nlogônia é um país tropical, com muitas belezas naturais internacionalmente
famosas; dentre elas, encontram-se as belas praias que compõem o arquipélago do país, que
todo verão recebem milhões de turistas estrangeiros.
O Ministério do Turismo da Nlogônia está preparando o país para a chegada dos turistas, mas,
para fazer seu planejamento, precisa saber a extensão da costa nlogônica. Para isso, ele gerou
um mapa que divide o território nacional em vários quadrados, que podem ser ocupados por
água ou por terra; considera-se que um quadrado é parte da costa nlogônica se ele é um
quadrado ocupado por terra que tem um lado em comum com um quadrado ocupado por
água.
Como a Nlogônia é um país muito grande, o ministro do turismo pediu que você escrevesse um
programa que, dado o mapa da Nlogônia, determina a extensão da costa nlogônica.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j, N=0, M=0;;
	printf("Digite um total de colunas: ");
	scanf("%d", &M);
	printf("Digite um total de linhas: ");
	scanf("%d", &N);
	char **costa=(char**)malloc(M*sizeof(char*));
	for(i=0;i<M;i++){
		costa[i]=(char*)malloc(N*sizeof(char));
	}
	printf("Digite o mapa do local utilizando pontos (.) e hashtags (#).\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%c\t", &costa[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<M;i++){
		free(costa[i]);	
	}
	free(costa);
	return(0);
}
