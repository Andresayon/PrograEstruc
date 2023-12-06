#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "Andres.h"

struct curp
{
    char nombre[30];
    char appaterno[30];
    char apmaterno[30];
    char dia[30];
    char mes[30];
    char anio[30];
    char sexo[30];
    char estado[30];
} curp2 = {};

int main()
{
    system("cls");
    printf("\t***********************************************\n");
    printf("        **");
    printf("\t PROGRAMA QUE GENERA UN CURP        **\n"); 
    printf("\t***********************************************\n");
    printf("\n");
    printf("1.-GENERAR CURP\n");
    printf("2.-SALIR DEL PROGRAMA\n");
    int op = validar_programa_curp(1, 2, "\nDIGITA UNA OPCION: ");

    if (op == 2)
    {
        printf("\nSalio del programa");
        return 0;
    }

    system("cls");

    char curp[18];
    capt_datos();

    n_maria_jose(curp2.nombre);

    vali_nom_comp(curp2.nombre);
    vali_nom_comp(curp2.appaterno);
    vali_nom_comp(curp2.apmaterno);

    val_n_tilde(curp2.nombre);
    val_n_tilde(curp2.appaterno);
    val_n_tilde(curp2.apmaterno);

    vali_simbolos(curp2.nombre);
    vali_simbolos(curp2.appaterno);
    vali_simbolos(curp2.apmaterno);

    u_dieresis(curp2.nombre);
    u_dieresis(curp2.appaterno);
    u_dieresis(curp2.apmaterno);

    curp[0] = curp2.appaterno[0];
    curp[1] = curp2.appaterno[val_vocal(curp2.appaterno)];
    curp[2] = curp2.apmaterno[0];
    curp[3] = curp2.nombre[0];
    curp[4] = curp2.anio[2];
    curp[5] = curp2.anio[3];
    curp[6] = curp2.mes[0];
    curp[7] = curp2.mes[1];
    curp[8] = curp2.dia[0];
    curp[9] = curp2.dia[1];

    if (atoi(curp2.sexo) == 1)
    {
        curp[10] = 'H';
    }
    else
    {
        curp[10] = 'M';
    }

    int nest = atoi(curp2.estado);

    switch (nest)
    {
    case 0:
        curp[11] = 'N';
        curp[12] = 'E';
        break;

    case 1:
        curp[11] = 'A';
        curp[12] = 'S';
        break;

    case 2:
        curp[11] = 'B';
        curp[12] = 'C';
        break;

    case 3:
        curp[11] = 'B';
        curp[12] = 'S';
        break;

    case 4:
        curp[11] = 'C';
        curp[12] = 'C';
        break;

    case 5:
        curp[11] = 'C';
        curp[12] = 'L';
        break;

    case 6:
        curp[11] = 'C';
        curp[12] = 'M';
        break;

    case 7:
        curp[11] = 'C';
        curp[12] = 'S';
        break;

    case 8:
        curp[11] = 'C';
        curp[12] = 'H';
        break;

    case 9:
        curp[11] = 'D';
        curp[12] = 'F';
        break;

    case 10:
        curp[11] = 'D';
        curp[12] = 'G';
        break;

    case 11:
        curp[11] = 'G';
        curp[12] = 'T';
        break;

    case 12:
        curp[11] = 'G';
        curp[12] = 'R';
        break;

    case 13:
        curp[11] = 'H';
        curp[12] = 'G';
        break;

    case 14:
        curp[11] = 'J';
        curp[12] = 'C';
        break;

    case 15:
        curp[11] = 'M';
        curp[12] = 'C';
        break;

    case 16:
        curp[11] = 'M';
        curp[12] = 'N';
        break;

    case 17:
        curp[11] = 'M';
        curp[12] = 'S';
        break;

    case 18:
        curp[11] = 'N';
        curp[12] = 'T';
        break;

    case 19:
        curp[11] = 'N';
        curp[12] = 'L';
        break;

    case 20:
        curp[11] = 'O';
        curp[12] = 'C';
        break;

    case 21:
        curp[11] = 'P';
        curp[12] = 'L';
        break;

    case 22:
        curp[11] = 'Q';
        curp[12] = 'T';
        break;

    case 23:
        curp[11] = 'Q';
        curp[12] = 'R';
        break;

    case 24:
        curp[11] = 'S';
        curp[12] = 'P';
        break;

    case 25:
        curp[11] = 'S';
        curp[12] = 'L';
        break;

    case 26:
        curp[11] = 'S';
        curp[12] = 'R';
        break;

    case 27:
        curp[11] = 'T';
        curp[12] = 'C';
        break;

    case 28:
        curp[11] = 'T';
        curp[12] = 'S';
        break;

    case 29:
        curp[11] = 'T';
        curp[12] = 'L';
        break;

    case 30:
        curp[11] = 'V';
        curp[12] = 'Z';
        break;

    case 31:
        curp[11] = 'Y';
        curp[12] = 'N';
        break;

    case 32:
        curp[11] = 'Z';
        curp[12] = 'S';
        break;
    }

    curp[13] = curp2.appaterno[val_cons(curp2.appaterno)];
    curp[14] = curp2.apmaterno[val_cons(curp2.apmaterno)];
    curp[15] = curp2.nombre[val_cons(curp2.nombre)];

    int hc1 = atoi(curp2.anio);

    if (hc1 < 2000)
    {
        if (curp[4] == '0')
        {
            curp[16] = '0';
        }

        if (curp[4] == '1')
        {
            curp[16] = '1';
        }

        if (curp[4] == '2')
        {
            curp[16] = '2';
        }

        if (curp[4] == '3')
        {
            curp[16] = '3';
        }

        if (curp[4] == '4')
        {
            curp[16] = '4';
        }

        if (curp[4] == '5')
        {
            curp[16] = '5';
        }

        if (curp[4] == '6')
        {
            curp[16] = '6';
        }

        if (curp[4] == '7')
        {
            curp[16] = '7';
        }

        if (curp[4] == '8')
        {
            curp[16] = '8';
        }

        if (curp[4] == '9')
        {
            curp[16] = '9';
        }
    }
    else
    {
        if (curp[4] == '0')
        {
            curp[16] = 'A';
        }
        if (curp[4] == '1')
        {
            curp[16] = 'B';
        }
        if (curp[4] == '2')
        {
            curp[16] = 'C';
        }
        if (curp[4] == '3')
        {
            curp[16] = 'D';
        }
        if (curp[4] == '4')
        {
            curp[16] = 'E';
        }
        if (curp[4] == '5')
        {
            curp[16] = 'F';
        }
        if (curp[4] == '6')
        {
            curp[16] = 'G';
        }
        if (curp[4] == '7')
        {
            curp[16] = 'H';
        }
        if (curp[4] == '8')
        {
            curp[16] = 'I';
        }
        if (curp[4] == '9')
        {
            curp[16] = 'J';
        }
    }
    curp[17] = '\0';
    int nran = rand() % 10;
    sprintf(curp + strlen(curp), "%d", nran);
    curp[18] = '\0';

    palbra_altisonante(curp);

    printf("CURP: %s", curp);
    printf("\n");
    system("pause");
    system("cls");

    return main();
}

