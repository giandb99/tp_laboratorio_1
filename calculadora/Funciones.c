#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief Pide el ingreso de un numero y lo almacena
 *
 * \param numeroA float* la direccion de memoria
 * \return void
 *
 */

void ingresarNumero(float* numeroA)
{
   printf("\nIngrese un numero: ");
   fflush(stdin);
   scanf("%f", numeroA);
}

/** \brief la funcion toma los 2 numeros digitados y los suma
 *
 * \param numero1 float
 * \param numero2 float
 * \return float  el resultado de numero1 + numero2
 *
 */

int sumar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1 + numero2;
    printf("El resultado de la suma es %.2f\n", resultado);
    return resultado;
}

/** \brief la funcion toma los 2 numeros digitados y los resta
 *
 * \param numero1 float
 * \param numero2 float
 * \return float  el resultado de numero1 - numero2
 *
 */

int restar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1 - numero2;
    printf("El resultado de la resta es %.2f\n", resultado);
    return resultado;
}

/** \brief la funcion toma los 2 numeros digitados y los multiplica
 *
 * \param numero1 float
 * \param numero2 float
 * \return float  el resultado de numero1 * numero2
 *
 */

int multiplicar(float numero1, float numero2)
{
    float resultado;
    resultado=numero1 * numero2;
    printf("El resultado de la multiplicacion es %.2f\n", resultado);
    return resultado;
}

/** \brief la funcion toma los 2 numeros digitados y los divide
 *
 * \param numero1 float
 * \param numero2 float
 * \return float  el resultado de numero1 / numero2
 *
 */


int dividir(float numero1, float numero2)
{
    float resultado;
    if(numero2==0)
    {
        printf("No es posible dividir por cero\n");
    }
    else
    {
        resultado=numero1 / numero2;
        printf("El resultado de la division es %.2f\n",resultado);
    }
    return resultado;
}

/** \brief la funcion toma un numero digitado y lo factoriza
 *
 * \param numero1 float
 * \return double la factorizacion de numero1
 *
 */

double mostrarFactorial(float numero1)
{
    int i;
    double resultado = 1;

   for(i=(int)numero1;i>=1;i--)
    {
        resultado=resultado*i;
    }
    printf("El factorial de %.2f es %.2lf \n",numero1, resultado);
    return (resultado);
}
