#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Andres.h"

#define N 15

void llenarVector(int *vector, int n)
{
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        int num;
        int esRepetido;
        do
        {
            num = rand() % 101 + 100; 
            esRepetido = 0;
            for (int j = 0; j < i; j++)
            {
                if (vector[j] == num)
                {
                    esRepetido = 1;
                    break;
                }
            }
        } while (esRepetido);
        vector[i] = num;
    }
}

void llenarMatriz(int matriz[4][4])
{
    srand(time(NULL));
    int numeros[16];

    // Inicializa el arreglo de números del 1 al 16
    for (int i = 0; i < 16; i++)
    {
        numeros[i] = i + 1;
    }

    // Llena la matriz sin números repetidos
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int num_elementos = 16 - i * 4 - j;
            int indice = rand() % num_elementos;
            matriz[i][j] = numeros[indice];

            // Mueve el último elemento al lugar del número que se utilizó y actualiza el número de elementos
            numeros[indice] = numeros[num_elementos - 1];
        }
    }
}


void imprimirVector(int vector[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void imprimirMatriz(int matriz[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int opcion;
    int vector[N];
    int matriz[4][4];

    do
    {
        printf("\nMENU DE VECTORES Y MATRIZ\n");
        printf("1. LLENAR VECTOR\n");
        printf("2. LLENAR MATRIZ\n");
        printf("3. IMPRIMIR VECTOR\n");
        printf("4. IMPRIMIR MATRIZ\n");
        printf("5. ORDENAR VECTOR\n");
        printf("6. BUSCAR EN VECTOR\n");
        printf("0. SALIR\n");
        printf("DIGITE UNA OPCION: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            llenarVector(vector, N);
            break;

        case 2:
            llenarMatriz(matriz);
            break;

        case 3:
            printf("VECTOR: ");
            imprimirVector(vector, N);
            break;

        case 4:
            printf("MATRIZ:\n");
            imprimirMatriz(matriz);
            break;

        case 5:
            ordena_Vect(vector, N);
            printf("VECTOR ORDENADO DE FORMA ASCENDENTE: ");
            imprimirVector(vector, N);
            break;

        case 6:
            buscar_Numero_Vector(vector, N);
            break;

        case 0:
            printf("SALIDA\n");
            break;

        default:
            printf("POR FAVOR DIGITE SOLO UN NUMERO QUE APAREZCA EN EL MENU\n");
        }
    } while (opcion != 0);

    return 0;
}