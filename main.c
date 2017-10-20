#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	srand(time(NULL));
	
	char respuesta; 
	char carta1 = ' ';
	char carta2 = ' '; 
	char carta3_extra = ' ';
	int tipo[13] = {2,3,4,5,6,7,8,9,10,11,12,12,14};
	int deck[52];
	int i = 0, j = 0, k = 0, min = 0, max = 51, az = 0;
	int valor1 = 0, valor2 = 0, carta3 = 0;
	//Llenar el deck
	for(i = 0; i<4; i++){
		for(j = 0; j < 13; j++){
			deck[k] = tipo[j];
			k++;
		}
	}
	printf("Cartas en el deck: \n\n");
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
	//Si gana el juego en la primer ronda
	if((valor1 == 14 && valor2 >9 && valor2 < 14) || (valor1 < 14 && valor1 > 9 && valor2 == 14)){
		printf("\n Ganaste el juego en la primer ronda! \n");
		return 0;
	}
	printf("\nCarta1: ");
	if(valor1 > 10){
		switch(valor1){
		case 11:
			carta1 = 'J';
			valor1 = 10;
			break;
		case 12:
			carta1 = 'Q';
			valor1 = 10;
			break;
		case 13:
			carta1 = 'K';
			valor1 = 10;
			break;
		case 14:
			carta1 = 'A';
			do{
				printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
				scanf("%d", &az);
			}while(az != 1 && az != 11);
			valor1 = az;
			break;
		}
		printf("%c\n", carta1);
	}else{
		printf("%d\n", valor1);
	}
	
	
	
	printf("Carta2: ");
	if(valor2 > 10){
		switch(valor2){
		case 11:
			carta2 = 'J';
			valor2 = 10;
			break;
		case 12:
			carta2 = 'Q';
			valor2 = 10;
			break;
		case 13:
			carta2 = 'K';
			valor2 = 10;
			break;
		case 14:
			carta2 = 'A';
			do{
				printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
				scanf("%d", &az);
			}while(az != 1 && az != 11);
			valor2 = az;
			break;
		}
		printf("%c\n", carta2);
	}else{
		printf("%d\n", valor2);
	}
	
	
	
	int suma = valor1 + valor2;
	printf("\nEl valor de las dos es: %d \n", suma);
	
	do{
		fflush(stdin);
		printf("\nQuieres otra carta? S/N\n");
		scanf(" %c", &respuesta);
		if (respuesta == 's' || respuesta == 'S') {
			do{
				random3 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
			}while(deck[random3] == 0);
			
			carta3 = deck[random3];
			deck[random3] = 0;
			
			printf("Tu carta es: ");
			
			if(carta3 > 10){
				switch(carta3){
				case 11:
					carta3_extra = 'J';
					carta3 = 10;
					break;
				case 12:
					carta3_extra = 'Q';
					carta3 = 10;
					break;
				case 13:
					carta3_extra = 'K';
					carta3 = 10;
					break;
				case 14:
					carta3_extra = 'A';
					do{
						printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
						scanf("%d", &az);
					}while(az != 1 && az != 11);
					carta3 = az;
					break;
				}
				printf("%c\n", carta3_extra);
			}else{
				printf("%d\n", carta3_extra);
			}
			
			suma = suma + carta3;
			printf("La suma es: %d \n", suma);
			
			if(suma > 21){
				printf("!PERDISTE!!! \n");
				/// temporal
				int count = 0;
				for(int i=0;i<52;i++){
					printf("%d ", deck[i]);
					if(count == 12){
						printf("\n");
						count = 0;
						continue;
					}
					count ++ ;
				}
				
				return EXIT_SUCCESS;
			}
			
		} else {
			break;
		}
	}while(1);
	
	// Juego computadora
	int flag = 1;
	int flag2 = 1;
	
	random1 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	random2 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	
	do{
		if(deck[random1] != 0 && flag){
			valor1 = deck[random1];
			deck[random1] = 0;
			flag = 0;
		}else{
			random1 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
		}
		
		if(deck[random2] !=0 && flag2 ){
			valor2 = deck[random2];
			deck[random2] = 0;
			flag2 = 0;
		}else{
			random2 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
		}
		
	}while(flag || flag2);
	
	random3 = 0;
	
	//    valor1 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	//    valor2 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	carta3 = 0;
	carta3_extra = ' ';
	
	//    printf("valor1: %d \nvalor2: %d \n", valor1, valor2);
	if((valor1 == 14 && valor2 >9 && valor2 < 14) || (valor1 < 14 && valor1 > 9 && valor2 == 14)){
		printf("\n!! Gano la computadora con un BlackJack!!\n");
		return EXIT_SUCCESS;
	}
	int bandera_AS1 = 0;
	int bandera_AS2 = 0;
	
	printf("\nPrimer carta de la computadora es: ");
	if(valor1 > 10){
		switch(valor1){
		case 11:
			carta1 = 'J';
			valor1 = 10;
			break;
		case 12:
			carta1 = 'Q';
			valor1 = 10;
			break;
		case 13:
			carta1 = 'K';
			valor1 = 10;
			break;
		case 14:
			carta1 = 'A';
			bandera_AS1 = 1;
			do{
				printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
				scanf("%d", &az);
			}while(az != 1 && az != 11);
			valor1 = az;
			break;
		}
		printf("%c\n", carta1);
	}else{
		printf("%d\n", valor1);
	}
	
	
	printf("Segunda carta de la computadora es: ");
	if(valor2 > 10){
		switch(valor2){
		case 11:
			carta2 = 'J';
			valor2 = 10;
			break;
		case 12:
			carta2 = 'Q';
			valor2 = 10;
			break;
		case 13:
			carta2 = 'K';
			valor2 = 10;
			break;
		case 14:
			carta2 = 'A';
			bandera_AS2 =1;
			do{
				printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
				scanf("%d", &az);
			}while(az != 1 && az != 11);
			valor2 = az;
			break;
		}
		printf("%c\n", carta2);
	}else{
		printf("%d\n", valor2);
	}
	
	int suma_compu = valor1 + valor2;
	printf("La suma de la computadora es: %d \n", suma_compu);
	
	do{
		//        fflush(stdin);
		//        printf("\nQuieres otra carta? \n");
		//        scanf(" %c", &respuesta);
		if (suma > suma_compu) {
			do{
				random3 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
			}while(deck[random3] == 0);
			
			carta3 = deck[random3];
			deck[random3] = 0;
			
			printf("Tu carta es: ");
			
			if(carta3 > 10){
				switch(carta3){
				case 11:
					carta3_extra = 'J';
					carta3 = 10;
					break;
				case 12:
					carta3_extra = 'Q';
					carta3 = 10;
					break;
				case 13:
					carta3_extra = 'K';
					carta3 = 10;
					break;
				case 14:
					carta3_extra = 'A';
					do{
						printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
						scanf("%d", &az);
					}while(az != 1 && az != 11);
					carta3 = az;
					break;
				}
				printf("%c\n", carta3_extra);
			}else{
				printf("%d\n", carta3);
			}
			
			suma_compu = suma_compu + carta3;
			printf("La suma de la compu es: %d \n", suma_compu);
			
			if(suma_compu > 21){
				printf("!PERDIO LA COMPUTADORA!!! \n");
				
				/// temporal
				int count = 0;
				for(int i=0;i<52;i++){
					printf("%d ", deck[i]);
					if(count == 12){
						printf("\n");
						count = 0;
						continue;
					}
					count ++ ;
				}
				return EXIT_SUCCESS;
			}
			
		} else {
			break;
		}
	}while(1);
	
	if(suma > suma_compu ){
		printf("!GANASTE!!! \n");
	}else{
		printf("!PERDISTE!!! \n");
	}
	
	/// temporal
	int count = 0;
	for(int i=0;i<52;i++){
		printf("%d ", deck[i]);
		if(count == 12){
			printf("\n");
			count = 0;
			continue;
		}
		count ++ ;
	}
	
	return 0;
}
