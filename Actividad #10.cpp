#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Andres.h"

#define N 500

struct Alumno
{
    int status;
    int matricula;
    char apPaterno[50];
    char apMaterno[50];
    char nombre[50];
    int edad;
    char sexo;
};

char nombres[10][50] = {"Juan", "Maria", "Pedro", "Ana", "Luis", "Laura", "Carlos", "Sofia", "Javier", "Isabel, Andres"};
char apellidosPaternos[10][50] = {"Gomez", "Rodriguez", "Perez", "Fernandez", "Lopez", "Martinez", "Gonzalez", "Diaz", "Sanchez", "Ramirez"};
char apellidosMaternos[10][50] = {"Hernandez", "Garcia", "Martinez", "Torres", "Vargas", "Moreno", "Jimenez", "Ortega", "Ruiz", "Castro"};

void llenarRegistroAlumno(struct Alumno *alumno)
{
    char entrada[50];

    do
    {
        printf("Status (1 para activo, 0 para inactivo): ");
        scanf("%s", entrada);
    } while (!esNumero(entrada) || !validarStatus(atoi(entrada)));

    alumno->status = atoi(entrada);

    do
    {
        printf("Matricula (entre 300000 y 399999): ");
        scanf("%s", entrada);
    } while (!esNumero(entrada) || !validarMatricula(atoi(entrada)));

    alumno->matricula = atoi(entrada);

    do
    {
        printf("Apellido Paterno: ");
        scanf("%s", entrada);
    } while (!soloLetras(entrada));
    strncpy(alumno->apPaterno, entrada, sizeof(alumno->apPaterno) - 1);

    do
    {
        printf("Apellido Materno: ");
        scanf("%s", entrada);
    } while (!soloLetras(entrada));
    strncpy(alumno->apMaterno, entrada, sizeof(alumno->apMaterno) - 1);

    do
    {
        printf("Nombre: ");
        scanf("%s", entrada);
    } while (!soloLetras(entrada));
    strncpy(alumno->nombre, entrada, sizeof(alumno->nombre) - 1);

    do
    {
        printf("Edad: ");
        scanf("%s", entrada);
    } while (!esNumero(entrada));

    alumno->edad = atoi(entrada);

    do
    {
        printf("Sexo (M o F): ");
        scanf("%s", entrada);
    } while (strlen(entrada) != 1 || (entrada[0] != 'M' && entrada[0] != 'F'));

    alumno->sexo = entrada[0];
}

void llenarRegistroAlumnoAleatorio(struct Alumno *alumno)
{
    alumno->status = rand() % 2;
    alumno->matricula = rand() % 100000 + 300000;

    strcpy(alumno->nombre, nombres[rand() % 10]);
    strcpy(alumno->apPaterno, apellidosPaternos[rand() % 10]);
    strcpy(alumno->apMaterno, apellidosMaternos[rand() % 10]);

    alumno->edad = rand() % 10 + 18;
    alumno->sexo = (rand() % 2 == 0) ? 'M' : 'F';
}

void mostrarRegistros(struct Alumno alumnos[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("Alumno %d:\n", i + 1);
        printf("Status: %d\n", alumnos[i].status);
        printf("Matricula: %d\n", alumnos[i].matricula);
        printf("Apellido Paterno: %s\n", alumnos[i].apPaterno);
        printf("Apellido Materno: %s\n", alumnos[i].apMaterno);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Edad: %d\n", alumnos[i].edad);
        printf("Sexo: %c\n", alumnos[i].sexo);
        if (i != cantidad - 1)
        {
            printf("\n");
        }
    }
}

void eliminarRegistrosInactivos(struct Alumno alumnos[], int *cantidad)
{
    int cantidadNueva = 0;
    for (int i = 0; i < *cantidad; i++)
    {
        if (alumnos[i].status == 1)
        {
            alumnos[cantidadNueva] = alumnos[i];
            cantidadNueva++;
        }
    }
    *cantidad = cantidadNueva;
}

