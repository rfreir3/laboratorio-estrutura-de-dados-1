#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct dados_funcionario{
	char nome[50], cargo[50];
	float salario;
	int identificador;	
}Funcionario;

void preenche(Funcionario * p1, int tamanho){
	int i;
	for(i=0;i<tamanho;i++){
		printf("Digite o nome do funcionário: ");
		scanf(" %[^\n]s", p1->nome);
		printf("Digite o salário do funcionário: ");
		scanf("%f", p1->salario);
		printf("Digite o identificador do funcionário: ");
		scanf("%d", p1->identificador);
		printf("Digite o cargo do funcionário: ");
		scanf(" %[^\n]s", p1->cargo);
	}
}

void exibe(Funcionario * p2, int tamanho){
	int i;
	for(i=0;i<tamanho;i++){
		printf("%s", p2->nome[i]);
		printf("%f", p2->salario);
		printf("%d", p2->identificador);
		printf("%s", p2->cargo[i]);
	}
}

int main(){
	int qntd_funcionarios;
	setlocale(LC_ALL, "Portuguese");
	printf("Digite a quantidade de funcionários da empresa: ");
	scanf("%d", &qntd_funcionarios);
	Funcionario * vetor_de_funcionarios=(Funcionario*)malloc(qntd_funcionarios*sizeof(Funcionario));
	preenche(vetor_de_funcionarios, qntd_funcionarios);
	exibe(vetor_de_funcionarios, qntd_funcionarios);
	return(0);
}