void capt_datos()
{
    vali_cad(curp2.nombre, "Nombre(s): ");

    vali_cad(curp2.appaterno, "Apellido paterno / x si no tiene: ");

    vali_cad(curp2.apmaterno, "Apellido materno / x si no tiene: ");
    system("cls");
    vali_cad_rango(curp2.anio, "Anio de nacimiento. Ejemplo 2002: ", 4, 1900, 2023);

    vali_cad_rango(curp2.mes, "Mes de nacimiento. Ejemplo 09: ", 2, 1, 12);

    vali_cad_rango(curp2.dia, "Dia de nacimiento. Ejemplo 07: ", 2, 1, val_dia_mes(atoi(curp2.dia), atoi(curp2.mes)));
    system("cls");
    printf("\nSexo: \n");
    printf("1.-HOMBRE\n");
    printf("2.-MUJER\n");
    vali_cad_rango(curp2.sexo, "\nDigite una opcion: ", 1, 1, 2);
    system("cls");

    menu_estados();
    vali_cad_rango(curp2.estado, "\nDigite una opcion. Ejemplo 02): ", 2, 0, 32);
    system("cls");
}

int val_n_tilde(char cadena[30])
{
    int i = 0;

    int lon = strlen(cadena);
    strupr(cadena);

    do
    {
        if (cadena[i] == -92)
        {
            cadena[i] = 'X';
        }
        i++;

    } while (i < lon);

    return 0;
}

