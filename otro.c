#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(){
	
	int carta,pinta,numero,suma,pc_num,dealer;
	
	srand(time(NULL));
	
	printf("En el BlackJack debes juntar cartas hasta que la suma de las que tengas sea 21,\n");
	printf("Si la suma de tus cartas es mas alta que 21 ya perdiste.\n\n");
	carta = 0;
	suma = 0;
	
	while(carta!=1){
		numero = (rand()%10)+1;
		printf("Tu carta vale %d \n",numero);
		pinta = (rand()%4)+1;
		
		suma = suma + numero;                     
		printf("Tu suma es de: %d\n\n",suma);
		printf("Otra carta? \nSi >> Escribe 0\nNo >> Escribe 1\n\n");
		scanf("%d",&carta);
		if (suma>21){
			printf("Perdiste el juego!\nTe pasaste de 21\n\n");
			carta = 1;
		}
	}
	
	dealer = (rand()%7)+1;
	pc_num = dealer + 16;
	
	if(pc_num>21){
		printf("PUNTAJE JUGADOR: %d\nPUNTAJE PC: %d\n",suma,pc_num);
		printf("HA GANADO EL JUEGO!\n\n");
	}
	else if(suma<=21){
		if(suma>pc_num){
			printf("PUNTAJE JUGADOR: %d\nPUNTAJE PC: %d\n",suma,pc_num);
			printf("HA GANADO EL JUEGO!\n\n");
		}
		if(suma==pc_num){
			printf("PUNTAJE JUGADOR: %d\nPUNTAJE PC: %d\n",suma,pc_num);
			printf("JUEGO EMPATADO!!\n\n");
		}
		if(suma<pc_num){
			printf("PUNTAJE JUGADOR: %d\nPUNTAJE PC: %d\n",suma,pc_num);
			printf("HA PERDIDO EL JUEGO!\n\n");
		}
	}
	
	system("pause");
	return 0;
}  
