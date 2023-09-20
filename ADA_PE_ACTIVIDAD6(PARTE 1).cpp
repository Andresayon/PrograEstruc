#include <stdio.h>
#include <stdlib.h>
#define N 10

int msges();
void menu();
void Fibonacci(void);
void Factorial(void);
void Digitos(void);

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
    printf("1.- FIBONACCI \n");
    printf("2.- FACTORIAL \n");
    printf("3.- DIGITOS \n");
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
            Fibonacci();
            break;
        case 2:
            Factorial();
            break;
        case 3:
            Digitos();
            break;
        }

    } while (op != 0);
}

void Fibonacci(void)
{
    int n, termino1 = 0, termino2 = 1, numeros, i = 0;
    int opc;

    system("CLS");

    printf("\nMENU");
    printf("\n1.-Fibonacci utilizando for");
    printf("\n2.-Fibonacci utilizando while");
    printf("\n3.-Fibonacci utilizando Do while");
    printf("\nDigite una opcion: ");
    scanf("%d", &opc);
    printf("\n");

    if (opc == 1)
    {
        printf("Digite la cantidad de numeros que desea: ");
        scanf("%d", &n);

        if (n <= 0)
        {
            printf("Tiene que ser un numero entero\n");
        }

        printf("%d Los numeros en la seria de Fibonacci son: ", n);

        for (int i = 0; i < n; i++)
        {
            printf("%d ", termino1);
            numeros = termino1 + termino2;
            termino1 = termino2;
            termino2 = numeros;
        }
    }

    else
    {
        if (opc == 2)
        {
            printf("Digite la cantidad de numeros que desea: ");
            scanf("%d", &n);

            if (n <= 0)
            {
                printf("Tiene que ser un numero entero\n");
            }

            printf("%d Los numeros en la seria de Fibonacci son: ", n);

            while (i < n)
            {
                printf("%d ", termino1);
                numeros = termino1 + termino2;
                termino1 = termino2;
                termino2 = numeros;
                i++;
            }
        }

        else
        {
            if (opc == 3)
            {
                printf("Digite la cantidad de numeros que desea: ");
                scanf("%d", &n);

                if (n <= 0)
                {
                    printf("Tiene que ser un numero entero\n");
                }

                printf("%d Los numeros en la seria de Fibonacci son: ", n);

                if (n > 0)
                {
                    printf("%d ", termino1);
                    i++;
                }

                do
                {
                    printf("%d ", termino1);
                    numeros = termino1 + termino2;
                    termino1 = termino2;
                    termino2 = numeros;
                    i++;
                } while (i < n);
            }
        }
    }

    printf("   FIBONACCI\n");
    system("PAUSE");
}

void Factorial(void)
{

    int opc, num;
    int factorial = 1;

    system("CLS");

    printf("\nMENU");
    printf("\n1.-Factorial utilizando for");
    printf("\n2.-Factorial utilizando while");
    printf("\n3.-Factorial utilizando Do while");
    printf("\nDigite una opcion: ");
    scanf("%d", &opc);
    printf("\n");

    if (opc == 1)
    {
        printf("Digite un numero para saber su factorial: ");
        scanf("%d", &num);

        if (num < 0)
        {
            printf("No se puede poner el factorial de un numero negativo\n");
        }
        else
        {

            for (int i = 1; i <= num; i++)
            {
                factorial *= i;
            }

            printf("Factorial del %d es %d\n", num, factorial);
        }
    }
    else
    {
        if (opc == 2)
        {
            printf("Digite un numero para saber su factorial: ");
            scanf("%d", &num);

            if (num < 0)
            {
                printf("No se puede poner el factorial de un numero negativo\n");
            }
            else
            {
                int i = 1;
                while (i <= num)
                {
                    factorial *= i;
                    i++;
                }

                printf("Factorial del %d es %d\n", num, factorial);
            }
        }

        else
        {
            if (opc == 3)
            {
                printf("Digite un numero para saber su factorial: ");
                scanf("%d", &num);

                if (num < 0)
                {
                    printf("No se puede poner el factorial de un numero negativo\n");
                }
                else
                {
                    int i = 1;
                    do
                    {
                        factorial *= i;
                        i++;
                    } while (i <= num);

                    printf("Factorial del %d es %d\n", num, factorial);
                }
            }
        }
    }

    printf("   FACTORIAL\n");
    system("PAUSE");
}

void Digitos(void)
{
    int opc, num, i = 0;

    system("CLS");

    printf("\nMENU");
    printf("\n1.-Cantidad de numeros utilizando for");
    printf("\n2.-Cantidad de numeros utilizando while");
    printf("\n3.-Cantidad de numeros utilizando Do while");
    printf("\nDigite una opcion: ");
    scanf("%d", &opc);
    printf("\n");

    if (opc == 1)
    {
        printf("Digite un numero entero: ");
        scanf("%d", &num);

        if (num < 0)
        {
            num = -num;
        }

        for (; num != 0; num /= 10)
        {
            i++;
        }

        printf("Cantidad de digitos que tiene el numero: %d \n", i);
    }
    else
    {
        if (opc == 2)
        {
            printf("Digite un numero entero: ");
            scanf("%d", &num);

            if (num < 0)
            {
                num = -num;
            }

            while (num != 0)
            {
                i++;
                num /= 10;
            }

            printf("Cantidad de digitos que tiene el numero: %d \n", i);
        }
        else
        {
            if (opc == 3)
            {
                printf("Digite un numero entero: ");
                scanf("%d", &num);

                if (num < 0)
                {
                    num = -num;
                }

                do
                {
                    i++;
                    num /= 10;
                } while (num != 0);

                printf("Cantidad de digitos que tiene el numero: %d \n", i);
            }
        }
    }

    printf("   DIGITOS\n");
    system("PAUSE");
}