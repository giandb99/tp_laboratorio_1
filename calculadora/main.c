#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Funciones.h"
#include "Funciones.c"

int ingresarOpcion(void);

int main()
{
    float numero;
    float numeroA;
    float numeroB;
    int suma;
    int resta;
    int multiplicacion;
    float division;
    int resultadoFactorial;
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
                printf("\n2. Ingresar el segundo numero (B=%f)",numeroB);
            }
            else
            {
                printf("\n2. Ingresar el segundo numero (B=x)");
            }

        printf("\n3. Realizar los calculos");
        printf("\n4. Mostrar los resultados");
        printf("\n5. Salir");

        opcion=ingresarOpcion();
        switch(opcion)
        {
            case 1:
                banderaA=1;
          //      ingresarNumero("%f", &numeroA);
                break;

            case 2:
                banderaB=1;
            //    ingresarNumero("%f", &numeroB);
                break;

            case 3:
                if(banderaA==1 && banderaB==1)
                {
                    printf("\nCalculando la suma %.2f + %.2f ...",numeroA,numeroB);
                    printf("\nCalculando la resta %.2f - %.2f ...",numeroA,numeroB);
                    printf("\nCalculando la multiplicacion %.2f * %.2f ...",numeroA,numeroB);
                    printf("\nCalculando la division %.2f / %.2f ...",numeroA,numeroB);
                    printf("\nCalculando los factoriales de %.2f y %.2f ...",numeroA,numeroB);
                }
                else
                {
                    printf("\nError! Ingrese los 2 numeros...");
                }
                break;

            case 4:
                suma=sumar(numeroA,numeroB);
                printf("El resultado de la suma es %d\n", suma);

                resta=restar(numeroA,numeroB);
                printf("El resultado de la resta es %d\n", resta);

                multiplicacion=multiplicar(numeroA,numeroB);
                printf("El resultado de la multiplicacion es %d\n", multiplicacion);

                division=dividir(numeroA,numeroB);
                printf("El resultado de la division es %f\n", division);

                mostrarFactorial();
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


















 /*
    int resultado;
    int numeroA;
    int numeroB;
    int opcion;

    do
    {
        printf("\n--CALCULADORA--");
        printf("\n1.- Sumar");
        printf("\n2.- Restar");
        printf("\n3.- Multiplicar");
        printf("\n4.- Dividir");
        printf("\n5.- Salir");

        printf("\n\nElegir una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1: //SUMA
                printf("\nIntroduce el primer numero: ");
                scanf("%d",&numeroA);
                printf("\nIntroduce el segundo numero: ");
                scanf("%d",&numeroB);
                resultado=numeroA + numeroB;
                printf("\nLa suma es igual a: %d\n",numeroA,numeroB,resultado);
                break;

            case 2: //RESTA
                printf("\nIntroduce el primer numero: ");
                scanf("%d",&numeroA);
                printf("\nIntroduce el segundo numero: ");
                scanf("%d",&numeroB);
                resultado=numeroA - numeroB;
                printf("\nLa resta es igual a: %d\n",numeroA,numeroB,resultado);
                break;

            case 3: // MULTIPLICACION
                printf("\nIntroduce el primer numero: ");
                scanf("%d",&numeroA);
                printf("\nIntroduce el segundo numero: ");
                scanf("%d",&numeroB);
                resultado=numeroA * numeroB;
                printf("\nLa multiplicacion es igual a: %d\n",numeroA,numeroB,resultado);
                break;

            case 4: //DIVISION
                printf("\nIntroduce el primer numero: ");
                scanf("%d",&numeroA);
                printf("\nIntroduce el segundo numero: ");
                scanf("%d",&numeroB);
                resultado=numeroA / numeroB;
                printf("\nLa division es igual a: %d\n",numeroA,numeroB,resultado);
                break;

            case 5: //SALIR
                break;
        }

    } while (opcion!=5);

    return 0;
 */
