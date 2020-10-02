#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ArrayEmployees.h"

int inicializarEmpleados(eEmpleado empleados[], int tam)
{
    int error = 1;

    if(empleados != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            empleados[i].isEmpty = 1;

            error = 0;
        }
    }

    return error;
}

int altaEmpleados(eEmpleado empleados[], int tam, int legajo)
{
    int error = 1;

    eEmpleado nuevoEmpleado;
    int indice;

    if(empleados != NULL && tam > 0 && legajo > 0)
    {
        indice = buscarLibre(empleados, tam);
        if(indice == -1)
        {
            printf("Sistema completo..\n");
        }
        else
        {
            nuevoEmpleado.idem = legajo;
            nuevoEmpleado.isEmpty = 0;
            printf("Ingrese nombre del empleado: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.apellido);
            printf("Ingrese salario: ");
            scanf("%f", &nuevoEmpleado.salario);
            printf("Ingrese sector del empleado: ");
            scanf("%d", &nuevoEmpleado.sector);

            empleados[indice] = nuevoEmpleado;

            error = 0;
        }
    }

    return error;
}

int buscarLibre(eEmpleado empleados[], int tam)
{
    int indice = -1;

    if(empleados != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
        {
            if(empleados[i].isEmpty == 1)
            {
                indice = i;
                break; // este break es para q en la 1°era vuelta encuentre el lugar vacio, entre y no siga ilterando
            }
        }
    }

    return indice;
}

void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%4d   %20s     %20s      %9.2f    %2d\n", unEmpleado.idem, unEmpleado.nombre, unEmpleado.apellido, unEmpleado.salario, unEmpleado.sector);
}

int mostrarEmpleados(eEmpleado empleados[], int tam)
{
    int error = 1;
    int flag = 0;
    if(empleados != NULL && tam > 0)
    {
        printf(" ID                 Nombre                   Apellido       Salario   Sector  \n\n");
        printf("-----------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(empleados[i].isEmpty == 0)
            {
                mostrarEmpleado(empleados[i]);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("No hay personas todavia..");
        }
        else
        {
            printf("\n\n");
        }

        error = 0;
    }

    return error;
}

int buscarEmpleadoId(eEmpleado empleados[], int tam, int legajo)
{
    int indice = -1;

    if(empleados != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
        {
            if(empleados[i].idem == legajo && empleados[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int bajaEmpleado(eEmpleado empleados[], int tam)
{
    int error = 1;
    int legajo;
    int indice;
    char respuesta;

    if(empleados != NULL && tam > 0)
    {
        mostrarEmpleados(empleados, tam);
        printf("Ingrese ID de empleado a dar de baja: ");
        scanf("%d", &legajo);

        indice = buscarEmpleadoId(empleados, tam, legajo);  // con esto le estoy diciendo q busque el empleado con ese id y copie en indice si lo encuentra

        if(indice == -1)
        {
            printf("No hay personas con ese ID.\n");
        }
        else
        {
            mostrarEmpleado(empleados[indice]);// aca le digo q me mustre el empleado con ese id
            printf("Confirma la baja del empleado?: ");
            fflush(stdin);
            scanf("%c", &respuesta);

            if(respuesta == 's')
            {
                empleados[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }

    return error;
}

int modificarEmpleado(eEmpleado empleados[], int tam)
{
    int error = 1;
    int legajo;
    int indice;
    int opcion;
    eEmpleado cambiarInfo;

    if(empleados != NULL && tam > 0)
    {
        mostrarEmpleados(empleados, tam);
        printf("Ingrese ID del empleado a modificar: ");
        scanf("%d", &legajo);

        for(int i = 0; i < tam ; i++)
        {
            indice = buscarEmpleadoId(empleados, tam, legajo);
        }
        if(indice == -1)
        {
            printf("No hay empleados con ese ID");
        }
        else
        {
            mostrarEmpleado(empleados[indice]);
            printf("Elija una opcion a modificar: \n");
            printf("1- Nombre.\n");
            printf("2- Apellido.\n");
            printf("3- Salario.\n");
            printf("4- Sector.\n");
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:

                printf("Ingrese nombre a cambiar: ");
                fflush(stdin);
                gets(cambiarInfo.nombre);
                strcpy(empleados[indice].nombre, cambiarInfo.nombre);

                break;

            case 2:
                printf("Ingrese apellido a cambiar: ");
                fflush(stdin);
                gets(cambiarInfo.apellido);
                strcpy(empleados[indice].apellido, cambiarInfo.apellido);

                break;

            case 3:
                printf("Ingrese salario a cambiar: ");
                scanf("%f",&cambiarInfo.salario);
                empleados[indice].salario = cambiarInfo.salario;

                break;

            case 4:
                printf("Ingrese sector a cambiar: ");
                scanf("%d", &cambiarInfo.sector);
                empleados[indice].sector = cambiarInfo.sector;


                break;

            default:
                printf("Opcion invalida.\n");

            }
            error = 0;
        }


    }
    return error;
}

int ordenarApellidos(eEmpleado empleados[], int tam, int criterio)
{
    int error = 1;
    eEmpleado auxEmpleado;

    if( empleados != NULL && tam > 0 && criterio >= 0 && criterio <= 1)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            for(int j = i+1 ; j < tam ; j++)
            {
                if((strcmp(empleados[i].apellido, empleados[j].apellido) > 0) && criterio == 0)//strcmp esta comparando los apellidos si devuelve mayor a cero es q estan desacomodadas alfabeticamente
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }
                else
                {
                    if(strcmp(empleados[i].apellido, empleados[j].apellido) < 0 && criterio == 1)
                    {
                        auxEmpleado = empleados[i];
                        empleados[i] = empleados[j];
                        empleados[j] = auxEmpleado;
                    }
                    else
                    {
                        if(empleados[i].sector < empleados[j].sector)
                        {
                            auxEmpleado = empleados[i];
                            empleados[i] = empleados[j];
                            empleados[j] = auxEmpleado;
                        }
                    }
                }


            }

            error = 0;
        }

    }

    return error;
}

int salarioEmpleado(eEmpleado empleados[], int tam)
{
    int error = 1;
    int contadorSalario = 0;
    int acumuladorSalario = 0;
    int promedioSalario;
    int contadorSueldoMayor = 0;
    int flagSueldoMayor = 1;

    if(empleados != NULL && tam > 0)
    {

        for(int i = 0 ; i < tam ; i++)
        {
            acumuladorSalario = acumuladorSalario + empleados[i].salario;
            contadorSalario++;
            if(flagSueldoMayor  == 1 || empleados[i].salario > 25000)
            {
                contadorSueldoMayor++;
            }
            flagSueldoMayor = 0;

        }

        promedioSalario = acumuladorSalario / contadorSalario;
        printf("El total de sueldo es: %d\n", acumuladorSalario);
        printf ("Su promedio por empleado es: %d\n", promedioSalario);
        printf("Los que cobran mas de un sueldo promedio son: %d\n\n", contadorSueldoMayor);


        error = 0;
    }
    return error;
}
