#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

#define QTY_CLIENTES 200

/** Realizar una agenda para guardar los datos d hasta 200 personas
 * de los cuales se toman los diferentes datos:
 * nombre, apellido, legajo(NO SE PUEDE REPETIR)
   OBJETIVO ES REALIZAR UN ABM DE LA AGENDA
   MOSTRAR EL LISTADO ORDENADO POR APELLIDO
 */

void inicializarArrayInt(int array[], int cantidad_de_elementos, int valor);
int buscarPrimeraOcurrencia(int array[], int cantidad_de_elementos, int valor);


int main()
{


    //ARRAY PARALELOS DONDE SE GUARDA LA INFORMACION
    char arrayNombres[QTY_CLIENTES][50];
    //INDICO LA CANTIDAD DE PERSONAS QUE SON 200 Y DESPUES LA CANTIDAD DE CARACTERES(TANTO NOMBRE COMO APELLIDO)
    char arrayApellido[QTY_CLIENTES][50];
    int arrayLegajos[QTY_CLIENTES];

    //---------------------------------------------

    //CUANDO VALIDEMOS
    char auxiliarNombreStr[50];
    char auxiliarApellidoStr[50];
    char auxiliarLegajoStr[50];
    int auxiliarLegajo;


    int indiceLugarLibre;
    int indiceResultadoBusqueda; //LA USO PARA DAR DE BAJA

    int opcion = 0;
    char auxiliarOpcionStr[50];

    int i, j;

    inicializarArrayInt(arrayLegajos, QTY_CLIENTES, -1); /**< se indica con -1 que esa posicion esta vacio */

    while(opcion != 6)
    {
        system("cls");
        if(!getStringNumeros("\n1. Alta \n2. Baja \n3. Modificar \n4. Listar \n5. Ordenar \n6. Salir \nIngrese un opcion: ", auxiliarOpcionStr))
        {
            printf("\nDEBE INGRESAR UN NUMERO\n");
            break;
        }

        opcion = atoi(auxiliarOpcionStr);

        switch(opcion)
        {

        case 1:
            //DETERMINAMOS SI ESTA LIBRE CUANDO ESTA EN -1
            indiceLugarLibre = buscarPrimeraOcurrencia(arrayLegajos, QTY_CLIENTES, -1);

            if(indiceLugarLibre == -1)
            {
                //PARA QUE SEA VERDAD NO TIENE QUE DEVOLVER -1
                printf("\n\nNO QUEDAN ESPACIOS LIBRES !!!\n");
                break;
            }

            printf("\nALTA\n"); //PARA SABER EN Q LUGAR ME ENCUENTRO

            //EMPIEZO A PEDIR LOS DATOS AL USUARIO PERO SIEMPRE VALIDANDO

            if(! getStringLetras("Ingrese el nombre: ", auxiliarNombreStr))
                //PREGUNTAMOS (SI SE DEVOLVIO) UN FALSO INDICAMOS LA CONDICION
            {
                printf("El nombre debe estar compuesto por letras\n");
                break;
            }

            if(! getStringLetras("Ingrese el apellido: ", auxiliarApellidoStr))
            {
                printf("El apellido debe estar compuesto por letras\n");
                break;
            }
            if(! getStringNumeros("Ingrese el legajo: ", auxiliarLegajoStr))
            {
                printf("El legajo debe contener numero");
                break;
            }

            //ATOI(CONVIERTE UN STRING A UN ENTERO
            auxiliarLegajo = atoi(auxiliarLegajoStr);

            //AHORA TENEGO QUE VERIFICAR SI ESE LEGAJO EXISTE O NO
            //TENGO UNA FUNCION QUE LO VERIFICA QUE SE LLAMA BUSCAR_PRIMERAOCURRENCIA
            //SI EXISTE, DEVUELVE ALGO DISTINTO A -1
            if(buscarPrimeraOcurrencia(arrayLegajos, QTY_CLIENTES, auxiliarLegajo) !=-1)
            {

                printf("\nEL LEGAJO YA EXISTE\n");
                break;
            }

            strcpy(arrayNombres[indiceLugarLibre], auxiliarNombreStr);
            strcpy(arrayApellido[indiceLugarLibre], auxiliarApellidoStr);
            arrayLegajos[indiceLugarLibre] = auxiliarLegajo;

            printf("\n\n");
            system("pause");

            break;

        case 2:

            if(!getStringNumeros("Ingrese el legajo a dar de baja: ", auxiliarLegajoStr))
            {
                printf("El legajo debe ser numerico");
                break;
            }

            indiceResultadoBusqueda = buscarPrimeraOcurrencia(arrayLegajos, QTY_CLIENTES, atoi(auxiliarLegajoStr));

            if(indiceResultadoBusqueda == -1)
            {

                printf("\nNO SE ENCUENTRA EL LEGAJO");
                break;
            }

            arrayLegajos[indiceResultadoBusqueda] = -1;

            printf("\n\n");
            system("pause");

            break;

        case 3:

            if(!getStringNumeros("Ingrese legajo a modificar: ", auxiliarLegajoStr))
            {

                printf("El legajo debe ser numerico");
                break;
            }

            indiceResultadoBusqueda = buscarPrimeraOcurrencia(arrayLegajos, QTY_CLIENTES, atoi(auxiliarLegajoStr));

            if(indiceResultadoBusqueda == -1)
            {
                printf("\nNO SE ENCUENTRA LEGAJO\n");
                break;
            }

            if(! getStringLetras("Ingrese nombre: ", auxiliarNombreStr))
            {

                printf("El nombre debe estar compuesto por letras\n");
                break;
            }

            if(! getStringLetras("Ingrese apellido: ", auxiliarApellidoStr))
            {

                printf("El apellido debe estar compuesto por letras\n");
                break;
            }

            //UNA VEZ MODIFICADO GUARDAMOS LA NUEVA INFORMACION
            strcpy(arrayNombres[indiceResultadoBusqueda], auxiliarNombreStr);
            strcpy(arrayNombres[indiceResultadoBusqueda], auxiliarApellidoStr);

            printf("\n\n");
            system("pause");

            break;

        case 4:

            printf("\nLISTAR\n");

            for(i=0; i<QTY_CLIENTES; i++)
            {

                //PREGUNTAMOS ESTO PQ SI ENCONTRAMOS UN -1(ES POR UNA PERSONA QUE SE DIO DE BAJA)
                if(arrayLegajos[i] != -1)
                {
                    printf("\nNOMBRE  \t APELLIDO \t LEGAJO");

                    printf("\n%s   -      %s        -   %d \n\n", arrayNombres[i], arrayApellido[i], arrayLegajos[i]);

                }

            }

            system("pause");

            break;

        case 5:

            //ORDENAMIENTO DE APELLIDO NADA MAS
            printf("\nORDENAR\n");

            for(i=0; i< QTY_CLIENTES -1; i++)
            {

                //CONDICION: POR SI SE DIO UNA BAJA LOGICA O NO SE CARGO NINGUN USUARIO
                if(arrayLegajos[i] == -1)
                {
                    continue; //REALIZA LA PROXIMA ITERACION
                }

                for(j= i+1; j< QTY_CLIENTES; j++)
                {

                    if(arrayLegajos[j] == -1)
                    {
                        continue;
                    }

                    //COMPARA LAS POSICION DE I Y DE J
                    if(strcmp(arrayApellido[i], arrayApellido[i]))
                    {

                      strcpy(auxiliarNombreStr, arrayNombres[i]);
                      strcpy(arrayNombres[i], arrayNombres[j]);
                      strcpy(arrayNombres[j], auxiliarNombreStr);

                      strcpy(auxiliarApellidoStr, arrayApellido[i]);
                      strcpy(arrayApellido[i], arrayApellido[j]);
                      strcpy(arrayApellido[j], auxiliarApellidoStr);

                      auxiliarLegajo = arrayLegajos[i];
                      arrayLegajos[i] = arrayLegajos[j];
                      arrayLegajos[j] = auxiliarLegajo;
                    }

                }
            }

            printf("\n\n");
            system("pause");

            break;


        }//LLAVE DE CIERRE DEL SWITCH

    }

    return 0;
}
/** \brief Inicializa un array de enteros con el valor recibido
 *
 * \param array Es el array a ser inicializado
 * \param cantiadad_de_elementos Indica la longitud del array
 * \return valor Es el valor que sera cargado en cada posicion
 *
 */

void inicializarArrayInt(int array[], int cantidad_de_elementos, int valor)
{

    int i;

    for(i=0; i<cantidad_de_elementos; i++)
    {

        array[i] = valor;

    }
}


/** \brief Busca la primera ocurrencia de un valor en un array de enteros
 * \param Array Es el array en el cual buscar
 * \param cantidad_de_elementos Indica la longitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencias (-1) y si hay la posicion de la misma(i)
 */

int buscarPrimeraOcurrencia(int array[], int cantidad_de_elementos, int valor)
{

    int i;

    for(i=0; i<cantidad_de_elementos; i++)
    {

        if(array[i] == valor)
        {
            return i;
        }

    }

    return -1;

}

void
