#include <stdio.h>
#include <stdlib.h>

#include "funmate.h"

int main()
{
    int num1 = -1;
    int num2 = -1;
    int opcion;

    int rdoS;
    int rdoR;
    int rdoM;
    float rdoD;
    int rdoF;

    int flagNum1 = 0;
    int flagNum2 = 0;
    int flagCalculos = 0;

    opcion = menu(num1 , num2);

    while(opcion != 5)
    {


        switch(opcion)
        {

            case 1:
                printf("Ingrese primer operador: \n");
                scanf("%d" , &num1);
                flagNum1 = 1;
                break;

            case 2:
                printf("Ingrese 2do operador: \n");
                scanf("%d" , &num2);
                flagNum2 = 1;
                break;

            case 3:
                  if(flagNum1 == 1 && flagNum2 == 1)
                  {
                       printf("Realizando operaciones con exito:\n");
                       rdoS = sumar(num1 , num2);
                       rdoR = restar(num1 , num2);
                       rdoM = multiplicacion(num1 , num2);
                       rdoD = division(num1 , num2);
                       rdoF = factorial(num1);

                        flagCalculos = 1;
                  }
                 else
                 {
                    printf("Error ingrese numeros primero\n");

                 }

                break;

            case 4:
                if(flagCalculos == 1)
                {
                    printf("LA suma es: %d\n" , rdoS);
                    printf("La resta es: %d\n" , rdoR);
                    printf("La multiplicacion es: %d\n" , rdoM);
                    printf("La division es: %.2f\n" , rdoD);
                    printf("El factorial del primero es: %d\n" , rdoF);

                }
                else
                {
                    printf("Primero realizar calculos\n");

                }

                break;


            default:
                printf("Error.. Caracter invalido\n");
                break;

        }

        system("pause");
        opcion = menu(num1 , num2);
    }

    return 0;

    }

