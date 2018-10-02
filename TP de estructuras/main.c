#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define E 2
#define VACIO 0
#define OCUPADO 1


int main()
{
    eEmployee listado[E];
    initEmployee(listado,E);
    int opcion;

    do
    {
        printf("1. Dar de alta de empleado\n2. Modificar\n3. Dar de baja un empleado\n4. Informar\n5. Salir\n");
        opcion=opcionA();
        switch(opcion)
        {
                case 1:
                    darDeAltaEmpleados(listado,E);
                    break;

                case 2:
                    while(listado[E].isEmpty==0)
                    {
                        printf("\nError! Primero debe dar de alta algun empleado\n");
                        printf("\nReingrese una opcion: ");
                        scanf("%d",&opcion);
                    }

                    modificarListadoDeEmpleados(listado,E);
                    break;

                case 3:
                    while(listado[E].isEmpty==0)
                    {
                        printf("\nError! Primero debe dar de alta algun empleado\n");
                        printf("\nReingrese una opcion: ");
                        scanf("%d",&opcion);
                    }

                    break;

                case 4:
                    while(listado[E].isEmpty==0)
                    {
                        printf("\nError! Primero debe dar de alta algun empleado\n");
                        printf("\nReingrese una opcion: ");
                        scanf("%d",&opcion);
                    }

                    mostrarListadoDeEmpleados(listado,E);
                    ordenarPorNombre(listado,E);
                    ordenarPorSector(listado,E);
                    break;

                default:
                    printf("\nLa opcion ingresada es invalida.\n");
                    printf("\nReingrese una opcion: ");
                    scanf("%d",&opcion);
                    break;
        }

    }while(opcion<1||opcion>5);

    return 0;
}

//initEmployee
