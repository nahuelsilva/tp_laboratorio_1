#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "arrayEmployees.h"

#define TAM 1000




char menu();



int main()
{
    int idem = 1000;
    eEmpleado lista[TAM]; //= {{1000, "juan", "silva", 5400, 1, 0}, {1001, "tomas", "aguilar", 7400, 3, 0}, {1002, "ana", "resola", 1200, 2, 0}, {1003, "liliana", "oclave", 2450, 1, 0}, {1004, "pepe", "suarez", 1520, 1, 0}, {1005, "fani", "balverde", 9500, 1, 0}};
    char seguir = 's';
    char confirma;
    int rtaBaja;
    int rtaModifica;
    int flagInicio = 0;




    if(inicializarEmpleados(lista, TAM) == 0)
    {
        printf("Inicializacion con exito..\n");
    }
    else
    {
        printf("Error al inicializar\n");
    }


    do
    {
        switch(menu())
        {

        case 'a': // alta
            if(altaEmpleados(lista, TAM, idem)== 0)
            {
                idem++;
                printf("Alta exitosa..\n\n");
            }
            else
            {
                printf("Error. No se pudo hacer el alta.\n");
            }
            mostrarEmpleados(lista, TAM);
            flagInicio = 1;

            break;

        case 'b': // modificar
            if(flagInicio == 1)
            {
                rtaModifica = modificarEmpleado(lista, TAM);

                if(rtaModifica == 0)
                {
                    printf("Modificacion con exito.\n");
                }
                else
                {
                    printf("No se pudo modificar.\n");
                }

                mostrarEmpleados(lista, TAM);
            }
            else
            {
                printf("Iniciar alta primero..\n");
            }


            break;

        case 'c': // baja
            if(flagInicio == 1)
            {
                rtaBaja = bajaEmpleado(lista, TAM);

                if(rtaBaja == 0)
                {
                    printf("Baja Exitosa.\n\n");
                }
                else
                {
                    if(rtaBaja == 1)
                    {
                        printf("Problemas al realizar la baja. Intente nuevamente.\n");
                    }
                    else
                    {
                        printf("Baja cancelada por el usuario.\n");
                    }
                }
                mostrarEmpleados(lista, TAM);
            }
            else
            {
                printf("Primero inicializar empleados.\n");
            }


            break;

        case 'd': // informar
            if(flagInicio == 1)
            {

                if(ordenarApellidos(lista, TAM, ASC) == 0)
                {
                    printf("se modifico con exito..\n\n");
                    mostrarEmpleados(lista, TAM);
                }
                else
                {
                    printf("no se pudo ordenar..\n");
                }

                if(salarioEmpleado(lista, TAM) == 0)
                {
                    printf("Salio correcto..\n");
                }
                else
                {
                    printf("no se pudo.");
                }
            }
            else
            {
                printf("Ingresar por lo menos 1 alta de empleado.\n");
            }



            break;

        case 'e': // salir
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');


    return 0;
}


char menu()
{
    char opcion;
    system("cls");

    printf("***************************************** ABM EMPLEADOS *******************************************\n\n");
    printf("a Alta\n");
    printf("b Modificar\n");
    printf("c Baja\n");
    printf("d Informar\n");
    printf("e Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

