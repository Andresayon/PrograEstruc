#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define NUM_ALUMNOS 40
#define NUM_UNIDADES 5
#define N 10
int msges();
void menu();
void Examen(void);
void Tabla_Multiplicar(void);
void Rango(void);
void Turista(void);
void Alumno(void);
int main()
{
    menu();
    return 0;
}
int msges()
{
    int op;
    system("CLS");
    printf("M E N U\n");
    printf("1.-Examen\n");
    printf("2.-Tabla de multiplicar\n");
    printf("3.-Rango\n");
    printf("4.-Turistas\n");
    printf("5.-Alumno\n");
    printf("0.-Salir\n");
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
            Examen();
            break;
        case 2:
            Tabla_Multiplicar();
            break;
        case 3:
            Rango();
            break;
        case 4:
            Turista();
            break;
        case 5:
            Alumno();
            break;
        }
    } while (op != 0);
}
void Examen(void)
{

    float calif[NUM_ALUMNOS][NUM_UNIDADES];
    int no_derecho = 0;
    system("CLS");
    for (int i = 0; i < NUM_ALUMNOS; i++)
    {
        printf("Ingrese las calificaciones del alumno %d:\n", i + 1);
        for (int j = 0; j < NUM_UNIDADES; j++)
        {
            printf("Unidad %d: ", j + 1);
            scanf("%f", &calif[i][j]);
        }
    }
    for (int i = 0; i < NUM_ALUMNOS; i++)
    {
        float prom = 0.0;
        for (int j = 0; j < NUM_UNIDADES; j++)
        {
            prom += calif[i][j];
        }
        prom /= NUM_UNIDADES;
        if (prom < 50.0)
        {
            no_derecho++;
        }
    }
    printf("La cantidad de alumnos sin derecho a examen de nivelacion es: %d\n", no_derecho);
    printf(" Examen\n");
    system("PAUSE");
}
void Tabla_Multiplicar(void)
{
    char seguir;
    int i, numero;
    system("CLS");
    do
    {
        printf("\n Introduzca un n%cmero entero: ", 163);
        scanf("%d", &numero);
        printf("\n La tabla de multiplicar del %d es:\n", numero);

        for (i = 1; i <= 10; i++)
            printf("\n %d * %d = %d", i, numero, i * numero);
        printf("\n\n %cDesea ver otra tabla (s/n)?: ", 168);
        fflush(stdin);
        scanf("%c", &seguir);
    } while (seguir != 'n');

    printf(" Tabla de multiplicar\n");
    system("PAUSE");
}
void Rango(void)
{
    int n, a, b, num, sum = 0, count = 0;
    float m;
    system("CLS");
    printf("Digite la cantidad de numeros que desea leer: ");
    scanf("%d", &n);
    printf("Digite el rango del numero separdo por un espacio: ");
    scanf("%d %d", &a, &b);
    printf("Digite los %d numeros:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (num >= a && num <= b)
        {
            sum += num;
            count++;
        }
    }
    if (count > 0)
    {
        m = (float)sum / count;
        printf("La suma de los numeros es: %d\n", sum);
        printf("La media de los numeros es: %.2f\n", m);
    }
    else
    {
        printf("No se encontraron numeros dentro de ese rango\n");
    }

    printf(" Rango\n");
    system("PAUSE");
}
void Turista(void)
{
    int turistas = 0;
    float total = 0.0;
    float maximo = 700.0;
    float sobrante = 0.0;
    float promedio = 0.0;
    system("CLS");
    while (turistas < 10 && total < maximo)
    {
        float turista;
        printf("Ingrese el peso del turista %d: ", turistas + 1);
        scanf("%f", &turista);

        if (total + turista <= maximo * 1.15)
        {
            total += turista;
            turistas++;
        }
        else
        {
            sobrante = (total + turista) - (maximo * 1.15);
            printf("No se pueden agregar mas tristas ya que suoera el limite en un 15%% (sobrarian %.2f kg)\n", sobrante);
        }
    }

    promedio = total / turistas;

    if (turistas == 10)
    {
        printf("La embarcacion a alcanzado el maximo de turistas (10)\n");
    }
    else
    {
        printf("La embarcacion a alcanzado el limite de peso que son (700 kg)\n");
    }

    printf("El peso promedio por turista es de %.2f kg\n", promedio);
    printf(" Turista en embarcacion\n");
    system("PAUSE");
}
void Alumno(void)
{

    int intentos = 0;
    float prom = 0.0;
    system("CLS");

    while (intentos < 3)
    {
        float calif[3];

        //
        printf("Digite la calificacion del primer parcial: ");
        scanf("%f", &calif[0]);

        printf("Digite la calificacion del segundo parcial: ");
        scanf("%f", &calif[1]);

        printf("Digite la calificacion del tercer parcial: ");
        scanf("%f", &calif[2]);

        prom = (calif[0] + calif[1] + calif[2]) / 3.0;

        
        if (prom >= 60)
        {
            printf("Aprobaste la materia \n");
            break;
        }
        else
        {
            if (intentos < 2)
            {
                printf("Debe repetir la materia\n");
                printf("\n");
            }
            else
            {
                printf("Se le condisera baja temporal ya que no aprobo en ni uno de los 3 intentos\n");
            }
        }

        intentos++;
    }

    printf(" Alumno\n");
    system("PAUSE");
}