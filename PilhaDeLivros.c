//PILHA DE LIVROS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

void limpaTela();
void pause();
void push(int quant);
void imprimir();



typedef struct apelido_no{
	char *nome, *autor;
	int ano;
	struct apelido_no *proximo;	
}no;

no *topo;
int main(){
	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	int i, op;
	do{
		i=1;
		limpaTela();
		printf("========PILHA DE LIVROS========\n\n");
		printf("%d - Empilhar Livro\n",i++);
		printf("%d - Empilhar X Livros aleatórios\n",i++);
		printf("%d - Desempilhar um Livro\n",i++);
		printf("%d - Desempilhar X Livros\n",i++);
		printf("%d - Desempilhar Todos Livros\n",i++);
		printf("%d - Dividir Pilha\n",i++);
		printf("%d - Imprimir Pilhas\n\n",i++);
		printf("%d - Sair\n\n",i);
		printf("Opção: ");
		scanf("%d",&op);
		fflush(stdin);
		limpaTela();
		switch(op){
			case 1:
				push(1);
			break;
			case 2:
				push(-1);
			break;
			case 3:
				//pop();
			break;
			case 4:
				//pop();
			break;
			case 5:
				//push();
			break;
			case 6:
				//push();
			break;
			case 7:
				imprimir();
			break;
		}
	}while(op!=i);
	return 0;
}
//============================
void limpaTela(){
	system("cls");
}
//============================
void pause(){
	system("pause");
}
//============================
void push(int quant){
	char tempNome[200], tempAutor[200];
	int tempAno;
	if(quant==1){
		printf("Nome do Livro: ");
		fgets(tempNome,sizeof(tempNome),stdin);
		tempNome[strcspn(tempNome,"\n")] = '\0';
		fflush(stdin);
		printf("Nome do Autor: ");
		fgets(tempAutor,sizeof(tempAutor),stdin);
		tempAutor[strcspn(tempAutor,"\n")] = '\0';
		fflush(stdin);
		printf("Ano do Livro: ");
		scanf("%d",&tempAno);
		fflush(stdin);
		no *novo=malloc(sizeof(no));
		novo->nome = malloc(strlen(tempNome) + 1);
		novo->autor = malloc(strlen(tempNome) + 1);
		strcpy(novo->nome,tempNome);
		strcpy(novo->autor,tempAutor);
		novo->ano=tempAno;
		novo->proximo=topo;
		topo=novo;
		printf("Livro Empilhado!\n");
		pause();
	}else{
		if(quant==-1){
			do{
				printf("Quantos Livros Aleatórios Irá Empilhar?\nR: ");
				scanf("%d",&quant);
				fflush(stdin);
				limpaTela();
			}while(quant<1);	
		}
		int i,j;
		for(i=0;i<quant;i++){
			for(j=0;j<10;j++){
				tempNome[j]=rand()%36+65;
				tempAutor[j]=rand()%36+65;
			}
			tempNome[j] = '\0';
			tempAutor[j] = '\0';
			tempAno=rand()%127+1900;
			no *novo=malloc(sizeof(no));
			novo->nome = malloc(strlen(tempNome) + 1);
			novo->autor = malloc(strlen(tempNome) + 1);
			strcpy(novo->nome,tempNome);
			strcpy(novo->autor,tempAutor);
			novo->ano=tempAno;
			novo->proximo=topo;
			topo=novo;	
		}
		printf("Livros Empilhados!\n");
		pause();
	}
}
//============================
void imprimir(){
	int cont=1;
	no *temp;
	temp=topo;
	printf("Pilha 1\n\n");
	while(temp!=NULL){
		printf("%dº Livro:\n",cont++);
		printf("Nome: %s\n", temp->nome);
		printf("Autor: %s\n", temp->autor);
		printf("Ano: %d\n\n", temp->ano);	
		temp=temp->proximo;
	}
	pause();
}















