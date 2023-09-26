#include <stdio.h>
#include <string.h>

void ensenada()
{
    char cadena1[] = {"ENSENADA"};
    printf("%s", cadena1);
    printf("\n");
}

void invertida(char *cadena)
{
    int tamano = strlen(cadena);
    char invertido[tamano + 1];

    for (int i = 0; i < tamano; i++)
    {
        invertido[i] = cadena[tamano - 1 - i];
    }
    invertido[tamano] = '\0';

    printf("%s\n", invertido);
}

void salto_linea(char *cadena)
{
    int tamano = strlen(cadena);

    for (int i = 0; i < tamano; i++)
    {
        printf("%c\n", cadena[i]);
    }
}

void salto_linea_invertido(char *cadena)
{
    int tamano = strlen(cadena);

    for (int i = tamano - 1; i >= 0; i--)
    {
        printf("%c\n", cadena[i]);
    }
}

void menos_caracter(char *cadena)
{
    int tamano = strlen(cadena);

    for (int i = 0; i < tamano; i++)
    {
        for (int j = 1; j < tamano - i; j++)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

void menos_invertido(char *cadena)
{
    int longitud = strlen(cadena);
    for (int i = 0; i < longitud; i++)
    {
        for (int j = longitud - 1; j >= i; j--)
        {
            printf("%c", cadena[j]);
        }
        printf("\n");
    }
}

void primer_caracter(const char *cadena)
{
    int tamano = strlen(cadena);

    for (int i = 0; i < tamano; i++)
    {
        printf("%s\n", cadena + i);
    }
}

void menos_caracter_invertido(const char *cadena)
{
    int tamano = strlen(cadena);
    const char *fin = cadena + tamano - 1;

    while (cadena <= fin)
    {
        for (const char *caracter = fin; caracter >= cadena; caracter--)
        {
            printf("%c", *caracter);
        }
        printf("\n");
        fin--;
    }
}

void solo_nsdn(const char *cadena)
{
    if (strcmp(cadena, "ENSENADA") == 0)
    {
        printf("NSDN\n");
    }
}

void solo_eeaa(const char *cadena)
{
    if (strcmp(cadena, "ENSENADA") == 0)
    {
        printf("EEAA");
    }
}

int main()
{
    char palabra[] = "ENSENADA";
    printf("Salida #1\n");
    ensenada();
    printf("Salida #2\n");
    invertida(palabra);
    printf("\nSalida #3\n");
    salto_linea(palabra);
    printf("\nSalida #4\n");
    salto_linea_invertido(palabra);
    printf("\nSalida #5\n");
    menos_caracter(palabra);
    printf("\nSalida #6\n");
    menos_invertido(palabra);
    printf("\nSalida #7\n");
    primer_caracter(palabra);
    printf("\nSalida #8\n");
    menos_caracter_invertido(palabra);
    printf("\nSalida #9\n");
    solo_nsdn(palabra);
    printf("\nSalida #10\n");
    solo_eeaa(palabra);

    return 0;
}