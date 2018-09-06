#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#include "Funciones.c"

int main()
{
    float numeroA;
    float numeroB;
    float resultado;
    int banderaA=0;
    int banderaB=0;
    int opcion;

    do
    {
        printf("\n*************CALCULADORA*************\n\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        if(banderaA==1)
        {
            printf("\n1. Ingresar el primer numero (A=%.2f)",numeroA);
        }
        else
        {
            printf("\n1. Ingresar el primer numero (A=x)");
        }
            if(banderaB==1)
            {
                printf("\n2. Ingresar el segundo numero (B=%.2f)",numeroB);
            }
            else
            {
                printf("\n2. Ingresar el segundo numero (B=x)");
            }

        printf("\n3. Realizar los calculos");
        printf("\n4. Mostrar los resultados");
        printf("\n5. Salir\n\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

        opcion=ingresarOpcion();
        switch(opcion)
        {
            case 1:
                banderaA=1;
                ingresarNumero(&numeroA);
                break;

            case 2:
                banderaB=1;
                ingresarNumero(&numeroB);
                break;

            case 3:
                if(banderaA==1 && banderaB==1)
                {
                    printf("\nCalculando la suma ...");
                    printf("\nCalculando la resta ...");
                    printf("\nCalculando la multiplicacion ...");
                    printf("\nCalculando la division ...");
                    printf("\nCalculando los factoriales ... \n\n");
                }
                else
                {
                    printf("\nError! Ingrese los 2 numeros...");
                }
                break;

            case 4:
                if(banderaA==1 && banderaB==1)
                {

                    resultado=sumar(numeroA,numeroB);

                    resultado=restar(numeroA,numeroB);

                    resultado=multiplicar(numeroA,numeroB);

                    resultado=dividir(numeroA,numeroB);

                    if(numeroA<0)
                    {
                        printf("(Error %.2f) No se pueden factorizar los numeros negativos!!!\n",numeroA);
                    }
                    else
                    {
                        mostrarFactorial(numeroA);
                    }

                    if(numeroB<0)
                    {
                        printf("(Error %.2f) No se pueden factorizar los numeros negativos!!!\n",numeroB);
                    }
                    else
                    {
                        mostrarFactorial(numeroB);

                    }
                }
                else
                {
                    printf("\nError!!! Aun no hiciste los calculos!!\n\n");
                }
                break;


            case 5:
                printf("Saliendo...\n");
                break;

            default:
                printf("Error. Ingrese una opcion valida (1-5): ");
        }

        system("pause"); //pausa la consola
        system("cls");  //limpia

    }while (opcion!=5);

    return 0;
}

int ingresarOpcion(void)
{
    int opcion;
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    while(opcion <1 || opcion>5)
    {
        printf("Error. Ingrese una opcion valida (1-5): ");
        fflush(stdin);
        scanf("%d",&opcion);
    }

    return opcion;
}
