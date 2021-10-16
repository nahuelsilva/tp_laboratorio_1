/*
 * empleados.h
 *
 *  Created on: 16 oct. 2021
 *      Author: User
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_
#include <stdio.h>
#include <string.h>

#define TAM 10
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int isEmpty;
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;


}eEmpleados;




int Menu();
void Inicializar(eEmpleados lista[], int tam);
void MostrarUnEmpleado(eEmpleados unEmpleado);
void ListaDeEmpleados(eEmpleados lista[], int tam);
void AltaEmpleado(eEmpleados lista[], int tam, int idGenerador);
int PedirEntero(char mensaje[],char mensajeError[], int min,int max);
void GetString(char mesaje[], char cadena[], int tam);
float PedirFlotante(char mensaje[]);
int BuscarEmpleado(eEmpleados lista[], int tam);
void EliminarEmpleado(eEmpleados lista[], int tam);
void ModificarEmpleado(eEmpleados lista[], int tam);
void OrdenarPorApellidoSector(eEmpleados lista[], int tam);
void PromedioSalario(eEmpleados lista[], int tam);
int EmpleadosMayorAlPromedio(eEmpleados lista[], int tam, int* sueldosMayor, int sueldoPromedio);

#endif /* EMPLEADOS_H_ */
