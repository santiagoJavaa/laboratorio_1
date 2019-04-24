#include <stdio.h>
#include <stdlib.h>
#include "Empleados.h"
#include "Funciones_Validar.h"

#define CANT_EMPLEADOS 100

int main()
{

    eEmpleados misEmpleados[CANT_EMPLEADOS];

    inicializa_Empleados(misEmpleados, CANT_EMPLEADOS);

    datos_hardcode_Empleados(misEmpleados, CANT_EMPLEADOS);

    lista_empleados(misEmpleados, CANT_EMPLEADOS);



    return 0;
}
