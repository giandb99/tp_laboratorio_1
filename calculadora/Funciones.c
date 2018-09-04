#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*void ingresarNumero(float* numero)
{
   printf("\nIngrese un numero: ");
   fflush(stdin);
   scanf("%f %f", &numeroA,&numeroB);
}
*/
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

int mostrarFactorial()
{
    int i, numero,factorial=1;

    for(i=numero;i>=1;i--);
    {
        factorial *= i;
    }
}
