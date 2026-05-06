#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	char nome [50];
	float nota1;
	float nota2;
	float sub;
	char final[20];
}dados;

typedef struct apelido{
	dados da;
	struct apelido *proximo;
}no;
	
no *topo=NULL;

dados entrada_dados();
void push(dados newD);
void pop();
void imprimir();

//-------------------------------------------

int main(){
	setlocale(LC_ALL,"Portuguese");
	int opcao;

	do {
		system("cls");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Imprimir\n");
		printf("4 - Inverter pilha\n");
		printf("5 - Sair\n");
		printf("OPÇÃO: "); 
		scanf("%d",&opcao);
		switch(opcao) {
			case 1:
				push(entrada_dados());
				break;
			case 2:
				pop();
				break;
			case 3:
				imprimir();
				break;
			case 4:
				//inverter();
				break;
		}
	}while(opcao !=5);
}

//-------------------------------------------

dados entrada_dados(){
	dados dat;
	float maior;
	
	fflush(stdin);
	printf("\n");
	printf("   Nome: "); fgets(dat.nome, sizeof(dat.nome), stdin); dat.nome[strcspn(dat.nome, "\n")] = '\0';
	printf("1ª Nota: "); scanf("%f", &dat.nota1);
	printf("2ª Nota: "); scanf("%f", &dat.nota2);
	printf("    Sub: "); scanf("%f", &dat.sub);	

	
	if(dat.nota1 > dat.nota2){
		maior = dat.nota1;
	}else{
		maior = dat.nota2;
	}
	
	if(dat.nota1 + dat.nota2 >= 12){
		strcpy(dat.final, "APROVADO");
	} else {
		if(dat.sub + maior < 12){
		
		strcpy(dat.final, "REPROVADO");
		}
	}
	return dat;
	

}

//-------------------------------------------

void push(dados newD){
	no *novo = malloc(sizeof(no));
	//verificar memória
	novo->da = newD;
	novo->proximo = topo;
	topo = novo;
}

//-------------------------------------------

void pop(){
	no *temp = topo;
	topo = topo->proximo;
	free(temp);
}

//-------------------------------------------

void imprimir(){
	no *temp = topo;
	while(temp != NULL){
		printf("  \nNome: %s\n", temp->da.nome); 
		printf(" 1ª Nota: %.1f\n", temp->da.nota1); 
		printf(" 2ª Nota: %.1f\n", temp->da.nota2); 
		printf("     Sub: %.1f\n", temp->da.sub); 
		printf("Situação: %s\n", temp->da.final); 
		temp = temp->proximo;
	}
	
	system("pause");
}





















