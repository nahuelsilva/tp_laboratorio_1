/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "empleados.h"








int main(void) {
	setbuf(stdout,NULL);

	int opcion;

	eEmpleados listaEmpleados[TAM];

	Inicializar(listaEmpleados,TAM);
	int idGenerador = 100;
	int flag1 = 0;
	int sueldosMayoresEmpleados;

	opcion = Menu();


	//tengo q validar para q NO entre un caracter
	while(opcion != 5)
	{
		switch(opcion){

			case 1:
				AltaEmpleado(listaEmpleados,TAM,idGenerador);
				idGenerador++;
				flag1 = 1;
				break;

			case 2:
				if(flag1 == 1)
				{
					ModificarEmpleado(listaEmpleados,TAM);
				}
				else
				{
					printf("Error. Primero ingrese por lo menos un empleado: \n");
				}
				break;

			case 3:
				if(flag1 == 1)
				{
					EliminarEmpleado(listaEmpleados,TAM);
				}
				else
				{
					printf("Error. Primero ingrese por lo menos un empleado: \n");
				}
				break;

			case 4:
				if(flag1 == 1)
				{
					OrdenarPorApellidoSector(listaEmpleados,TAM);
					PromedioSalario(listaEmpleados, TAM);

					if(EmpleadosMayorAlPromedio(listaEmpleados, TAM, &sueldosMayoresEmpleados,55000) == 1)
					{
						printf("Los empleados que superan el sueldo promedio son: %d\n", sueldosMayoresEmpleados);

					}
					else
					{
						printf("No hay sueldos mayores al promedio\n");
					}

				}
				else
				{
					printf("Error. Primero ingrese por lo menos un empleado: \n");
				}

				break;

			default:
				printf("ERROR... INGRESE NUEVAMENTE NUMERO:\n");
				break;
		}

		opcion = Menu();
	}




	return EXIT_SUCCESS;
}