int n_maria_jose(char cadena[30])
{
    strupr(cadena);
    int x = strlen(cadena);

    if (cadena[0] == 'M' && cadena[1] == 'A' && cadena[2] == 'R' && cadena[3] == 'I' && cadena[4] == 'A' && cadena[5] == ' ')
    {
        elim_m_j(cadena, 6, x);
    }

    if (cadena[0] == 'M' && cadena[1] == 'A' && cadena[2] == '.' && cadena[3] == ' ')
    {
        elim_m_j(cadena, 4, x);
    }

    if (cadena[0] == 'M' && cadena[1] == 'A' && cadena[2] == ' ')
    {
        elim_m_j(cadena, 3, x);
    }

    if (cadena[0] == 'M' && cadena[1] == '.' && cadena[2] == ' ')
    {
        elim_m_j(cadena, 3, x);
    }

    if (cadena[0] == 'M' && cadena[1] == ' ')
    {
        elim_m_j(cadena, 2, x);
    }

    if (cadena[0] == 'J' && cadena[1] == 'O' && cadena[2] == 'S' && cadena[3] == 'E' && cadena[4] == ' ')
    {
        elim_m_j(cadena, 5, x);
    }

    if (cadena[0] == 'J' && cadena[1] == '.' && cadena[2] == ' ')
    {
        elim_m_j(cadena, 3, x);
    }

    if (cadena[0] == 'J' && cadena[1] == ' ')
    {
        elim_m_j(cadena, 2, x);
    }

    return 0;
}

int u_dieresis(char cadena[30])
{
    int i = 0;

    strupr(cadena);
    int x = strlen(cadena);

    do
    {
        if (cadena[i] == -102)
        {
            cadena[i] = 'U';
        }
        i++;

    } while (i < x);

    return 0;
}

