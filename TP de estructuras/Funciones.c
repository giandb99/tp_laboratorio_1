#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Funciones.h"

int menu()
{
    int opcion;
    char respuesta;
    int auxLibre;
    int auxId;
    int bandera;

    bandera=0;

    eEmployee listado[EMPLEADOS];
    initEmployees(listado,EMPLEADOS,-1);

    do
    {
        printf("1-ALTAS\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-SALIR\n");

        opcion=opcionF();

        switch(opcion)
        {
            case 1:
                auxLibre=searchFree(listado,EMPLEADOS,-1);
                if(auxLibre==-1)
                {
                    printf("\nNo hay mas lugar disponible.\n");
                }
                else
                {
                    printf("\nDesea ingresar un empleado? ");
                    respuesta=answerF();
                    if(respuesta=='n')
                    {
                        printf("\nNo se ingresara empleado\n");
                    }
                    else
                    {
                        printf("\nSe ingresara empleado\n");
                        addEmployees(listado,auxLibre);
                        bandera=1;
                    }
                }
                break;

            case 2:
                if(bandera==1)
                {
                    auxId=idF();
                    findEmployeeById(listado,EMPLEADOS,auxId);
                }
                else
                {
                    printf("\nError.Primero debe ingresar un empleado.\n");
                    system("pause");
                    system("cls");
                }
                break;

            case 3:
                if(bandera==1)
                {
                    auxId=idF();
                    removeEmployee(listado,EMPLEADOS,auxId);
                }
                else
                {
                    printf("\nError.Primero debe ingresar un empleado.\n");
                    system("pause");
                    system("cls");
                }
                break;

            case 4:
                if(bandera==1)
                {
                    sortEmployeeByLastName(listado,EMPLEADOS);
                    printEmployees(listado,EMPLEADOS);
                    sortEmployeeBySector(listado,EMPLEADOS);
                    printEmployees(listado,EMPLEADOS);
                    averages(listado,EMPLEADOS);
                }
                else
                {
                    printf("\nError.Primero debe ingresar un empleado.\n");
                    system("pause");
                    system("cls");
                }
                break;

            case 5:
                break;
        }
    }while(opcion!=5);

    return 0;
}

int opcionF()
{
    int opcion;

    printf("\nIngrese una opcion por favor: ");
    fflush(stdin);
    scanf("%d",&opcion);

    while(opcion<1||opcion>5)
    {
        printf("\nLa opcion ingresada no es valida.\n\nVuelva a ingresar una opcion por favor: ");
        scanf("%d",&opcion);
    }
    return opcion;
}

char answerF()
{
    char respuesta;

    printf("[N o S]: ");
    fflush(stdin);
    scanf("%c",&respuesta);
    system("cls");

    while(respuesta!='n'&&respuesta!='s')
    {
        printf("\nLa opcion ingresada no es valida. Ingrese N o S por favor: \n");
        fflush(stdin);
        scanf("%c",&respuesta);
        system("pause");
        system("cls");
    }
    return respuesta;
}

int idF()
{
    int id;
    printf("\nIngrese el ID: ");
    scanf("%d",&id);
    return id;
}

void initEmployees(eEmployee listado[],int len,int valor)
{
    int i;
    for(i=1;i<=len;i++)
    {
        listado[i].isEmpty=valor;
    }
}

int searchFree(eEmployee listado[],int len,int valor)
{
    int i;
    for(i=1;i<=len;i++)
    {
        if(listado[i].isEmpty==valor)
        {
            return i;
        }
    }
    return -1;
}

int addEmployees(eEmployee listado[],int auxLibre)
{
    int i;

    i=auxLibre;
    listado[i].id=auxLibre;
    printf("\nEl id del empleado es: %d\n",auxLibre);
    fflush(stdin);
    printf("\nIngrese nombre: ");
    gets(listado[i].name);
    fflush(stdin);

    printf("\nIngrese apellido: ");
    gets(listado[i].lastName);
    fflush(stdin);

    printf("\nIngrese salario: ");
    scanf("%f",&listado[i].salary);

    printf("\nIngrese sector: ");
    scanf("%d",&listado[i].sector);

    listado[i].isEmpty=0;

    system("pause");
    system("cls");

    return 0;
}

