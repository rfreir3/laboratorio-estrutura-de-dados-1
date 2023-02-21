// Questão 1) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um
// novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
// consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o
// produto (gostou/não gostou). Escreva um programa em C que:
// a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados,
// um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta
// para a segunda pergunta.
// b) determine a porcentagem de pessoas do sexo feminino que responderam que
// gostaram do produto.
// c) determine a porcentagem de pessoas do sexo masculino que responderam que não
// gostaram do produto.


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
setlocale(LC_ALL, "Portuguese");
int n, i, contf = 0, contm = 0;

printf("Digite o número de pessoas que responderam as perguntas\n");
scanf("%d", &n); // "n" corresponde ao tamanho dos vetores;

char *sexo = (char *)malloc(n * sizeof(char));
int *op = (int *)malloc(n * sizeof(int));
//============================================
//Alocação dinamica dos vetores "sexo" e "op";

for( i = 0; i < n; i++){
   printf("Digite o sexo do entrevistado. F para Feminino e M pra masculino\n");
   scanf(" %c", &sexo[i]);
   printf("Digite 0 pra não gostou e 1 pra gostou\n");
   scanf("%d", &op[i]);
}
//===============================================================================
//preenchendo os vetores;
  
 
int j;
for( j = 0; j < n; j++){
  if ((sexo[j] == 'F') && (op[j] == 1)){
    contf++; //quando "sexo" é igual a "F" e "op" é igual a 1, a variável "contf" soma 1 ao seu conteúdo;
  }  
  else if ((sexo[j] == 'M') && (op[j] == 0)){ 
    contm++; //quando "sexo" é igual a "M" e "op" é igual a 0, a variável "contm" soma 1 ao seu conteúdo;
  }

}

  float FM, MM;
  FM = (contf*100)/n;
  MM = (contm*100)/n;
  //=================
  //calcula porcentagem;

  printf("\nA porcentagem de pessoas do sexo feminino que gostaram do produto: %.2f%%\n",FM);
  printf("\nA porcentagem de pessoas do sexo masculino que nao gostaram do produto: %.2f%%\n",MM);

  free(sexo);
  free(op);
  //=========
  //libera a memória.
  return (0);
}

/*Questão 2) Escreva um programa para corrigir provas de múltipla escolha. Cada prova tem N
questões e cada questão vale 10/N pontos. Os primeiros dados a serem lidos são o número de
questões e o gabarito da prova. Em seguida, serão lidas as respectivas respostas de um total de
10 alunos matriculados. Calcule e mostre:
a) a nota obtida para cada aluno;
b) a porcentagem de aprovação, sabendo-se que a nota mínima para ser aprovado é 6.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


float comparar(char *gabarito, char *alunos, int x){ //Função de comparação do gabarito com as respostas dos alunos;
	int i;
	float y=0;
	for(i=0;i<x;i++){
		if(alunos[i]==gabarito[i]){
			y+=10;
		}
	}
	return y;
  //===========================
  //compara o conteúdo do vetor "aluno" e "gabarito". Caso a condição seja verdadeira, a função retorna a nota da prova;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int questoes, i, j;
	float nota=0, porcentagem=0;
	
	
	printf("Quantidade de questões: ");
	scanf("%d", &questoes); //"questoes" corresponde ao tamanho do espaço dos vetores "gabarito" e "alunos";
	
	 
	char *gabarito, *alunos;
	gabarito=(char*)malloc(questoes*sizeof(char)); //alocação de vetor;
	if(gabarito==NULL){
		printf("Erro!");
		exit(1);
  //============================================
  //Caso haja erro na alocação de memória, o programa é fechado;
    
	}
	alunos=(char*)malloc(questoes*sizeof(char)); //alocação de vetor;
	if(alunos==NULL){
		printf("Erro!");
		exit(1);
  //============================================
  //Caso haja erro na alocação de memória, o programa é fechado;
    
    
	}
	
	
	for(i=0;i<questoes;i++){
		printf("\nDigite a resposta da %dª questão: ", i+1);
		scanf("%s", &gabarito[i]);
    //==================================================
    //inserindo gabarito da prova;
	}
	
	
	for(i=0;i<10;i++){
		printf("\nAgora digite as respostas do %dº aluno.", i+1);
		for(j=0;j<questoes;j++){
			printf("\n%dª resposta: ", j+1);
			scanf("\n%s", &alunos[j]);
      //==============================
      //definindo respostas do aluno;
		}
		nota=comparar(gabarito, alunos, questoes);
		printf("\nNota: %.2f", nota/questoes); 
    //====================================
    //divide a nota pela quantidade de questões para imprimir a nota real;
		
    if(nota>=6){
			porcentagem+=1;
		}
	}
  //=================
	//contando quantos alunos passaram;
	printf("\nPorcentagem de aprovação: %.1f%%", (porcentagem/10)*100); //calculando porcentagem;
	free(gabarito);
	free(alunos);
  //============
  //liberando memória.
	return(0);
}
