#include <stdio.h>
#include <time.h>
#include "Andres.h"
#include <fstream>
#include <string.h>
#include <stdlib.h>

struct numero_de_empleado
{
    int numeroempleado;
};

typedef struct _trabajador
{
    int status;
    int edad;
    struct numero_de_empleado nempleado;
    char appat[30];
    char apmat[30];
    char nombre[30];
    char sexo[3];
} Talum;

Talum numalum[5000];


int ban;
int n = 0;
const int MAXIMO = 1000;

int menu();
void Registro_Visible();
void Elegir(int op);
void Modificar_Registro();
void Editarlo(int numop, int aux2);
void Eliminar_Registro();
void Buscar_Trabajador();
void Agregar();
void Archivo_TXT();
void Archivo_Binario();
void cargararchivobinario();
void Registros_Borrados();
void Ordenar();
int Identificar(const void *a, const void *b);

int main()
{
    int op;
    srand(time(0));

    do
    {
        op = menu();
        Elegir(op);
    } while (op != 0);
    return 0;
}

int menu()
{
    int opc;
    char matricula[10];
    do
    {
        printf("\n");
        printf("\nMENU\n");
        printf("1.- AGREGAR (AUTOM 100 REGISTROS)\n");
        printf("2.- EDITAR REGISTRO\n");
        printf("3.- ELIMINAR REGISTRO (logico)\n");
        printf("4.- BUSCAR\n");
        printf("5.- ORDENAR\n");
        printf("6.- IMPRIMIR\n");
        printf("7.- GENERAR ARCHIVO TEXTO\n");
        printf("8.- VER ARCHIVO TEXTO\n");
        printf("9.- CREAR ARCH BINARIO\n");
        printf("10.- CARGAR ARCH BINARIO\n");
        printf("11.- MOSTRAR ELIMINADOS\n");
        printf("0.- Salir\n");
        printf("Digite una opcion: ");
        do
        {
            scanf("%s", matricula);
            opc = valinum(matricula);
        } while (opc == -1);
    } while (rangonum(0, 11, opc) != 1);
    return opc;
}

void Elegir(int op)
{
    system("cls");
    switch (op)
    {
    case 1:
        Agregar();
        printf("Registro agregado correctamente\n");
        break;
    case 2:
        Modificar_Registro();
        break;
    case 3:
        Eliminar_Registro();
        break;
    case 4:
        Buscar_Trabajador();
        break;
    case 5:
        Ordenar();
        printf("Se a ordenada");
        break;
    case 6:
        Registro_Visible();
        break;
    case 7:
        Archivo_TXT();
        printf("Archivo de texto generado");
        break;
    case 8:
        break;
    case 9:
        Archivo_Binario();
        printf("Archivo binario creado");
        break;
    case 10:
        cargararchivobinario();
        break;
    case 11:
        Registros_Borrados();
        break;
    }
}

