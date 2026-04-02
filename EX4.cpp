#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {
	setlocale(LC_ALL, "Portuguese");
	int *vet, num, tam = 0, max = 5;
	
	vet = (int*)calloc(5, 4/*sizeof(int)*/);
	
	do {
		printf("Escreva a merda do seu número inteiro: ");
		scanf("%d", &num);
		
		if (num >= 0){
			tam++;
			if(tam > max) {
				max *= 2;
				vet = (int*)realloc(vet,max*4/*sizeof(int)*/);
			}
			
			printf("\n%d\n", max);
			printf("\n%d\n", tam);
			
			*(vet + tam - 1) = num;
		}			
	} while(num >= 0);
	
	for(int i = 0 ; i < max; i++) {
		printf("%d° número: %d\n",i + 1, *(vet + i));
	}		
	system("pause");
		
}




