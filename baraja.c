/*
	Baraja en Lenguaje C
	- Crear mazo de juego
	- Barajear Mazo
	- Tener 1 Carta
	- Contar Cartas (Con fines Estadisticos)
	
	Twitter @albertobsd
	Web: http://CodigoEnC.com
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *baraja ="A234567890JQKA234567890JQKA234567890JQKA234567890JQK";
char *mazo;
int fin;
int posicion = 0;

void crear_mazo(int numero);
void barajear_mazo();
char obtener_carta();
int es_fin();

int main()	{
	char carta;
	int contador;
	crear_mazo(10);
	barajear_mazo();
	printf("%s\n",mazo);
	while(!es_fin()){
		carta = obtener_carta();
		switch(carta)	{
			case 'A':
			case 'K':
			case 'Q':
			case 'J':
			case '0':
				contador--;
			break;
			case '9':
			case '8':
			case '7':
			break;
			case '6':
			case '5':
			case '4':
			case '3':
			case '2':
				contador++;
			break;
		}
		printf("%i\n",contador);
	}
}

void crear_mazo(int numero)	{
	int i = 0;
	int longitud = strlen(baraja);
	int offset = 0;
	mazo = calloc(longitud+1,numero);
	while(i < numero){
		memcpy(mazo+offset,baraja,longitud);
		offset +=longitud;
		i++;
	}
}

void barajear_mazo()	{
	//
	char *barajeado;
	int i = 0;
	int longitud = strlen(mazo);
	int r;
	fin = longitud;
	srand(time(NULL));
	barajeado = calloc(longitud+1,1);
	while(i < longitud)	{
		r = rand() %longitud;
		if(mazo[r] != '\0')	{
			barajeado[i] = mazo[r];
			mazo[r] = 0;
			i++;	
		}
	}
	free(mazo);
	mazo = barajeado;
}

char obtener_carta()	{
	char carta;
	carta = mazo[posicion];
	mazo[posicion] = '\0';
	posicion++;
	return carta;
}

int es_fin()	{
	if(posicion == fin)	{
		return 1;
	}
	else	{
		return 0;
	}
}