#include <stdio.h>
#include <string.h>

int main() {
	char nome[7], *p=nome, **pp=&p;
	int idade=45, *i=&idade, **ii = &i;;
	
	strcpy(nome, "Moreno");
	
	printf("              Variavel nome: %s\n", nome);
	printf("            Usando ponteiro: %s\n", p);
	printf("Usando ponteiro de ponteiro: %s\n\n", *pp);
	
	printf("            Usando ponteiro: %d\n", *i);
	printf("Usando ponteiro de ponteiro: %d\n\n", **ii);
	
	printf("2o caractere usando pp com []: %c\n", (*pp)[1]);
	printf("3o caractere usando pp com []: %c\n\n", *(*pp+2));
	
	printf("		         	 End. de nome: %p\n", &nome);
	printf("			End. ponteiro de nome: %p\n", &p);
	printf("End. ponteiro de ponteiro de nome: %p\n", &pp);
	
	printf("		        	 End. de idade: %p\n", &idade);
	printf("			End. ponteiro de idade: %p\n", &i);
	printf("End. ponteiro de ponteiro de idade: %p\n", &ii);
	
	printf("			End. onde ponteiro de nome aponta: %p\n", &*p);
	printf("End. onde ponteiro de ponteiro de nome aponta: %p\n", &**pp);

		
		
}
