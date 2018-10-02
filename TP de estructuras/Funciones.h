typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

int initEmployee(eEmployee listado[],int);
int buscarLibre(eEmployee listado[],int);
int siguienteId(eEmployee listado[],int);
int buscarPorId(eEmployee listado[],int,int);

int opcionA();

void darDeAltaEmpleados(eEmployee listado[],int);
int mostrarListadoDeEmpleados(eEmployee listado[],int);
void ordenarPorNombre(eEmployee listado[],int);
void modificarListadoDeEmpleados(eEmployee listado[],int);


void mostrarUnEmpleado(eEmployee);
eEmployee cargarUnEmpleado();
