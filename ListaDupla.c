/*
Construir um programa em linguagem C que implemente uma lista DUPLAMENTE encadeada.
O programa deverá possuir as seguintes opções no menu:
- inserir no inicio
- inserir no fim
- inserir no meio
- apresentar a quantidade de elementos da lista (criar funcao)
- inserir 10 elementos sorteados //sorteio inclusive se é inicio, meio ou fim)
- apresentar lista
- remover elemento
- sair

entrega: https://forms.gle/v8X3ZTSVGURg7iFa9
materiais: https://drive.google.com/drive/folders/1rN5JbC5E1Vu1mchc57z_8DBko0bLP4MU7
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct apelido_no{
   int valor;
   struct apelido_no *ant;
   struct apelido_no *prox;
}no;

void limpaTela();
void pause();
void inserirInicio(int num, no **lista);
int perguntaNum(int op);
void imprimir(no *lista);
void inserirFim(int num, no **lista);


int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	
	no *lista = NULL;
	int op;
	
	do{
		limpaTela();
		printf("====LISTA DUPLAMENTE ENCADEADA====\n\n");
		printf("1 - Inserir no início\n");
		printf("2 - Inserir no meio \n");
		printf("3 - Inserir no fim\n");
		printf("4 - Inserir 10 elementos sorteados\n");
		printf("5 - Apresentar lista\n");
		printf("6 - Remover elemento\n");
		printf("7 - Sair\n");
		scanf("%d", &op);
		limpaTela();
		switch(op){
			case 1:
				inserirInicio(perguntaNum(1), &lista);
				break;
			case 2:
				//inserirMeio(perguntaNum(3), perguntaNum(1));
				break;
			case 3:
				inserirFim(perguntaNum(1), &lista);
				break;
			case 4:
				//inserir10();
				break;
			case 5:
				imprimir(lista);
				break;
			case 6:
				//remover(perguntaNum(2));
				break;
		}
		
	}while(op!=7);
}

void limpaTela(){
	system("cls");
}

void pause(){
	system("pause");
}

void inserirInicio(int num, no **lista){
	no *novo = malloc(sizeof(no));
	novo->valor = num;
	novo->ant = NULL;
	novo->prox = *lista;
	if(*lista){
		(*lista)->ant = novo;
	} 
	*lista = novo;
}


int perguntaNum(int num){
	int valor;
	switch(num){
		case 1:
			printf("Valor para inserir na lista: ");
		break;
		case 2:
			printf("Valor para remover na lista: ");	
		break;	
		case 3:
			printf("Deseja inserir após qual número? ");	
		break;	
	}
	scanf("%d", &valor);
	return valor;
}

void imprimir(no *lista){
	int i = 1;
	printf("VALORES DA LISTA\n\n");
	while(lista){
		printf("Posição %d: %d\n", i++, lista->valor);
		lista = lista->prox;
	}	
	pause();
}

void inserirFim(int num, no **lista){
	no *aux = *lista;
	no *novo = malloc(sizeof(no));
	novo->valor = num;
	while(aux->prox){
		aux = aux->prox;
	}
	aux->prox = novo;
	novo->ant = aux;
}