void buscarPorMatricula(struct Alumno alumnos[], int cantidad)
{
    char entrada[50];
    int matriculaBuscada;

    do
    {
        printf("Digite la matricula del alumno que quiere buscar: ");
        scanf("%s", entrada);
    } while (!esNumero(entrada));

    matriculaBuscada = atoi(entrada);

    int encontrado = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (alumnos[i].matricula == matriculaBuscada)
        {
            printf("\tAlumno encontrado\n");
            printf("Status: %d\n", alumnos[i].status);
            printf("Matricula: %d\n", alumnos[i].matricula);
            printf("Apellido Paterno: %s\n", alumnos[i].apPaterno);
            printf("Apellido Materno: %s\n", alumnos[i].apMaterno);
            printf("Nombre: %s\n", alumnos[i].nombre);
            printf("Edad: %d\n", alumnos[i].edad);
            printf("Sexo: %c\n", alumnos[i].sexo);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("No hay alumnos con esta matricula\n");
    }
}

void ordenarAlumnosPorMatricula(struct Alumno alumnos[], int cantidad)
{
    struct Alumno temp;
    int swapped;

    for (int i = 0; i < cantidad - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < cantidad - i - 1; j++)
        {
            if (alumnos[j].matricula > alumnos[j + 1].matricula)
            {
                temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

void mostrarRegistrosOrdenados(struct Alumno alumnos[], int cantidad)
{

    ordenarAlumnosPorMatricula(alumnos, cantidad);
}

void mostrarRegistrosSinOrden(struct Alumno alumnos[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("Alumno %d:\n", i + 1);
        printf("Status: %d\n", alumnos[i].status);
        printf("Matricula: %d\n", alumnos[i].matricula);
        printf("Apellido Paterno: %s\n", alumnos[i].apPaterno);
        printf("Apellido Materno: %s\n", alumnos[i].apMaterno);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Edad: %d\n", alumnos[i].edad);
        printf("Sexo: %c\n", alumnos[i].sexo);
        if (i != cantidad - 1)
        {
            printf("\n");
        }
    }
}

void mostrarMenu()
{
    printf("\t ---------Menu--------\n");
    printf("1.- AGREGAR (AUTOM 10 REGISTROS)\n");
    printf("2.- AGREGAR MANUAL\n");
    printf("3.- ELIMINAR REGISTRO (logico)\n");
    printf("4.- BUSCAR\n");
    printf("5.- ORDENAR\n");
    printf("6.- IMPRIMIR\n");
    printf("0.- Salir\n");
}

int main()
{
    struct Alumno alumnos[50];
    int cantidadAlumnos = 0;

    srand(time(NULL));

    int opcion;

    do
    {
        mostrarMenu();
        printf("Digite una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:

            for (int i = cantidadAlumnos; i < cantidadAlumnos + 10; i++)
            {
                llenarRegistroAlumnoAleatorio(&alumnos[i]);
            }
            cantidadAlumnos += 10;
            printf("Registros agregados correctamente\n");
            break;
        case 2:
            do
            {
                if (cantidadAlumnos < 500)
                {
                    llenarRegistroAlumno(&alumnos[cantidadAlumnos]);
                    printf("Registro de alumno %d llenado.\n", cantidadAlumnos + 1);
                    cantidadAlumnos++;

                    if (cantidadAlumnos == 500)
                    {
                        printf("Se alcanzo el limete de registros que es de 500.\n");
                        break;
                    }

                    int agregarOtro;
                    do
                    {
                        printf("si desea agregar otro registro digita 1 para si, 0 para no: ");
                        scanf("%d", &agregarOtro);
                    } while (agregarOtro != 0 && agregarOtro != 1);

                    if (agregarOtro == 0)
                    {
                        break;
                    }
                }
                else
                {
                    printf("Se ha alcanzado el limite de 500 registros.\n");
                    break;
                }
            } while (1);
            break;
        case 3:
            eliminarRegistrosInactivos(alumnos, &cantidadAlumnos);
            printf("Se han eliminado los alumnos con status 0\n");
            break;
        case 4:
            buscarPorMatricula(alumnos, cantidadAlumnos);
            break;
        case 5:
            ordenarAlumnosPorMatricula(alumnos, cantidadAlumnos);
            break;
        case 6:
            mostrarRegistrosSinOrden(alumnos, cantidadAlumnos);
            break;
        case 0:
            printf("Salio del programa\n");
            break;
        default:
            printf("Opcion no valida. Digita una opcion valida\n");
        }
    } while (opcion != 0);

    return 0;
}
