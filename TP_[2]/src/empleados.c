/*
 * empleados.c
 *
 *  Created on: 16 oct. 2021
 *      Author: User
 */


#include "empleados.h"

int Menu()
{
	int respuesta;

		printf("---MENU DE OPCIONES EMPLEADOS---\n\n");
		printf("Elija una opcion en numeros: \n");
		printf("1) Alta de empleado: \n");
		printf("2) Modificar datos del empleado: \n");
		printf("3) Baja de empleado: \n");
		printf("4) Informar: \n");
		printf("5) Salir.\n");
		scanf("%d", &respuesta);

		return respuesta;
}

int PedirEntero(char mensaje[],char mensajeError[], int min,int max)
{
	int numero;
	int retorno = -1;

	printf("%s", mensaje);
	scanf("%d", &numero);

	while(numero)
	{
		if(numero >= min && numero <= max)
		{
			retorno = numero;
			break;
		}

		printf("%s", mensajeError);
		scanf("%d", &numero);
	}


	return retorno;

}

float PedirFlotante(char mensaje[])
{
	float numero;
	printf("%s", mensaje);
	scanf("%f", &numero);

	return numero;
}

void GetString(char mensaje[], char cadena[], int tam)
{
	char aux[tam];
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", aux);

	strcpy(cadena, aux);
}

void Inicializar(eEmpleados lista[], int tam)
{
	for(int i=0; i<tam; i++){

		lista[i].isEmpty = LIBRE;

	}
}

void MostrarUnEmpleado(eEmpleados unEmpleado)
{
	printf("%4d  %20s    %20s       %7.2f     %2d\n", unEmpleado.id, unEmpleado.name,unEmpleado.lastName,unEmpleado.salary, unEmpleado.sector);
}

void ListaDeEmpleados(eEmpleados lista[], int tam)
{
	printf(" ID                   Name                Lastname        Salary     Sector\n");
	for(int i=0; i<tam; i++){

		if(lista[i].isEmpty == OCUPADO)
		{
			MostrarUnEmpleado(lista[i]);
		}
	}

}

void AltaEmpleado(eEmpleados lista[], int tam, int idGenerador)
{



	for(int i=0; i<tam; i++){

		if(lista[i].isEmpty == LIBRE)
		{
			lista[i].id = idGenerador;
			GetString("Ingrese Nombre: \n", lista[i].name,51);
			GetString("Ingrese Apellido: \n", lista[i].lastName,51);
			lista[i].salary = PedirFlotante("Ingrese Salario: \n");
			lista[i].sector = PedirEntero("Ingrese Sector del empleado: \n", "Error.Ingrese numero correcto: (1,10) \n", 1,10);
			lista[i].isEmpty = OCUPADO;

			break;
		}
	}


}

void EliminarEmpleado(eEmpleados lista[], int tam)
{
	int idEliminar;
	char respuesta;

	idEliminar = BuscarEmpleado(lista,tam);

	for(int i=0; i<tam; i++){

		if(idEliminar == lista[i].id){

			printf("Quiere eliminar este empleado: \n");
			fflush(stdin);
			scanf("%c", &respuesta);

			if(respuesta == 's'){

	            lista[i].isEmpty = LIBRE;

	            break;
			}

		}
	}
}

int BuscarEmpleado(eEmpleados lista[], int tam)
{
	int idBuscado;
	int retorno = -1;

	ListaDeEmpleados(lista,tam);
	printf("Ingrese Id del empleado: \n");
	scanf("%d", &idBuscado);

	for(int i=0; i<tam; i++){

		if(idBuscado == lista[i].id){

			MostrarUnEmpleado(lista[i]);
			retorno = lista[i].id;
			break;
		}
	}

	return retorno;
}

void ModificarEmpleado(eEmpleados lista[], int tam)
{
	int idModificar;

	idModificar = BuscarEmpleado(lista,tam);

	for(int i=0; i<tam; i++){

		if(idModificar == lista[i].id){

			GetString("Ingrese Nombre: \n", lista[i].name,51);
			GetString("Ingrese Apellido: \n", lista[i].lastName,51);
			lista[i].salary = PedirFlotante("Ingrese Salario: \n");
			lista[i].sector = PedirEntero("Ingrese Sector del empleado: \n", "Error.Ingrese numero corrcto: \n", 1,10);
		}

	}

}

void OrdenarPorApellidoSector(eEmpleados lista[], int tam)
{
	eEmpleados aux;

	for(int i=0; i<tam-1; i++){

		for(int j=i+1; j<tam; j++){

			if(strcmp(lista[i].lastName , lista[j].lastName) > 0){

				aux = lista[i];
				lista[i] = lista[j];
				lista[j] = aux;

			}
		}
	}
	ListaDeEmpleados(lista,tam);
}

void PromedioSalario(eEmpleados lista[], int tam)
{
	float acumulador = 0;
	float resultado;
	int contador = 0;


	for(int i=0; i<tam; i++)
	{
		if(lista[i].isEmpty == OCUPADO)
		{
			acumulador += lista[i].salary;
			contador++;
		}

	}
	resultado = (float) acumulador / contador;

	printf("El promedio de los sueldos es: %f\n", resultado);
}

int EmpleadosMayorAlPromedio(eEmpleados lista[], int tam, int* sueldosMayor, int sueldoPromedio)
{
	int retorno = 0;
	int contador = 0;

	for(int i=0; i<tam; i++)
	{
		if(lista[i].isEmpty == OCUPADO)
		{
			if(lista[i].salary > sueldoPromedio)
			{

				contador++;
				retorno = 1;

			}

		}
	}

	*sueldosMayor = contador;
	return retorno;
}

