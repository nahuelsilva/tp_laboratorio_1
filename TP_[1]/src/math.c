/*
 * math.c
 *
 *  Created on: 25 sep. 2021
 *      Author: User
 */

#include "math.h"

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
