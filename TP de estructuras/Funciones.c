#include "Funciones.h"
#include <stdio.h>
#include <string.h>
#define E 2
#define VACIO 0
#define OCUPADO 1

eEmployee cargarUnEmpleado()
{
    eEmployee miEmpleado;

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(miEmpleado.name);

    printf("\nIngrese apellido: ");
    fflush(stdin);
    gets(miEmpleado.lastName);

    printf("\nIngrese salario: ");
    scanf("%f",&miEmpleado.salary);

    printf("\nIngrese sector: ");
    scanf("%d",&miEmpleado.sector);

    return miEmpleado;
}

int opcionA()
{
    int opcion;
    printf("\nIngrese una opcion por favor: ");
    scanf("%d",&opcion);
    while(opcion<1||opcion>5)
    {
        printf("\nLa opcion ingresada es invalida.\nVuelva a ingresar una opcion por favor: ");
        scanf("%d",&opcion);
    }
    return opcion;
}

int initEmployee(eEmployee listado[],int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            listado[i].isEmpty= VACIO;
            listado[i].id= 1;
        }
    }
    return retorno;
}

int buscarLibre(eEmployee listado[],int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<tam;i++)
        {
            if(listado[i].isEmpty == VACIO)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int siguienteId(eEmployee listado[],int tam)
{
    int retorno = 0;
    int i;
    if(tam > 0 && listado != NULL)
    {
        for(i=0; i<tam; i++)
        {
            if(listado[i].isEmpty == OCUPADO)
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }
            }
        }
    }
    return retorno+1;
}

int buscarPorId(eEmployee listado[] ,int tam, int id)
{
    int retorno = -1;
    int i;
    if(tam > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<tam;i++)
        {
            if(listado[i].isEmpty == VACIO && listado[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void mostrarUnEmpleado(eEmployee unEmpleado)
{
    printf("\n%d---%s---%s---%.2f---%d\n",unEmpleado.id,unEmpleado.name,unEmpleado.lastName,unEmpleado.salary,unEmpleado.sector);
}

void darDeAltaEmpleados(eEmployee listado[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
       listado[i]=cargarUnEmpleado();
    }
}

int mostrarListadoDeEmpleados(eEmployee listado[],int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            if(listado[i].isEmpty==VACIO)
            {

                mostrarUnEmpleado(listado[i]);
            }
        }
    }
    return retorno;
}

void ordenarPorNombre(eEmployee listado[],int tam)
{
    int i;
    int j;

    eEmployee auxEmpleado;

    for(i=0;i<tam-1;i++)
    {
        for(j=i;j<tam;j++)
        {
            if(strcmp(listado[i].lastName,listado[j].lastName)>0)
            {
                auxEmpleado=listado[i];
                listado[i]=listado[j];
                listado[j]=auxEmpleado;
            }
        }
    }
}

void ordenarPorSector(eEmployee listado[],int tam)
{
    int i;
    int j;

    eEmployee auxSector;

    for(i=0;i<tam-1;i++)
    {
        for(j=i;j<tam;j++)
        {
            if(listado[i].sector<listado[j].sector)
            {
                auxSector=listado[i];
                listado[i]=listado[j];
                listado[j]=auxSector;
            }
        }
    }
}

void modificarListadoDeEmpleados(eEmployee listado[], int tam)
{
    eEmployee miEmpleado;
    int id;
    int i;
    int opcion;

    printf("Ingrese un id a buscar: ");
    scanf("%d",&id);

    for(i=0;i<tam;i++)
    {
            while(id==listado[i].id);
            {
                mostrarUnEmpleado(miEmpleado);
                printf("\n1. Modificar nombre\n2. Modificar apellido\n3. Modificar salario\n4. Modificar sector\n");
                printf("Que desea modificar? Elija una opcion: ");
                opcion = getchar();
                switch(opcion)
                {
                    case '1':
                            printf("\nIngrese el nuevo nombre: ");
                            fflush(stdin);
                            gets(miEmpleado.name);
                            break;
                    case '2':
                            printf("\nIngrese el nuevo apellido: ");
                            fflush(stdin);
                            gets(miEmpleado.lastName);
                            break;
                    case '3':
                            printf("\nIngrese el nuevo salario: ");
                            scanf("%f",&miEmpleado.salary);
                            break;
                    case '4':
                            printf("\nIngrese el nuevo sector: ");
                            scanf("%d",&miEmpleado.sector);
                            break;
                }
            }
    }
}
