#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	srand(time(NULL));
	
	char respuesta;
	char carta1 = ' ';
	int carta2 = 0;
	int minimo = 10, maximo = 14;
	
	int valor1 = minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	int valor2 = minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	
	if(valor1 > 10){
		switch(valor1){
			case 11:
				carta1 = 'J';
			case 12:
				carta1 = 'Q';
			case 13:
				carta1 = 'K';
			case 14:
				carta1 = 'A';
		}
	}
	if(valor2 < 10){
		carta2 = carta2 + valor2;
	}
	printf("Tus cartas son: %c y %d \n", carta1, carta2);
	
	printf("Quieres otra carta? S/N \n");
	scanf("%c", &respuesta);
	
	printf("\nSeleccion: %c \n", respuesta);
	
	
	
	
	int i,j;
	//Tipo de Carta
	char tipo[4][9] = {"Corazones", "Diamantes", "Trebol", "Picas"};
	//Valor de Carta
	char valor[13][6] = {"Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve", "Diez", "Jack", "Queen", "King", "Az"};
	//Ciclo para eligir carta
	for(i = 1; i <= 13; i++){
		for(j = 1; j <= 4; j++){
			printf("Carta: %s de %s \n", valor[i], tipo[j]);
		}
	}
	
	
	return 0;
}
