#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define M 500

void vali_num2(int *opcion)
{
    int input;
    do
    {
        printf("DIGITE UNA OPCION: ");
        if (scanf("%d", &input) != 1 || input < 0 || input > 6)
        {
            printf("El numero debe ser de entre el 0 y 6\n");
            while (getchar() != '\n')
                ;
        }
        else
        {
            *opcion = input;
        }
    } while (*opcion < 0 || *opcion > 6);
}

void vali_num(const char *cad)
{
    if (cad == NULL || *cad == '\0')
    {
        printf("Debes ingresar un numero valido\n");
        return;
    }

    int i = 0;

    if (cad[i] == '-')
    {
        i++;
    }

    while (cad[i] != '\0')
    {
        if (!isdigit(cad[i]))
        {
            printf("No es valido\n");
            return;
        }
        i++;
    }
    printf("Numero valido\n");
}

void vali_Caracter(char caracter)
{
    if ((caracter >= 'a' && caracter <= 'z') || (caracter >= 'A' && caracter <= 'Z'))
    {
        printf("Es letra\n");
    }
    else
    {
        printf("Esto no es una letra\n");
    }
}

void ordena_Vect(int vector[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

void buscar_Numero_Vector(int vector[], int n)
{
    int valor;
    int encontrado = 0;

    while (1)
    {
        printf("Digite un numero que desea buscar (100-200): ");
        if (scanf("%d", &valor) == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (vector[i] == valor)
                {
                    printf("El numero %d si esta y se encuentra en la posicion %d del vector.\n", valor, i);
                    encontrado = 1;
                    break;
                }
            }

            if (!encontrado)
            {
                printf("El numero %d no esta en el vector\n", valor);
            }
            break;
        }
        else
        {
            printf("El tipo de dato debe ser un numero entero\n");
            while (getchar() != '\n')
                ;
        }
    }
}



char validarSexo(char valor)
{
    return (valor == 'M' || valor == 'F');
}

int esNumero(char *cadena)
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (!isdigit(cadena[i]))
        {
            return 0;
        }
    }
    return 1;
}

int validarStatus(int status)
{
    return (status == 0 || status == 1);
}

int validarMatricula(int matricula)
{
    return (matricula >= 300000 && matricula <= 399999);
}

int soloLetras(char *cadena)
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (!isalpha(cadena[i]))
        {
            return 0;
        }
    }
    return 1;
}