int findEmployeeById(eEmployee listado[],int len,int id)
{
    int i;
    int opcion;

    for(i=1;i<len;i++)
    {
        if(id==listado[i].id&&listado[i].isEmpty==0)
        {
            printf("\nSe puede modificar el empleado.\n");
            printf("\n1. Modificar nombre\n2. Modificar apellido\n3. Modificar salario\n4. Modificar sector\n");
            printf("\nQue desea modificar? Elija una opcion: ");
            fflush(stdin);
            scanf("%d",&opcion);

            while(opcion<1||opcion>4)
            {
                printf("\nLa opcion ingresada no es valida.\n\nVuelva a ingresar una opcion por favor: ");
                scanf("%d",&opcion);
            }

            switch(opcion)
            {

                case 1:
                        printf("\nIngrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(listado[i].name);

                        break;
                case 2:
                        printf("\nIngrese el nuevo apellido: ");
                        fflush(stdin);
                        gets(listado[i].lastName);
                        break;
                case 3:
                        printf("\nIngrese el nuevo salario: ");
                        fflush(stdin);
                        scanf("%f",&listado[i].salary);
                        break;
                case 4:
                        printf("\nIngrese el nuevo sector: ");
                        fflush(stdin);
                        scanf("%d",&listado[i].sector);
                        break;
                }
        }
    }
    return 0;
}

int removeEmployee( eEmployee listado[],int len,int id)
{
    int i;
    for(i=1;i<len;i++)
    {
        if(id==listado[i].id&&listado[i].isEmpty==0)
        {
            printf("\nEl empleado %s %s fue dado de baja.\n",listado[i].name,listado[i].lastName);
            listado[i].isEmpty=1;
        }
    }
    system("pause");
    system("cls");
    return 0;
}

void sortEmployeeByLastName(eEmployee listado[],int len)
{
    int i;
    int j;

    eEmployee auxLastName;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(listado[i].lastName>listado[j].lastName)
            {
                auxLastName=listado[i];
                listado[i]=listado[j];
                listado[j]=auxLastName;
            }
        }
    }
}

void sortEmployeeBySector(eEmployee listado[],int len)
{
    int i,j;

    eEmployee auxEmployee;

    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(listado[i].sector>listado[j].sector)
            {
                auxEmployee=listado[i];
                listado[i]=listado[j];
                listado[j]=auxEmployee;
            }
        }
    }
}

void printEmployees(eEmployee listado[],int len)
{
    int i;

    printf("---%4s---%12s---%12s---%10s---%5s---\n","ID","Nombre","Apellido","Salario","Sector");

    for(i=0;i<len;i++)
    {
        if(listado[i].isEmpty==0)
        {
            printf("\n---%4d---%12s---%12s---%10.2f---%5d---\n",listado[i].id,listado[i].name,listado[i].lastName,listado[i].salary,listado[i].sector);
            fflush(stdin);
        }
    }
    if(listado[i].isEmpty==1)
    {
        printf("\nNo se ha ingresado ningun empleado\n");
    }
}

void averages(eEmployee listado[],int len)
{
    int i;
    float acumulador=0;

    for(i=0;i<len;i++)
    {
        if(listado[i].isEmpty==0)
        {
            acumulador=acumulador+listado[i].salary;
            fflush(stdin);
        }
        else if(listado[i].isEmpty==1)
        {
            printf("\nNo se ha ingresado ningun salario\n");
        }
    }
    printf("\nEl total de los salarios es: %f.\n",acumulador);
    printf("\nEl salario promedio de los sueldos es: %f.\n",acumulador/i);
}