void Agregar()
{
    if (n + 100 > MAXIMO)
    {
        printf("El registro esta lleno");
        return;
    }
    char nombresH[25][30] = {"OSCAR", "GABRIEL", "LUIS", "JAVIER", "CARLOS", "FERNANDO", "DIEGO", "ANTONIO", "ANDRES", "JOSE", "RAFAEL", "MIGUEL", "PEDRO", "ALBERTO", "HUGO", "EDUARDO", "RICARDO", "JORGE", "VICTOR", "FELIPE", "MARIO", "ALBERTO", "LUIS", "OSCAR", "SERGIO"};
    char nombresM[25][30] = {"CLAUDIA", "MARIA", "CARMEN", "GLORIA", "ALICIA", "ANA", "ROSA", "PAULA", "NATALIA", "LAURA", "SOFIA", "FABIOLA", "ELENA", "ISABEL", "MONICA", "CAMILA", "DANIELA", "ROSA", "VICTORIA", "MARTA", "LUCIA", "ANDREA", "SARA", "PATRICIA", "CLAUDIA"};
    char apellidos[50][30] = {"CABALLERO", "TORRES", "DELGADO", "RIVERA", "GOMEZ", "RODRIGUEZ", "NAVARRO", "MOLINA", "GUTIERREZ", "CHAVEZ", "CASTAÑO", "CRIOLLO", "MARTINEZ", "FLORES", "GARCIA", "SANCHEZ", "HERNANDEZ", "BLANCO", "CASTILLO", "MENDOZA", "VARGAS", "ROMERO", "ALVAREZ", "MORENO", "ROJAS", "MORALES", "ORTEGA", "CASTRO", "RUIZ", "DELGADO", "SILVA", "CASTAÑEDA", "HERRERA", "CASTAÑO", "CRUZ", "ARROYO", "COLLADO", "GALINDO", "VEGA", "JIMENEZ", "PINTO", "QUINTERO", "RAMIREZ", "CRUZ", "CABALLERO", "COSTA"};

    for (int i = 0; i < 100; i++)
    {

        numalum[n].status = 1;

        numalum[n].edad = rand() % 53 + 18;

        if (rand() % 2 == 1)
        {
            strcpy(numalum[n].sexo, "M");
            strcpy(numalum[n].nombre, nombresH[rand() % 15]);
        }
        else
        {
            strcpy(numalum[n].sexo, "F");
            strcpy(numalum[n].nombre, nombresM[rand() % 15]);
        }
        strcpy(numalum[n].appat, apellidos[rand() % 29]);
        strcpy(numalum[n].apmat, apellidos[rand() % 29]);

        numalum[n].nempleado.numeroempleado = rand() % (100001) + 300000;
        n++;
        ban = 0;
    }
}

void Registro_Visible()
{
    printf("%-4s %-10s %-15s %-15s %-15s %-4s %-4s\n", "Etatus", "Num Emp", "Nombre", "Appat", "Apmat", "Edad", "Sexo");
    for (int i = 0; i < n; i++)
    {
        printf("%-4d %-10d %-15s %-15s %-15s %-4d %-2s\n", numalum[i].status, numalum[i].nempleado.numeroempleado, numalum[i].nombre, numalum[i].appat, numalum[i].appat, numalum[i].edad, numalum[i].sexo);
    }
}

void Modificar_Registro()
{
    char matri[10];
    int num;
    Registro_Visible();
    do
    {
        printf("\nDigite el numero del empleado que desea cambiar: ");
        scanf("%s", matri);
        num = valinum(matri);
        printf("\n");
    } while (num == -1);

    int aux[MAXIMO];
    for (int i = 0; i < n; i++)
    {
        aux[i] = numalum[i].nempleado.numeroempleado;
    }

    int aux2;
    if (ban == 0)
    {
        aux2 = busquedasec(aux, num, n);
    }
    else
    {
        aux2 = busquedasecmejorada(aux, num, n);
    }

    if (aux2 != 1 && numalum[aux2].status == 1)
    {
        printf("%-4s %-10s %-15s %-15s %-15s %-4s %-4s\n", "Estatus", "Num Emp", "Nombre", "Appat", "Apmat", "Edad", "Sexo");
        printf("%-4d %-10d %-15s %-15s %-15s %-4d %-2s\n\n", numalum[aux2].status, numalum[aux2].nempleado.numeroempleado, numalum[aux2].nombre, numalum[aux2].appat, numalum[aux2].apmat, numalum[aux2].edad, numalum[aux2].sexo);

        printf("1.- Nombre \n");
        printf("2.- Apellido Paterno\n");
        printf("3.- Apellido Materno\n");
        printf("4.- Edad\n");
        printf("5.- Sexo\n");
        printf("\nDigite la opcion que desea modificar: ");
        do
        {
            scanf("%s", matri);
            num = valinum(matri);
        } while (num == -1 || rangonum(1, 5, num) != 1);
        Editarlo(num, aux2);

        printf("MODIFICADO\n");
        printf("%-5s %-12s %-15s %-15s %-15s %-6s %-5s\n", "Estatus ", "Num Emp ", "Nombre ", "Appat ", "Apmat ", "Edad ", "Sexo ");
        printf("%-5d %-12d %-15s %-15s %-15s %-6d %-5s\n\n", numalum[aux2].status, numalum[aux2].nempleado.numeroempleado, numalum[aux2].nombre, numalum[aux2].appat, numalum[aux2].apmat, numalum[aux2].edad, numalum[aux2].sexo);
    }
    else
    {
        printf("Este numero es incorrecto o no existe");
        printf("\n");
    }
}

