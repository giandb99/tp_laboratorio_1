#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ingresarNumero(float* numeroA)
{
   printf("\nIngrese un numero: ");
   fflush(stdin);
   scanf("%f", numeroA);
}

int sumar(float numero1, float numero2)
{
    float suma;
    suma=numero1 + numero2;
    return suma;
}

int restar(float numero1, float numero2)
{
    float resta;
    resta=numero1 - numero2;
    return resta;
}

int multiplicar(float numero1, float numero2)
{
    float multiplicacion;
    multiplicacion=numero1 * numero2;
    return multiplicacion;
}

int dividir(float numero1, float numero2)
{
    float division;
    division=numero1 / numero2;
    return division;
}

int mostrarFactorialA()
{
    int i;
    long long int factorial = 1;

    for(i;i>=1;i--)
    {
       factorial= factorial * i;
    }
    printf("El factorial del primer numero es: %lld\n\n",factorial);
    return factorial;

}

int mostrarFactorialB()
{
    int i;
    long long int factorial = 1;

    for(i;i>=1;i--)
    {
       factorial= factorial * i;
    }
    printf("El factorial del segundo numero es: %lld\n\n",factorial);
    return factorial;

}
