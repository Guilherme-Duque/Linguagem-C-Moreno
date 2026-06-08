/*
Turma: ESOFT3S-N-C

FAVOR NAO ALTERAR

Construir um programa em linguagem C que implemente uma lista simplesmente encadeada.
O programa deverá possuir as seguintes opções no menu:
- inserir no inicio
- inserir no fim
- inserir no meio
- inserir 10 elementos sorteados //sorteio inclusive se é inicio, meio ou fim
- apresentar lista
- remover elemento
- sair

Envio: https://forms.gle/m93Tp9QXDrKkCv4T6
Materiais: Materiais: https://drive.google.com/drive/folders/1rN5JbC5E1Vu1mchc57z_8DBko0bLP4MU
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct apelido{
	int valor;
	struct apelido *proximo;
} no;
void limpaTela();
void pause();
void inserirInicio(int num);
int perguntaNum(int op);
void inserirFim(int num);
void imprimir();
void remover(int num);
void inserirMeio (int ant, int num);
void inserir10();

no *lista;

int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	int op;
	do{
		limpaTela();
		printf("====LISTA SIMPLESMENTE ENCADEADA====\n\n");
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
				inserirInicio(perguntaNum(1));
				break;
			case 2:
				inserirMeio(perguntaNum(3), perguntaNum(1));
				break;
			case 3:
				inserirFim(perguntaNum(1));
				break;
			case 4:
				inserir10();
				break;
			case 5:
				imprimir();
				break;
			case 6:
				remover(perguntaNum(2));
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

void inserirInicio(int num){
	no *novo = malloc(sizeof(no));
	
	if(novo){
		novo->valor = num;
		novo->proximo = lista;
		lista = novo;
	} else {
		printf("Erro ao alocar memória");
		pause();
	}
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

void inserirFim(int num){
	no *aux, *novo = malloc(sizeof(no));
	if(novo){
		novo->valor = num;
		novo->proximo = NULL;
		if(lista){
			aux = lista;
			while(aux->proximo) aux = aux->proximo;
			aux->proximo = novo;		
		} else {
			lista = novo;	
		}
	} else{
		printf("Erro ao alocar memória");
		pause();
	}
}

void imprimir(){
	no *temp = lista;
	int i = 1;
	printf("VALORES DA LISTA\n\n");
	while(temp){
		printf("Posição %d: %d\n", i++, temp->valor);
		temp = temp->proximo;
	}	
	pause();
}

void remover(int num) {
	//Da pra melhorar, se houver repetição, remover todos, escolher qual remover
	if (lista == NULL) {
		printf("Lista vazia. Nada a remover.\n");
		return;
		}
	no *atual = lista;
	no *anterior = NULL;
	while (atual != NULL && atual->valor != num) {
	anterior = atual;
	atual = atual->proximo;}
	if (atual == NULL) { 
		printf("Valor não encontrado na lista. Nada a remover.\n");
		return;
		}
	if (anterior == NULL) {
		lista = atual->proximo;
		free (atual);
	} else {
		anterior->proximo = atual->proximo;
		free (atual);
		}
	printf("Valor %d removido da lista.\n", num);
	pause();
}

void inserirMeio (int ant, int num){
	no *aux, *novo=malloc(sizeof(no));
	if (novo) {
		novo->valor=num;
		if (lista==NULL) {
		novo->proximo=NULL;
		lista=novo;
		}else{
		aux=lista;
		while(aux->valor != ant && aux->proximo)
		aux=aux->proximo;
		novo->proximo=aux->proximo;
		aux->proximo=novo;
		}	
	} else{
		printf("Erro ao alocar memoria \n");
		pause();
	}
}

void inserir10(){
	int escolha, num, i, ant;
	for(i = 0; i < 10; i++){
		escolha = rand() % 3 + 1;
		num = rand() % 100;
		switch (escolha){
			case 1:
				inserirInicio(num);
			break;
			case 2:
				//Da pra melhorar, considerar apenas os números já inseridos
				ant = rand() % 100;
				inserirMeio(ant, num);
			break;
			case 3:
				inserirFim(num);
			break;
		}
	}
	printf("10 Valores aleatórios inseridos\n");
	pause();
	
}





















