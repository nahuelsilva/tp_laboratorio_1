/*
 * math.h
 *
 *  Created on: 25 sep. 2021
 *      Author: User
 */

#ifndef MATH_H_
#define MATH_H_
#include <stdio.h>

/// @fn int Suma(int, int)
/// @brief esta funcion recibe dos enteros para luego sumarlos
/// @param num1 recibe el primer numero como parametro
/// @param num2 recibe el segundo numero como parametro
/// @return lo que devuelve o retorna es el resultado de la suma
int Suma(int num1, int num2);

/// @fn int Resta(int, int)
/// @brief esta funcion recibe dos enteros para luego restarlos
/// @param num1 recibe desde el main el primer numero
/// @param num2 recibe el segundo numero como parametro
/// @return retorna el resultado de la resta
int Resta(int num1, int num2);

/// @fn int Multiplicacion(int, int)
/// @brief esta recibe dos enteros para luego multiplicarlos
/// @param num1 recibe el primer numero como parametro
/// @param num2 recibe el segundo numero tambien como parametro
/// @return retorna el resultado de la multiplicacion
int Multiplicacion(int num1, int num2);

/// @fn float Division(int, int)
/// @brief esta funcion recibe dos enteros para dentro de ella haga su division teniendo en cuenta
/// que la divion por cero no se puede realizar
/// @param num1 recibe el primer numero como parametro
/// @param num2 recibe el entero como parametro
/// @return retorna el resultado en caso de que no se haya ingresado cero
float Division(int num1, int num2);

/// @fn void Factorial(int, int)
/// @brief esta funcion solo recibe los dos enteros pero no devuelve nada ya que dentro de ella
/// muestra sus resultados
/// @param num1 recibe primer entero
/// @param num2 le pasammos por parametros el segundo numero
void Factorial(int num1 , int num2);

#endif /* MATH_H_ */
