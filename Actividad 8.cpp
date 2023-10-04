#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenarVector1(int vector1[], int n)
{
    printf("digite %d numeros para el vector 1 solo con numeros del 30 al 70:\n", n);
    for (int i = 0; i < n; i++)
    {
        do
        {
            scanf("%d", &vector1[i]);
        } while (vector1[i] < 30 || vector1[i] > 70);
    }
}

void llenarVector2(int vector2[], int n)
{
    srand(time(NULL));
    int numeros_disponibles[20];
    for (int i = 1; i <= 20; i++)
    {
        numeros_disponibles[i - 1] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int indice = rand() % (20 - i);
        vector2[i] = numeros_disponibles[indice];
        for (int j = indice; j < 19 - i; j++)
        {
            numeros_disponibles[j] = numeros_disponibles[j + 1];
        }
    }
}

void llenarVector3(int vector1[], int vector2[], int vector3[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i < 10)
        {
            vector3[i] = vector1[i];
        }
        else
        {
            vector3[i] = vector2[i - 10];
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

void llenarMatriz(int matriz[][4], int vector1[], int vector2[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i * 4 + j < 10)
            {
                matriz[i][j] = vector1[i * 4 + j];
            }
            else
            {
                matriz[i][j] = vector2[i * 4 + j - 10];
            }
        }
    }
}

void imprimirMatriz(int matriz[][4])
{
    printf("Matriz 4x4:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int opcion;
    int vector1[10];
    int vector2[10];
    int vector3[20];
    int matriz[4][4];

    do
    {
        printf("\nMENU DE VECTORES Y MATRIZ\n");
        printf("1. LLENAR VECTOR 1 (MANUEALMENTE)\n");
        printf("2. LLENAR VECTOR 2 ALEATORIAMENTE\n");
        printf("3. LLENAR VECTOR 3 CON VECTOR 1 Y VECTOR 2\n");
        printf("4. IMPRIMIR VECTORES\n");
        printf("5. LLENAR MATRIZ DE 4X4\n");
        printf("6. IMPRIMIR MATRIZ\n");
        printf("0. SALIR\n");
        printf("DIGITE UNA OPCION: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            llenarVector1(vector1, 10);
            break;
        case 2:
            llenarVector2(vector2, 10);
            break;
        case 3:
            llenarVector3(vector1, vector2, vector3, 20);
            printf("SE LLENO EL VECTOR 3\n");
            break;
        case 4:
            printf("VECTOR 1: ");
            imprimirVector(vector1, 10);
            printf("VECTOR 2: ");
            imprimirVector(vector2, 10);
            printf("VECTOR 3: ");
            imprimirVector(vector3, 20);
            break;
        case 5:
            llenarMatriz(matriz, vector1, vector2);
            printf("LA MATRIZ SE COMPLETO\n");
            break;
        case 6:
            imprimirMatriz(matriz);
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