/*
 ============================================================================
 Name        : Silva Nahuel 1b
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int Menu(int num1, int num2);
int Suma(int num1, int num2);
int Resta(int num1, int num2);
int Multiplicacion(int num1, int num2);
float Division(int num1, int num2);
void Factorial(int num1 , int num2);

int main(void) {

	setbuf(stdout, NULL);

	int opcionMenu;
	int num1 = -1;
	int num2 = -1;
	int flagNum1 = 0;
	int flagNum2 = 0;
	int flagResultado = 0;
	int sumaResultado;
	int restaResultado;
	int multiplicacionResultado;
	float divisionResultado;

	opcionMenu = Menu(num1,num2);

	while(opcionMenu != 5){

		switch(opcionMenu){

		case 1:
			printf("Ingrese primer operador: \n");
			scanf("%d", &num1);
			flagNum1 = 1;
			break;

		case 2:
			printf("Ingrese segundo operador: \n");
			scanf("%d", &num2);
			flagNum2 = 1;
			break;

		case 3:
			if(flagNum1 == 1 && flagNum2 == 1){

				printf("Realizando operaciones con exito: \n");
				sumaResultado = Suma(num1, num2);
				restaResultado = Resta(num1, num2);
				multiplicacionResultado = Multiplicacion(num1,num2);
				divisionResultado = Division(num1,num2);

				flagResultado = 1;

			}
			else{

				printf("ERROR..Ingrese ambos operadores primero..\n");
			}

			break;

		case 4:
			if(flagResultado == 1){

				printf("Los resultados son: \n");
				printf("El resultado de la SUMA es: %d\n", sumaResultado);
				printf("El resultado de la RESTA es: %d\n", restaResultado);
				printf("El resultado de la MULTIPLICACION es: %d\n",multiplicacionResultado);

				if(divisionResultado == 0){
					printf("No se puede dividir un numero por CERO\n");
				}
				else{

					printf("El resultado de la DIVISION es: %.2f\n", divisionResultado);
				}
				Factorial(num1, num2);

			}
			else{

				printf("ERROR..Primero debe realizar los calculos..\n");

			}

			break;

		default:

			 printf("Error.. Caracter invalido\n");
			 break;

		}

		opcionMenu = Menu(num1, num2);
	}

	return EXIT_SUCCESS;
}

int Menu(int num1, int num2){

	int opcion;


	printf("---CALCULADORA---\n\n");

    if(num1 != -1 ) // num1 = -1 es para q me imprima el else y ya tome el valor num1 = 0
    {
        printf("1-Ingrese numero A = %d\n" , num1);

    }
    else
    {
        printf("1-Ingrese A = x\n");
    }

    if(num2 != -1)
    {
        printf("2-Ingrese numero B = %d\n" , num2);
    }
    else
    {
        printf("2-Ingrese B = y\n");
    }
	printf("3-Calcular todas las operaciones\n");
	printf("4-Informar resultados\n");
	printf("5-Salir\n");
	printf("Elija una opcion numerica:\n");
	scanf("%d", &opcion);


	return opcion;
}

int Suma(int num1, int num2){

	int resultado;

	resultado = num1 + num2;

	return resultado;
}

int Resta(int num1, int num2){

	int resultado;

	resultado = num1 - num2;

	return resultado;
}

int Multiplicacion(int num1, int num2){

	int resultado;

	if(num1 == 0 || num2 == 0){

		resultado = 0;

	}
	else{

		resultado = num1 * num2;
	}

	return resultado;
}

float Division(int num1, int num2){

	float resultado;

	if(num1 == 0 || num2 == 0){

		resultado = 0;

	}
	else{

		resultado = (float)num1 / num2;

	}

	return resultado;

}
void Factorial(int num1 , int num2){

	long int resultadoNum1 = 0;
	long int resultadoNum2 = 0;

	resultadoNum1 = 1;

	while(num1 > 1){

		resultadoNum1 *= num1;
		num1--;

	}

	printf("El factorial del primer numero es: %ld\n", resultadoNum1);

	resultadoNum2 = 1;

	while(num2 > 1){

		resultadoNum2 *= num2;
		num2--;

	}

	printf("El factorial del segundo numero es: %ld\n", resultadoNum2);
}
/*

    // Variables a utilizar
    long int Resultado=0;
    long int Factorial;

    // Solicitar numero para calcular el factorial
    printf("Introduzca No. para calcular el factorial ...: ");
    scanf(" %ld", &Factorial);
    // Calcular el factorial del numero solicitado
    Resultado = 1;
    while(Factorial > 1) {
       Resultado *= Factorial;
       printf(" %ld x",Factorial);
       Factorial--;
    }
    printf(" 1 = %ld\n\n",Resultado);

  system("PAUSE");
  return 0;
 */