void Editarlo(int op, int aux2)
{
    char aux[15];
    int num;
    int i;
    char matri[10];
    switch (op)
    {
    case 1:
        do
        {
            printf("\nNombre: ");
            fflush(stdin);
            fgets(aux, 15, stdin);
        } while (carvalido(aux) != 1);
        for (i = 0; i <= 15; i++)
        {
            if (aux[i] == '\n')
            {
                aux[i] = '\0';
            }
        }
        strcpy(numalum[aux2].nombre, aux);
        break;

    case 2:
        do
        {
            printf("\nApellido Paterno: ");
            fflush(stdin);
            fgets(aux, 15, stdin);
        } while (carvalido(aux) != 1);
        for (i = 0; i <= 15; i++)
        {
            if (aux[i] == '\n')
            {
                aux[i] = '\0';
            }
        }
        strcpy(numalum[aux2].appat, aux);
        break;

    case 3:
        do
        {
            printf("\nApellido Materno: ");
            fflush(stdin);
            fgets(aux, 15, stdin);
        } while (carvalido(aux) != 1);
        for (i = 0; i <= 15; i++)
        {
            if (aux[i] == '\n')
            {
                aux[i] = '\0';
            }
        }
        strcpy(numalum[aux2].appat, aux);
        break;

    case 4:
        printf("\nEdad: ");
        do
        {
            scanf("%s", matri);
            num = valinum(matri);
        } while (num == -1 || rangonum(18, 70, num) != 1);
        numalum[aux2].edad = num;
        break;

    case 5:
        printf("\nSexo");
        printf("\n1.- Hombre\n");
        printf("0.- Mujer\n");
        printf("Digite una opcion: ");
        do
        {
            scanf("%s", matri);
            num = valinum(matri);
        } while (num == -1 || rangonum(0, 1, num) != 1);
        if (num == 1)
        {
            strcpy(numalum[n].sexo, "M");
        }
        else
        {
            strcpy(numalum[n].sexo, "F");
        }
        break;
    }
}

void Eliminar_Registro()
{
    char matri[10];
    int num;
    printf("Digite el numero de empleado que desea eliminar: ");
    do
    {
        scanf("%s", matri);
        num = valinum(matri);
    } while (num == -1);

    int aux[MAXIMO];
    for (int i = 0; i < n; i++)
    {
        aux[i] = numalum[i].nempleado.numeroempleado;
    }

    int aux2;
    if (ban == 0)
    {
        aux2 = busquedasec(aux, num, n);
    }
    else
    {
        aux2 = busquedasecmejorada(aux, num, n);
    }

    if (aux2 != -1)
    {
        if (numalum[aux2].status == 0)
        {
            printf("Ya se elimino este numero");
        }
        else
        {
            numalum[aux2].status = 0;
        }
    }
    else
    {
        printf("No existe este numero de empleado");
    }
}

