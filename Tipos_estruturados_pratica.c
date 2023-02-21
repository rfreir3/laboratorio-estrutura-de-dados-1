/*O programa a seguir apresenta alguns erros, os quais não consegui resolver. Acredito que algumas coisas estão corretas, por isso decidi colocar aqui*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX_VAGAS 4
#define MAX_TURMAS 2

typedef struct aluno{
	char nome[80];
	int mat;
	float notas[3];
	float media;
}Aluno;

typedef struct turma{
	char id;
	int vagas;
	Aluno* alunos[MAX_VAGAS];
}Turma;

Turma* cria_turma(char id){ //Função para criar turmas:
    int i;
    Turma* turmas = (Turma*) malloc(sizeof(Turma));
    if (turmas == NULL) {
        printf("Não foi possivel alocar memória para a turma.\n");
        exit(1);
    }
  //====================================================================
  //verifica se a alocação do vetor "turmas" foi bem sucedido;
	
	printf("Digite um id para a turma: ");
	scanf("%s", &turmas->id);
    turmas->vagas = 0; //<-inicializa a variável "vagas" da struct "Turma" com 0;
    for (i = 0; i < MAX_VAGAS; i++) {
        turmas->alunos[i] = NULL; //<-preenche as posições "alunos" dentro do vetor "turmas" com NULL;
    }
    printf("Turma %c criada com sucesso!\n", turmas->id);
    return turmas;
}

void matricula_aluno(Turma* turmas, int mat, char* nome){ //função que matricula aluno numa turma;
    int i;
	if (turmas->vagas < MAX_VAGAS){
		Aluno* alunos = (Aluno*) malloc(sizeof(Aluno));
		if (alunos == NULL) {
		    printf("Erro: não foi possível alocar memória para o aluno.\n");
		    exit(1);
		}
		//========================================================================
		//verifica se a alocação do vetor "turmas" foi bem sucedido;
    	
		alunos->mat = mat;
		strcpy(alunos->nome, nome);
		alunos->notas[0] = 0;
		alunos->notas[1] = 0;
		alunos->notas[2] = 0;
	  	//===============================  
	  	//insere os dados do aluno indicada pelo usuário nas variáveis da struct "Aluno";

		turmas->alunos[turmas->vagas] = alunos; 
		//=====================================
		//armazena os dados do aluno na posição "turmas->vagas" dentro do vetor de alunos (que está dentro de "turmas");

		turmas->vagas++; //indica que uma vaga da turma foi preenchida;
		printf("Aluno %s matriculado na turma %c com sucesso!\n", alunos->nome, turmas->id);
		}
	else{
    	printf("Erro: não há vagas disponíveis na turma %c.\n", turmas->id);
    }
}

Turma* procura_turma(Turma** turmas, int n, char id){ //função que busca uma turma indicada pelo usuário;
    int i;
    for (i = 0; i < n; i++) {
        if (turmas[i]->id == id) {
            printf("Turma encontrada!\n");
            return turmas[i];
        }
    }
    //======================================
    //verifica se a turma foi encontrada, retornando-a;
    
	printf("Turma não encontrada.\n");
    return NULL;
}

void lanca_notas(Turma* turmas){ //função que armazena as notas de um aluno e armazena nas variaveis do tipo "Aluno";
	int i;
	for(i=0;i<MAX_VAGAS;i++){
		printf("Digite as três notas do %d aluno: ", i+1);
		scanf("%f", &turmas->alunos[i]->notas[0]);
		scanf("%f", &turmas->alunos[i]->notas[1]);
		scanf("%f", &turmas->alunos[i]->notas[2]);
		//=========================================
		//lê as notas, armazenando-as no vetor "notas" do tipo "Aluno";
		
		turmas->alunos[i]->media=(turmas->alunos[i]->notas[0] + turmas->alunos[i]->notas[1] + turmas->alunos[i]->notas[2])/3; 
		//===================================================================================================================
		//calcula média, armazenando-a na variável "media" do tipo "Aluno";
		printf("Média: %f", turmas->alunos[i]->media); //imprime a média;
		
	}
}

void imprime_aluno(Turma* turmas){ //função que imprime todas as informações sobre os alunos de uma determinada turma;
	int i, j;
	char id;
	printf("Digite o id da turma que deseja consultar: ");
	scanf("%s", &id);
	for(i=0;i<MAX_VAGAS;i++){
		if(turmas->id==id){ //compara se o id acessado no vetor "turmas" corresponde ao id digitado pelo usuário;
			printf("Listando alunos...\n");
			printf("Aluno %d:\n", i++);
			for(j=0;j<81;j++){
				printf("Nome: ", turmas->alunos[i]->nome);
			}
			//================================================
			//imprime o nome do aluno matriculado;

			printf("Número de matrícula: ", turmas->alunos[i]->mat);
			printf("Média: ", turmas->alunos[i]->media);
			//======================================================
			//imprime as outras informações dos alunos;
		}
	}
}

void imprime_turma(Turma** turmas){ //função que imprime as informações de determinada uma turma;
	int i;
	char id;
	Aluno** alunos;
	printf("Digite o id da turma que deseja verificar: ");
	scanf("%s", &id);
	for(i=0;i<MAX_TURMAS;i++){
		if(turmas[i]->id==id){ //compara se o id acessado no vetor "turmas" corresponde ao id digitado pelo usuário;
			printf("Turma %c:\n", turmas[i]->id);
			printf("Vagas: %d\n", turmas[i]->vagas);
			//======================================
			//imprimindo informações da turma;
		}
	}
}
	
int main(){
	setlocale(LC_ALL, "Portuguese");
	Turma* turmas;
	char id, cont;
	char nome[80];
	int mat, op;
	printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
	printf("Este programa gerencia as turmas ofertadas,\nfornecendo as funcionalidades de matricula, lançamento de notas e listagem de alunos.\nAutor: Rafael Freire\t\tVersao: 1.0\n");
	do{
		printf("\nMENU:\n1 – Criar turma\n2 – Matricular aluno\n3 – Consultar turma\n4 – Lançar notas\n5 – Listar alunos\n6 – Listar turmas\n7 - Sair\n");
		printf("Digite sua opcao: ");
		scanf("%d", &op);
		switch(op){ //laço de repetição para que o programa continue sendo executado enquanto o usuário não digitar um caractere diferente de "S" ou "s";
			case 1:
				cria_turma(id);
				break;
			case 2:
				printf("Digite o nome do aluno: ");
				scanf("%s", &nome);
				printf("Digite o número de matrícula do aluno: ");
				scanf("%d", &mat);
				matricula_aluno(turmas, mat, nome);
				break;
			case 3:
				printf("Digite o id da turma que deseja buscar: ");
				scanf("%s", &id);
				procura_turma(&turmas, MAX_TURMAS, id);
				break;
			case 4:
				lanca_notas(turmas);
				break;
			case 5:
				imprime_aluno(turmas);
				break;
			case 6:
				imprime_turma(&turmas);
				break;
			case 7:
				printf("Obrigado por usar esse programa!");
				exit(1);
			default:
				printf("Opção invalida!");
				break;
		}
		printf("Deseja continuar? [S/N]");  
		scanf(" %c", &cont);	
	}while(cont=='S'||cont=='s');  //laço de repetição para que o programa continue sendo executado enquanto o usuário não digitar um caractere diferente de "S" ou "s";
	return(0);
}
