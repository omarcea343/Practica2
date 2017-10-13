#include <stdio.h>
#include <time.h>

int main(){
	
	//srand(time(NULL));
	
	char respuesta;
	int valor = 0, minimo = 0, maximo = 100;
	
	//valor = minimo + rand() / (RAND_MAX / (maximo - minimo + 1 ) + 1);
	
	printf("Quieres otra carta? S/N \n");
	scanf("%c", &respuesta);
	
	printf("\nSeleccion: %c", respuesta);
	
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
