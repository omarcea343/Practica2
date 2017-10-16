#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	srand(time(NULL));
	
	char respuesta;
	char carta1 = ' ';
	int carta2 = 0;
	int valor = 0, valor1 = 0, minimo = 10, maximo = 14;
	
	valor = minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	valor1 = minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	
	if(valor > 10){
		switch(valor){
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
	
	printf("Tus cartas son: %c y &d \n", carta1, carta2);
	
	printf("Quieres otra carta? S/N \n");
	scanf("%c", &respuesta);
	
	printf("\nSeleccion: %c \n", respuesta);
	
	return 0;
}

/*
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
*/
