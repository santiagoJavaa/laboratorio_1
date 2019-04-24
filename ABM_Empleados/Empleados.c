#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleados.h"
#include "Funciones_Validar.h"

void inicializa_Empleados(eEmpleados empleaods[], int tamanioEmpleado)
{
    int i;

    for(i=0; i<tamanioEmpleado; i++)
    {
        empleaods[i].legajo_empleado = 0;
        empleaods[i].estado = 0;
    }
}

void datos_hardcode_Empleados(eEmpleados empleados[], int tamanioEmpleados)
{

    int legajo[]= {1,2,3,4},i;
    char nombre[][51]= {"Juan","Luis","Maria","Jose"};
    char apellido[][51]= {"Gaeta","Sanchez","Gomez","Lopez"};
    char sexo[][10]= {"masculino","masculino","femenino","masculino"};
    float salario[20]= {19000, 15000, 13000, 10000};
    char sector[][40]= {"Ingeniero","Programador","Tesorero","Limpieza"};

    inicializa_Empleados(empleados, tamanioEmpleados);

    for(i=0; i<4; i++)
    {
        empleados[i].legajo_empleado = legajo[i];
        strcpy(empleados[i].nombre, nombre[i]);
        strcpy(empleados[i].apellido,apellido[i]);
        strcpy(empleados[i].sexo, sexo[i]);
        empleados[i].salario = salario[i];
        strcpy(empleados[i].sector, sector[i]);

        empleados[i].estado = 1;
    }
}
void lista_empleados(eEmpleados empleados[], int tamanioEmpleados){

    int i;

    printf("\n LEGAJO   \tNOMBRE   \tAPELLIDO  \tSEXO   \tSECTOR  \t SALARIO \n");

    for(i=0; i<tamanioEmpleados; i++){

        if(empleados[i].estado == 1){

            printf("\n%3d    %15s    %15s    %s      %s    %f \n\n",empleados[i].legajo_empleado,
            empleados[i].nombre, empleados[i].apellido,
            empleados[i].sexo, empleados[i].sector, empleados[i].salario);
        }
    }
}