void Buscar_Trabajador()
{
    char matri[10];
    int num;
    printf("Digite el numero de empleado que desea buscar:  ");
    do
    {
        scanf("%s", matri);
        num = valinum(matri);
    } while (num == -1);

    int aux[MAXIMO];
    for (int i = 0; i < n; i++)
    {
        aux[i] = numalum[i].nempleado.numeroempleado;
    }

    int aux2;
    if (ban == 0)
    {
        aux2 = busquedasec(aux, num, n);
    }
    else
    {
        aux2 = busquedasecmejorada(aux, num, n);
    }
    if (aux2 != -1)
    {
        printf("%-4s %-10s %-15s %-15s %-15s %-4s %-4s\n", "EST", "NUM EMP", "NOMBRE", "APP", "APM", "EDAD", "SEXO");
        printf("%-4d %-10d %-15s %-15s %-15s %-4d %-2s\n\n", numalum[aux2].status, numalum[aux2].nempleado.numeroempleado, numalum[aux2].nombre, numalum[aux2].appat, numalum[aux2].apmat, numalum[aux2].edad, numalum[aux2].sexo);
    }
    else
    {
        printf("No se encontro este numero");
    }
}

void Archivo_TXT()
{
    char nombre[50];

    printf("Digite el nombre del archivo que desea crear: ");
    scanf("%s", nombre);

    FILE *archivo;
    strcat(nombre, ".txt");

    archivo = fopen(nombre, "w");
    if (archivo == NULL)
    {
        printf("Error\n");
        return;
    }
    else
    {
        fprintf(archivo, "%-4s %-10s %-15s %-15s %-15s %-4s %-4s\n", "EST", "NUM EMP", "NOMBRE", "APP", "APM", "EDAD", "SEXO");
        for (int i = 0; i < n; i++)
        {
            fprintf(archivo, "%-4d %-10d %-15s %-15s %-15s %-4d %-4s1\n",
                    numalum[i].status,
                    numalum[i].nempleado.numeroempleado,
                    numalum[i].nombre,
                    numalum[i].appat,
                    numalum[i].apmat,
                    numalum[i].edad,
                    numalum[i].sexo);
        }
    }
    fclose(archivo);
}

void Archivo_Binario()
{
    Talum reg;
    int i;
    FILE *f;
    f = fopen("datos.dll", "wb");
    if (f == NULL)
    {
        printf("Hubo un error al abrir el archivo");
        return;
    }
    for (i = 0; i < n; i++)
    {
        reg = numalum[i];
        fwrite(&reg, sizeof(Talum), 1, f);
    }
    fclose(f);
}

void cargararchivobinario()
{
    Talum reg;
    FILE *a;

    a = fopen("datos.dll", "rb");

    if (a)
    {
        while (fread(&reg, sizeof(Talum), 1, a))
        {
            numalum[n] = reg;
            n++;
            if (n >= MAXIMO)
            {
                printf("Este archivo tiene muchos registros\n");
                break;
            }
        }
    }
    else
    {
        printf("Hubo un error al abrir el  archivo");
    }
    fclose(a);
}

void Registros_Borrados()
{
    printf("%-4s %-10s %-15s %-15s %-15s %-4s %-4s\n", "Estatus", "Num Emp", "Nombre", "Appat", "Apmat", "Edad", "Sexo");

    for (int i = 0; i < n; i++)
    {
        if (numalum[i].status == 0)
        {
            printf("%-4d %-10d %-15s %-15s %-15s %-4d %-2s\n",
                   numalum[i].status, numalum[i].nempleado.numeroempleado, numalum[i].nombre,
                   numalum[i].appat, numalum[i].apmat, numalum[i].edad, numalum[i].sexo);
        }
    }
}

void Ordenar()
{

    if (n > 200)
    {
        qsort(numalum, n, sizeof(Talum), Identificar);
    }
    else
    {
        int i, j;
        Talum temp;

        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                if (numalum[j].nempleado.numeroempleado > numalum[j + 1].nempleado.numeroempleado)
                {
                    temp = numalum[j];
                    numalum[j] = numalum[j + 1];
                    numalum[j + 1] = temp;
                }
            }
        }
    }
}

int Identificar(const void *a, const void *b)
{
    return ((Talum *)a)->nempleado.numeroempleado - ((Talum *)b)->nempleado.numeroempleado;
}