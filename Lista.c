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

typedef struct apelido{
	int valor;
	struct apelido *proximo;
} no;
void limpaTela();
void pause();
void inserirInicio(int num);
int perguntaNum(int op);
void inserirFim(int num);
void remover(int num);

no *lista;

int main(){
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
		switch(op){
			case 1:
				inserirInicio(perguntaNum(1));
				break;
			case 2:
				//inserirMeio(x);
				break;
			case 3:
				inserirFim(perguntaNum(1));
				break;
			case 4:
				//inserir10();
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

void remover(int num){
	no *anterior, *atual = lista;
	while(atual && atual->valor != num){
		
	}
}






















