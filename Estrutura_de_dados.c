/*1. Crie um tipo estruturado para armazenar dados de um funcion´ario. Uma estrutura deste tipo possui
os seguintes campos: nome, sal´ario, identificador e cargo.
a) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Funcionario
e preencha seus campos com valores fornecidos pelo usu´ario via teclado.
b) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Funcionario
e imprima os valores dos seus campos.
c) Implemente uma fun¸c˜ao para realizar uma altera¸c˜ao no sal´ario de uma estrutura do tipo Funcionario.
d) Escreva uma fun¸c˜ao que receba como parˆametro um vetor de estruturas do tipo Funcionario e
imprima o cargo e sal´ario do Funcionario com maior sal´ario e o cargo e sal´ario do funcion´ario
com o menor sal´ario.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct funcionario{
	char nome[50];
	float salario;
	int identificador;
	char cargo[50];
}Funcionario;


void preencher(Funcionario *preenche, int qtd){  //função que preenche variáveis dentro de uma struct por meio do vetor "preenche" do tipo "Funcionario";
	for(int i = 0; i < qtd; i++){
	printf("Informe o nome do funcionario: ");
	scanf(" %[^\n]s", preenche[i].nome);
	printf("Informe o salario: ");
	scanf("%f", &preenche[i].salario);
	printf("Informe o identificador do funcionario: ");
	scanf("%d", &preenche[i].identificador);
	printf("Informe o cargo: ");
	scanf(" %[^\n]s", preenche[i].cargo);
	printf("Nome do funcionario: %s.\n Salario: %.1f.\n Identificador: %d.\n Cargo: %s\n", preenche[i].nome, preenche[i].salario, preenche[i].identificador, preenche[i].cargo);
	
}


float altera (Funcionario * altera, int indice){  //função que altera salário do funcionário;
	altera[indice].salario += 1000;
}


void maior_menor(Funcionario * mem, int qtd){  //função que compara os salários dos funcionários e imprime o maior e menor com os respectivos nomes;
 float	menor = 0, maior = 0;
 int indice_maior, indice_menor;
	for(int i = 0; i < qtd; i++){
		if(i == 0){
			menor = mem[i].salario;
		}
		else if(mem[i].salario > maior){
			maior = mem[i].salario;
			indice_maior = i; //indice usado para acessar o nome do funcionário com maior salário;
		} 
		else if(mem[i].salario < menor){
			menor = mem[i].salario;
			indice_menor = i; //indice usado para acessar o nome do funcionário com maior salário;
		} 
	}
	printf("O funcionario com maior salario e %s, com salario de %.1f", mem[indice_maior].nome, mem[indice_maior].salario);
	printf("O funcionario com menor salario e %s, com salario de %.1f", mem[indice_menor].nome, mem[indice_menor].salario);
}

int main (){
	int quantidade, index;
	printf("Informe a quantidade de funcionarios: ");
	scanf ("%i", &quantidade);

	Funcionario * empresa = (Funcionario*) malloc (quantidade*sizeof(Funcionario) );
	if(empresa == NULL){
		exit (1);
	}
	
	preencher(empresa, quantidade);
	altera(empresa, 0);
	maior_menor(empresa, quantidade);
	
	
	return 0;
}

/*2. Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui os
seguintes campos: nome da pessoa, numero do documento e idade.
a) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Pessoa e
preencha seus campos com valores fornecidos pelo usu´ario via teclado.
b) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Pessoa e
imprima os valores dos seus campos.
c) Implemente uma fun¸c˜ao para realizar uma atualiza¸c˜ao da idade de uma estrutura do tipo Pessoa.
d) Escreva uma fun¸c˜ao que receba como parˆametro um vetor de estruturas do tipo Pessoa e imprima
o nome da Pessoa mais velha e mais nova.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa
{
    char nome[100];
    int numerododoc;
    int idade;

} Pessoa;
	
//função que preenche as variáveis dentro da struct;
void preenche(Pessoa *i){
int cont;
	for (cont = 0; cont < 4; cont++){
	printf("\n");
	printf("\nDados da pessoa (%d)\n\n", cont + 1);
	printf("Digite o nome: ");
	scanf(" %[^\n]", i[cont].nome);
	printf("Digite o numero do documento: ");
	scanf("%d", &i[cont].numerododoc);
	printf("Digite a idade: ");
	scanf("%d", &i[cont].idade);
    }
}

//função que imprime o conteúdo das variáveis dentro da struct;
void imprimir(Pessoa *i){
	int cont;
	for (cont = 0; cont < 4; cont++){
        printf("\n");
        printf("\nDados da pessoa (%d)\n\n", cont + 1);
        printf("nome do funcionario: %s\n", i[cont].nome);
        printf("Numero do documento: %d\n", i[cont].numerododoc);
        printf("Idade da pessoa: %d\n", i[cont].idade);
	}
}

//função que altera a idade(conteúdo de uma variável dentro da struct), caso o usuário deseje;
void alteraidade(Pessoa *i, int valor){
    int cont;
    for (cont = 0; cont < 4; cont++){
        if (valor == i[cont].numerododoc){
        	printf("Atualize a idade da pessoa: ");
        	scanf("%d", &i[cont].idade);
    }
}

//função que compara as idades e imprime a maior e a menor com os respectivos nomes;
void maioremenor(Pessoa *i){
    int menor = i[0].idade;
    int maior = i[0].idade;
    char nomemaior[100];
    char nomemenor[100];
    strcpy(nomemaior, i[0].nome);
    strcpy(nomemenor, i[0].nome);
    for (int cont = 1; cont < 4; cont++){
        if (i[cont].idade > maior){
	//=========================
	//compara o conteúdo da variável "maior" com o conteúdo da variável "idade" dentro do vetor "i" do tipo "Pessoa";
	
        //se a condição for verdadeira:
		strcpy(nomemaior, i[cont].nome); //copia a string dentro de "i[cont].nome" para a variável "nomemaior";
        	maior = i[cont].idade; //variável "maior" recebe o conteúdo de "i[cont].idade";
        }
        if (i[cont].idade < menor){
	//=========================
	//compara o conteúdo da variável "menor" com o conteúdo da variável "idade" dentro do vetor "i" do tipo "Pessoa";
	
	//se a condição for verdadeira:
        	strcpy(nomemenor, i[cont].nome); //copia a string dentro de "i[cont].nome" para a variável "nomemenor";
        	menor = i[cont].idade; //variável "menor" recebe o conteúdo de "i[cont].idade";
        }
    }

    printf("Pessoa mais velha encontrada idade: %d nome: %s\n", maior, nomemaior); //imprime maior idade com seu respectivo nome;
    printf("Pessoa mais nova encontrada idade: %d nome: %s\n", menor, nomemenor); //imprime menor idade com seu respectivo nome;
}

int main(void){
	Pessoa *n1 = (Pessoa *)malloc(4 * sizeof(Pessoa)); //alocando dinamicamente o vetor "n1" do tipo "Pessoa";
	int n2;
	int valor;
	preenche(n1);
	imprimir(n1);
	printf("\n");
	printf("Alterar idade de alguma pessoa? (1) sim ou (2) nao\n");
	scanf("%d", &n2);
	if (n2 == 1){
		printf("Digite o numero do documento da pessoa em questao: ");
		scanf("%d", &valor);
		alteraidade(n1, valor);
	}
	return (0);
}
