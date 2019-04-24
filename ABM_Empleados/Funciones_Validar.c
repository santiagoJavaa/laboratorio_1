

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", input);
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringLetrasConSigno(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetrasConSigno(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosConSigno(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoConSigno(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFloat(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esNumericoConSigno(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') || (str[i] > 43 && str[i] < 47) || (str[i] > 47 && str[i] < 58))
            return 0;
        i++;
    }
    return 1;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (i == 0 && str[i] == '-')
        {
            i++;
            continue;

        }
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esSoloLetrasConSigno(char str[])
{
    int i = 0;
    while(str[i] != '\0' && str[i] == '-')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'));
        return 0;
        i++;
    }
    return 1;
}



