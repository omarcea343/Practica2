#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
	srand(time(NULL));
	
	char respuesta;
	char carta1=' ';
	char carta2=' ';
	// Posibles valores:
	// 2,3,4,5,6,7,8,9,10,  J,  Q,  K,  A
	// 2,3,4,5,6,7,8,9,10, 11, 12, 13, 14
	int min = 10;
	int max = 14;
	int valor_as = 0;
	int valor1 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	int valor2 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	
	if((valor1 == 14 && valor2 >9) || (valor1 > 9 && valor2 == 14)){
		printf("\n!! Felicidades obtuviste un BlackJack!!");
		return EXIT_SUCCESS;
	}
	
	printf("\nTus cartas son: ");
	if(valor1 > 10){
		switch(valor1){
		case 11:
			carta1 = 'J';
		case 12:
			carta1 = 'Q';
		case 13:
			carta1 = 'K';
			valor1 = 10;
			break;
		case 14:
			carta1 = 'A';
			do{
				printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
				scanf("%d", &valor_as);
			}while(valor_as != 1 && valor_as != 11);
			valor1 = valor_as;
			break;
		}
		printf("%c", carta1);
	}else{
		printf("%d", valor1);
	}
	
	printf(" y ");
	if(valor2 > 10){
		switch(valor2){
		case 11:
			carta2 = 'J';
		case 12:
			carta2 = 'Q';
		case 13:
			carta2 = 'K';
			valor2 = 10;
			break;
		case 14:
			carta2 = 'A';
			do{
				printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
				scanf("%d", &valor_as);
			}while(valor_as != 1 && valor_as != 11);
			valor2 = valor_as;
			break;
		}
		printf("%c", carta2);
	}else{
		printf("%d", valor2);
	}
	
	int suma = valor1 + valor2;
	printf(" , la suma es: %d \n", suma);
	
	do{
		fflush(stdin);
		printf("\nQuieres otra carta? \n");
		scanf(" %c", &respuesta);
		if (respuesta == 's' || respuesta == 'S') {
			//            printf("resp: %c", respuesta);
		} else {
			break;
		}
	}while(1);
	
	return EXIT_SUCCESS;
}
