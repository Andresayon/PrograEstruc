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
    } while (strlen(entrada) != 1 || (entrada[0] != 'M' || entrada[0] != 'F'));

    alumno->sexo = entrada[0];
}

void generarArchivoTexto(struct Alumno alumnos[], int cantidad)
{
    FILE *archivo = fopen("registros.txt", "w"); 
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return;
    }

    for (int i = 0; i < cantidad; i++)
    {
        if (alumnos[i].status == 1) 
        {
            fprintf(archivo, "Alumno %d:\n", i + 1);
            fprintf(archivo, "Status: %d\n", alumnos[i].status);
            fprintf(archivo, "Matricula: %d\n", alumnos[i].matricula);
            fprintf(archivo, "Apellido Paterno: %s\n", alumnos[i].apPaterno);
            fprintf(archivo, "Apellido Materno: %s\n", alumnos[i].apMaterno);
            fprintf(archivo, "Nombre: %s\n", alumnos[i].nombre);
            fprintf(archivo, "Edad: %d\n", alumnos[i].edad);
            fprintf(archivo, "Sexo: %c\n", alumnos[i].sexo);
            fprintf(archivo, "\n");
        }
    }

    fclose(archivo);
    printf("Archivo de texto generado exitosamente.\n");
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
    int registrosMostrados = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (alumnos[i].status == 1)
        {
            printf("Alumno %d:\n", i + 1);
            printf("Status: %d\n", alumnos[i].status);
            printf("Matricula: %d\n", alumnos[i].matricula);
            printf("Apellido Paterno: %s\n", alumnos[i].apPaterno);
            printf("Apellido Materno: %s\n", alumnos[i].apMaterno);
            printf("Nombre: %s\n", alumnos[i].nombre);
            printf("Edad: %d\n", alumnos[i].edad);
            printf("Sexo: %c\n", alumnos[i].sexo);

            registrosMostrados++;

            if (registrosMostrados % 40 == 0)
            {

                printf("Presione Enter para continuar...");
                while (getchar() != '\n')
                    ;
                getchar();
            }

            if (i != cantidad - 1)
            {
                printf("\n");
            }
        }
    }

    if (registrosMostrados % 40 != 0)
    {
        printf("Presione Enter para continuar...");
        while (getchar() != '\n')
            ;
        getchar();
    }
}

int buscarPorMatricula(struct Alumno alumnos[], int cantidad, int matriculaBuscada)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (alumnos[i].matricula == matriculaBuscada)
        {
            return i;
        }
    }
    return -1;
}

void eliminarRegistro(struct Alumno alumnos[], int *cantidad, int indice)
{

    if (indice != (*cantidad - 1))
    {
        alumnos[indice] = alumnos[*cantidad - 1];
    }
    (*cantidad)--;
}

void mostrarMenu()
{
    printf("\t ---------Menu--------\n");
    printf("1.- AGREGAR (AUTOM 100 REGISTROS)\n");
    printf("2.- ELIMINAR\n");
    printf("3.- BUSCAR\n");
    printf("4.- ORDENAR\n");
    printf("5.- IMPRIMIR\n");
    printf("6.- ARCHIVO DE TEXTO\n");
    printf("0.- Salir\n");
}

void ordenarAlumnosPorMatricula(struct Alumno alumnos[], int cantidad)
{
    struct Alumno temp;
    int decen = 0;

    for (int i = 0; i < cantidad - 1; i++)
    {
        if (alumnos[i].matricula > alumnos[i + 1].matricula)
        {
            decen = 1;
            break;
        }
    }

    if (decen)
    {

        for (int i = 0; i < cantidad - 1; i++)
        {
            for (int j = 0; j < cantidad - i - 1; j++)
            {
                if (alumnos[j].matricula > alumnos[j + 1].matricula)
                {
                    temp = alumnos[j];
                    alumnos[j] = alumnos[j + 1];
                    alumnos[j + 1] = temp;
                }
            }
        }
        printf("Se ordeno por el metodo de la burbuja\n");
    }
    else
    {

        printf("Ya se a ordenado el registro\n");
    }
}

int main()
{
    struct Alumno alumnos[N];
    int cantidadAlumnos = 0;
    srand(time(NULL));
    int opcion;

    do
    {
        mostrarMenu();
        printf("Digite una opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch (opcion)
        {
        case 1:
            if (cantidadAlumnos + 100 <= N)
            {
                for (int i = cantidadAlumnos; i < cantidadAlumnos + 100; i++)
                {
                    llenarRegistroAlumnoAleatorio(&alumnos[i]);
                }
                cantidadAlumnos += 100;
                printf("Se han agregado 100 registros aleatorios.\n");
            }
            else
            {
                printf("No se pueden agregar 100 registros aleatorios por que el arreglo esta lleno\n");
            }
            break;
        case 2:
            do
            {
                int matriculaBuscada;
                printf("Digite la matricula del alumno que desea eliminar: ");
                scanf("%d", &matriculaBuscada);

                int indice = buscarPorMatricula(alumnos, cantidadAlumnos, matriculaBuscada);
                if (indice != -1)
                {
                    eliminarRegistro(alumnos, &cantidadAlumnos, indice);
                    printf("Registro eliminado correctamente.\n");
                }
                else
                {
                    printf("No se encontro ningun registro con la matricula digitada.\n");
                }

                int eliminarOtro;
                do
                {
                    printf("Si desea eliminar otro registro, digite 1 para si, 0 para no: ");
                    scanf("%d", &eliminarOtro);
                } while (eliminarOtro != 0 && eliminarOtro != 1);

                if (eliminarOtro == 0)
                {
                    break;
                }
            } while (1);
            break;
        case 3:
        {
            int matriculaBuscada;
            printf("Digite la matricula del alumno que quiere buscar: ");
            scanf("%d", &matriculaBuscada);

            int indice = buscarPorMatricula(alumnos, cantidadAlumnos, matriculaBuscada);
            if (indice != -1)
            {
                printf("Registro encontrado:\n");
                printf("Status: %d\n", alumnos[indice].status);
                printf("Matricula: %d\n", alumnos[indice].matricula);
                printf("Apellido Paterno: %s\n", alumnos[indice].apPaterno);
                printf("Apellido Materno: %s\n", alumnos[indice].apMaterno);
                printf("Nombre: %s\n", alumnos[indice].nombre);
                printf("Edad: %d\n", alumnos[indice].edad);
                printf("Sexo: %c\n", alumnos[indice].sexo);
            }
            else
            {
                printf("No se encontro ningun registro con la matricula digitada.\n");
            }
        }
        break;
        case 4:
            ordenarAlumnosPorMatricula(alumnos, cantidadAlumnos);
            break;
        case 5:
            mostrarRegistros(alumnos, cantidadAlumnos);
            break;
        case 6:
            generarArchivoTexto(alumnos, cantidadAlumnos);
            break;
        case 0:
            printf("Salio del programa\n");
            break;
        default:
            printf("Opcinn no valida. Digite una opción valida\n");
        }
    } while (opcion != 0);

    return 0;
}
