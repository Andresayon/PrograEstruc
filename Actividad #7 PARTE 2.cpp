#include <stdio.h>
#include <string.h>

void Mayusculas(char *cadena)
{
	int i = 0;
	while (cadena[i])
	{
		if (cadena[i] >= 'a' && cadena[i] <= 'z')
		{
			cadena[i] = cadena[i] - ('a' - 'A');
		}
		i++;
	}
}

void Minusculas(char *cadena)
{
	int i = 0;
	while (cadena[i])
	{
		if (cadena[i] >= 'A' && cadena[i] <= 'Z')
		{
			cadena[i] = cadena[i] + ('a' - 'A');
		}
		i++;
	}
}

void Capital(char *cadena)
{
	int i = 0;
	int primeraLetra = 1;
	while (cadena[i])
	{
		if (cadena[i] >= 'a' && cadena[i] <= 'z')
		{
			if (primeraLetra)
			{
				cadena[i] = cadena[i] - ('a' - 'A');
				primeraLetra = 0;
			}
		}
		else if (cadena[i] >= 'A' && cadena[i] <= 'Z')
		{
			if (!primeraLetra)
			{
				cadena[i] = cadena[i] + ('a' - 'A');
			}
		}
		else
		{
			primeraLetra = 1;
		}
		i++;
	}
}

int Caracteres(char *cadena)
{
	int contador = 0;
	while (cadena[contador])
	{
		contador++;
	}
	return contador;
}

void Sin_Espacios(char *cadena)
{
	int i, j = 0;
	for (i = 0; cadena[i]; i++)
	{
		if (cadena[i] != ' ')
		{
			cadena[j] = cadena[i];
			j++;
		}
	}
	cadena[j] = '\0';
}

char *Cadena_invertida(char *cadena)
{
	int longitud = Caracteres(cadena);
	char temp;
	int i, j;

	for (i = 0, j = longitud - 1; i < j; i++, j--)
	{
		temp = cadena[i];
		cadena[i] = cadena[j];
		cadena[j] = temp;
	}

	return cadena;
}

int main()
{
	char cadena[100];
	char c;
	int i = 0;

	printf("Ingrese una cadena: ");

	while ((c = getchar()) != '\n' && i < sizeof(cadena) - 1)
	{
		cadena[i] = c;
		i++;
	}

	cadena[i] = '\0';

	Mayusculas(cadena);
	printf("Cadena en MAYUSCULAS: %s\n", cadena);

	Minusculas(cadena);
	printf("Cadena en minusculas: %s\n", cadena);

	Capital(cadena);
	printf("Cadena en CAPITAL: %s\n", cadena);

	int longitud = Caracteres(cadena);
	printf("Longitud de la cadena: %d\n", longitud);

	Sin_Espacios(cadena);
	printf("Cadena sin espacios: %s\n", cadena);

	char *cadenaInvertida = Cadena_invertida(cadena);
	printf("Cadena invertida: %s\n", cadenaInvertida);

	return 0;
}
