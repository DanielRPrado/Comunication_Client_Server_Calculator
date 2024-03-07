#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void leer(dir)
    char *dir;
{
    FILE *archivo;

    char caracteres[100];

    archivo = fopen("Prueba.txt","r");

    if (archivo == NULL)
    {
        printf("erro archivo no encontrado");
        exit(1);
    }
    else
    {
        while (feof(archivo) == 0)
        {
            fgets(caracteres,100,archivo);
        }
        strcpy(dir,caracteres);

    }

    fclose(archivo);
}
