#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int msges();
void menu();
void Numdecen(void);
void Numalea(void);
void Rango(void);
void Tablamul(void);

int main()
{
    menu();

    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- NUMEROS EN FORMA DESCENDENTES \n");
    printf("2.- NUMEROS ALEATORIOS \n");
    printf("3.- MAYOR Y MENOR \n");
    printf("4.- TABLA DE MULTIPLICAR \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            Numdecen();
            break;
        case 2:
            Numalea();
            break;
        case 3:
            Rango();
            break;
        case 4:
            Tablamul();
            break;
        }

    } while (op != 0);
}

void Numdecen(void)
{
    int n;
    system("CLS");
    printf("Digite un numero entero: ");
    scanf("%d", &n);

    for (int i = n - 1; i >= 1; i--)
    {

        printf("\n-%d", i);
        printf("\n");
    }
    system("PAUSE");
}

void Numalea(void)
{

    int num[40], pares = 0, impares = 0, sumapares = 0, sumaimpares = 0;

    system("CLS");

    srand(time(NULL));

    for (int i = 0; i < 40; i++)
    {
        num[i] = rand() % 201;
    }

    printf("Numeros aleatorios:\n");
    for (int i = 0; i < 40; i++)
    {
        printf("%d ", num[i]);
        if (num[i] % 2 == 0)
        {
            printf(" Par\n");
            pares++;
            sumapares += num[i];
        }
        else
        {
            printf(" Impar\n");
            impares++;
            sumaimpares += num[i];
        }
    }

    printf("\nResumen:\n");
    printf("Numeros pares: %d\n", pares);
    printf("Numeros impares: %d\n", impares);
    printf("La suma de los numeros pares: %d\n", sumapares);
    printf("La suma de los numeros impares: %d\n", sumaimpares);

    system("PAUSE");
}

void Rango(void)
{
    int n = 35, numeros[n], num_mayor = 100, num_menor = 201;

    system("CLS");
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        numeros[i] = rand() % 101 + 100;
        if (numeros[i] > num_mayor)
        {
            num_mayor = numeros[i];
        }
        if (numeros[i] < num_menor)
        {
            num_menor = numeros[i];
        }
    }

    printf("\tNumeros:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", numeros[i]);
    }

    printf("\nEl numero mayor es: %d\n", num_mayor);
    printf("El numero menor es: %d\n", num_menor);

    system("PAUSE");
}

void Tablamul(void)
{
    int num;

    system("CLS");

    printf("Digite un numero entero(1-20): ");
    scanf("%d", &num);

    printf("\tEsta es la tabla de multiplicar del numero %d ", num);

    for (int i = 1; i <= 10; i++)
    {
        printf("\n%dx%d = %i", num, i, num * i);
        
    }

    system("PAUSE");
}