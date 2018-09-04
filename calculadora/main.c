#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Funciones.h"
#include "Funciones.c"

int ingresarOpcion(void);

int main()
{
    float numeroA;
    float numeroB;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    float factorialA;
    float factorialB;
    int banderaA=0;
    int banderaB=0;
    int opcion;

    do
    {
        printf("\n---CALCULADORA--\n\n");
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
                suma=sumar(numeroA,numeroB);
                printf("El resultado de la suma es %.2f\n", suma);

                resta=restar(numeroA,numeroB);
                printf("El resultado de la resta es %.2f\n", resta);

                multiplicacion=multiplicar(numeroA,numeroB);
                printf("El resultado de la multiplicacion es %.2f\n", multiplicacion);

                division=dividir(numeroA,numeroB);
                printf("El resultado de la division es %.2f\n", division);

                mostrarFactorialA();

                mostrarFactorialB();
                break;


            case 5:
                printf("Saliendo...\n");
                break;

            default:
                printf("Elija un numero del 1 al 5\n");
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
    scanf("%d",&opcion);

    return opcion;
}
