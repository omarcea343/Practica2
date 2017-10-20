#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	srand(time(NULL));
	
	char respuesta, carta1 = ' ', carta2 = ' ', carta3_extra = ' ';
	int tipo[13] = {2,3,4,5,6,7,8,9,10,11,12,12,14};
	int deck[52];
	int i = 0,j = 0,k = 0, min = 0, max = 51, az = 0, valor1, valor2, carta3 = 0;
	//Llenar el deck
	for(i = 0; i<4; i++){
		for(j = 0; j < 13; j++){
			deck[k] = tipo[j];
		}
	}
	//Imprir Deck
	for(i = 0;i < 52; i++){
		printf("%d ", deck[i]);
		if (deck[i] == 14){
			printf("\n");
		}
	}
	//Obtener Valores Aleatorios
	int random1 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	int random2 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	int random3 = 0;
	//Asignar cartas del deck aleatoriamente
	valor1 = deck[random1];
	valor2 = deck[random2];	
	//Marcar como usada la carta
	deck[random1] = 0;
	deck[random2] = 0;	
	
	if(){
		
	}
	
	printf("");
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
