
#include "funmate.h"

int menu(int num1 , int num2)
{
    int opcion;


        system("cls");

        printf("--Calculadora--\n\n");

        if(num1 >= 0 ) // num1 = -1 es para q me imprima el else y ya tome el valor num1 = 0
        {
            printf("1-Ingrese numero A = %d\n" , num1);

        }
        else
        {
            printf("1-Ingrese A = x\n");
        }

        if(num2 >= 0)
        {
            printf("2-Ingrese numero B = %d\n" , num2);
        }
        else
        {
            printf("2-Ingrese B = y\n");
        }

        printf("3- Calcular todas las operaciones\n");
        printf("4- Mostar resultado\n");
        printf("5- Salir\n\n");
        printf("Elija una opcion: ");
        scanf("%d" , &opcion);


    return opcion;

}

int sumar(int num1 , int num2)
{
    int resultadoSuma;

    resultadoSuma = num1 + num2;

    return resultadoSuma;
}

int restar(int num1 , int num2)
{
     int resultadoResta;

     resultadoResta = num1 - num2;

     return resultadoResta;
}

int multiplicacion(int num1 , int num2)
{
    int resultadoM;

    resultadoM = num1 * num2;

    return resultadoM;
}

float division(int num1 , int num2)
{
    float resultadoD;

    resultadoD = (float) num1 / num2;

    return resultadoD;
}

int factorial(int num1)
{
    //int fac;

    int fac = 1;

    for(int i = 1 ; i <= num1 ; i++)
    {
        fac = fac * i;
    }


    return fac;
}