int vali_nom_comp(char cadena[30])
{
    int j = 1;

    strupr(cadena);

    do
    {
        j--;
        int x = strlen(cadena);
        if (cadena[0] == 'D' && cadena[1] == 'A' && cadena[2] == ' ')
        {
            elim_nom_comp(cadena, 3, x);
            j++;
        }
        if (cadena[0] == 'D' && cadena[1] == 'A' && cadena[2] == 'S' && cadena[3] == ' ')
        {
            elim_nom_comp(cadena, 4, x);
            j++;
        }
        if (cadena[0] == 'D' && cadena[1] == 'E' && cadena[2] == ' ')
        {
            elim_nom_comp(cadena, 3, x);
            j++;
        }
        if (cadena[0] == 'D' && cadena[1] == 'E' && cadena[2] == 'L' && cadena[3] == ' ')
        {
            elim_nom_comp(cadena, 4, x);
            j++;
        }
        if (cadena[0] == 'D' && cadena[1] == 'E' && cadena[2] == 'R' && cadena[3] == ' ')
        {
            elim_nom_comp(cadena, 4, x);
            j++;
        }
        if (cadena[0] == 'D' && cadena[1] == 'I' && cadena[2] == ' ')
        {
            elim_nom_comp(cadena, 3, x);
            j++;
        }
        if (cadena[0] == 'D' && cadena[1] == 'I' && cadena[2] == 'E' && cadena[3] == ' ')
        {
            elim_nom_comp(cadena, 4, x);
            j++;
        }
        if (cadena[0] == 'D' && cadena[1] == 'D' && cadena[2] == ' ')
        {
            elim_nom_comp(cadena, 3, x);
            j++;
        }
        if (cadena[0] == 'Y' && cadena[1] == ' ')
        {
            elim_nom_comp(cadena, 2, x);
            j++;
        }
        if (cadena[0] == 'E' && cadena[1] == 'L' && cadena[2] == ' ')
        {
            elim_nom_comp(cadena, 3, x);
            j++;
        }
        if (cadena[0] == 'L' && cadena[1] == 'A' && cadena[2] == ' ')
        {
            elim_nom_comp(cadena, 3, x);
            j++;
        }
        if (cadena[0] == 'L' && cadena[1] == 'O' && cadena[2] == 'S' && cadena[3] == ' ')
        {
            elim_nom_comp(cadena, 4, x);
            j++;
        }
        if (cadena[0] == 'L' && cadena[1] == 'A' && cadena[2] == 'S' && cadena[3] == ' ')
        {
            elim_nom_comp(cadena, 4, x);
            j++;
        }
        if (cadena[0] == 'L' && cadena[1] == 'E' && cadena[2] == ' ')
        {
            elim_nom_comp(cadena, 3, x);
            j++;
        }
        if (cadena[0] == 'L' && cadena[1] == 'E' && cadena[2] == 'S' && cadena[3] == ' ')
        {
            elim_nom_comp(cadena, 4, x);
            j++;
        }
        if (cadena[0] == 'M' && cadena[1] == 'A' && cadena[2] == 'C' && cadena[3] == ' ')
        {
            elim_nom_comp(cadena, 4, x);
            j++;
        }
        if (cadena[0] == 'M' && cadena[1] == 'C' && cadena[2] == ' ')
        {
            elim_nom_comp(cadena, 3, x);
            j++;
        }
        if (cadena[0] == 'V' && cadena[1] == 'A' && cadena[2] == 'N' && cadena[3] == ' ')
        {
            elim_nom_comp(cadena, 4, x);
            j++;
        }
        if (cadena[0] == 'V' && cadena[1] == 'O' && cadena[2] == 'N' && cadena[3] == ' ')
        {
            elim_nom_comp(cadena, 4, x);
            j++;
        }

    } while (j != 0);

    return 0;
}

int elim_nom_comp(char cad[30], int elim, int len)
{
    int i = 0;
    char copia[30];

    strrev(cad);

    strcpy(copia, cad);

    do
    {
        copia[len - i] = '\0';
        i++;
    } while (i <= elim);

    strrev(copia);
    strcpy(cad, copia);

    return 0;
}

int val_vocal(char cadena[30])
{
    int i = 1;

    int x = strlen(cadena);

    do
    {
        if (cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
        {
            return i;
        }
        i++;
    } while (i < x);

    cadena[i] = 'X';

    return i;
}

int vali_cad(char cadena[30], char msge[30])
{
    int i = 0;
    printf("%s", msge);
    fflush(stdin);
    scanf("%29s", cadena);

    strupr(cadena);
    int x = strlen(cadena);

    if (cadena[0] == '\0')
    {
        system("cls");
        printf("\nDEBE DE CONTENER EL DATO\n");
        return vali_cad(cadena, msge);
    }

    if (cadena[0] == ' ')
    {

        printf("\nSIN EESPACIOS\n");
        return vali_cad(cadena, msge);
    }

    do
    {
        if (isdigit(cadena[i]))
        {

            printf("\nSOLO LETRAS\n");
            return vali_cad(cadena, msge);
        }
        i++;
    } while (i < x);

    return 0;
}

int val_dia_mes(int dias, int mes)
{

    switch (mes)
    {
    case 1:
        dias = 31;
        break;

    case 2:
        dias = anio_bis(dias, atoi(curp2.anio));
        break;

    case 3:
        dias = 31;
        break;

    case 4:
        dias = 30;
        break;

    case 5:
        dias = 31;
        break;

    case 6:
        dias = 30;
        break;

    case 7:
        dias = 31;
        break;

    case 8:
        dias = 31;
        break;

    case 9:
        dias = 30;
        break;

    case 10:
        dias = 31;
        break;

    case 11:
        dias = 30;
        break;

    case 12:
        dias = 31;
        break;
    }

    return dias;
}
