#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int msges();
void menu();
void Calificaciones(void);
void Chinchampuani(void);
void Chinchampumul(void);
void Nummayor(void);
void Numedio(void);
void Numacen(void);
void Zodiaco(void);

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
  printf("1.- Calificaciones \n");
  printf("2.- Chinchampu Anidado \n");
  printf("3.- Chinchampu Multiple \n");
  printf("4.- Numero Mayor \n");
  printf("5.- Numero de enmedio \n");
  printf("6.- Numeros acendentes \n");
  printf("7.- Signo Zodiacal \n");
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
      Calificaciones();
      break;
    case 2:
      Chinchampuani();
      break;
    case 3:
      Chinchampumul();
      break;
    case 4:
      Nummayor();
      break;
    case 5:
      Numedio();
      break;
    case 6:
      Numacen();
      break;
    case 7:
      Zodiaco();
      break;
    }

  } while (op != 0);
}

void Calificaciones(void)
{
  float calif1, calif2, calif3, prom;
  system("CLS");

  printf("Ingrese la primera calificacion: ");
  scanf("%f", &calif1);

  printf("Ingrese la segunda calificacion: ");
  scanf("%f", &calif2);

  printf("Ingrese la tercera calificacion: ");
  scanf("%f", &calif3);

  prom = (calif1 + calif2 + calif3) / 3;

  if (prom < 30)
  {
    printf("Repetir\n");
  }
  else if (prom < 60)
  {
    printf("Extraordinario\n");
  }
  else if (prom < 70)
  {
    printf("Suficiente\n");
  }
  else if (prom < 80)
  {
    printf("Regular\n");
  }
  else if (prom < 90)
  {
    printf("Bien\n");
  }
  else if (prom < 98)
  {
    printf("Muy Bien\n");
  }
  else if (prom <= 100)
  {
    printf("Excelente\n");
  }
  else
  {
    printf("Error en promedio\n");
  }

  system("PAUSE");
}

void Chinchampuani(void)
{
  int jugador, maquina;

  system("CLS");

  srand(time(NULL));

  printf("Juego del Chinchampu\n");
  printf("1. Piedra\n");
  printf("2. Papel\n");
  printf("3. Tijera\n");
  printf("\nDigite una opcion: ");
  scanf("%d", &jugador);

  maquina = rand() % 3 + 1;

  printf("\nJugador: ");
  switch (jugador)
  {
  case 1:
    printf("Piedra\n");
    break;
  case 2:
    printf("Papel\n");
    break;
  case 3:
    printf("Tijera\n");
    break;
  default:
    printf("La opcion es incorrecta\n");
  }

  printf("Maquina: ");
  switch (maquina)
  {
  case 1:
    printf("Piedra\n");
    break;
  case 2:
    printf("Papel\n");
    break;
  case 3:
    printf("Tijera\n");
    break;
  }

  if (jugador == maquina)
  {
    printf("Es un empate\n");
  }
  else if ((jugador == 1 && maquina == 3) || (jugador == 2 && maquina == 1) || (jugador == 3 && maquina == 2))
  {
    printf("Eres el ganador\n");
  }
  else
  {
    printf("Gana la maquina\n");
  }

  system("PAUSE");
}

void Chinchampumul(void)
{
  int jugador, maquina;
  system("CLS");

  printf("Bienvenido al juego de Chunchampu\n");
  printf("Digite una opcion:\n");
  printf("1.Piedra\n");
  printf("2.Papel\n");
  printf("3.Tijera\n");
  scanf("%d", &jugador);

  maquina = rand() % 3 + 1;

  printf("\nMaquina: ");
  switch (maquina)
  {
  case 1:
    printf("Piedra\n");
    break;
  case 2:
    printf("Papel\n");
    break;
  case 3:
    printf("Tijera\n");
    break;
  }

  printf("\nJugador: ");
  switch (jugador)
  {
  case 1:
    printf("Piedra\n");
    break;
  case 2:
    printf("Papel\n");
    break;
  case 3:
    printf("Tijera\n");
    break;
  default:
    printf("Opcion incorrecta\n");
  }

  if (jugador == maquina)
  {
    printf("\nEs un empate\n");
  }
  else if ((jugador == 1 && maquina == 3) || (jugador == 2 && maquina == 1) || (jugador == 3 && maquina == 2))
  {
    printf("\nEres el ganador\n");
  }
  else
  {
    printf("\nLa maquina es la ganadora\n");
  }

  system("PAUSE");
}

void Nummayor(void)
{
  int num1, num2, num3;
  system("CLS");
  printf("Digite un numero: ");
  scanf("%d", &num1);
  printf("Digite un numero: ");
  scanf("%d", &num2);
  printf("Digite un numero: ");
  scanf("%d", &num3);

  if (num1 >= num2 && num1 >= 3)
  {
    printf("El numero mayor es el: %d", num1);
  }
  else
  {
    if (num2 >= num3)
    {
      printf("El numero mayor es el: %d", num2);
    }
    else
    {
      printf("El numero mayor es el: %d", num3);
    }
  }
  printf("   NUMERO MAYOR\n");
  system("PAUSE");
}

void Numedio(void)
{
  int num1, num2, num3;
  system("CLS");
  printf("Digite un numero: ");
  scanf("%d", &num1);
  printf("Digite un numero: ");
  scanf("%d", &num2);
  printf("Digite un numero: ");
  scanf("%d", &num3);

  if (num1 >= num2 && num1 <= num3)
  {
    printf("El numero de enmedio es: %d", num1);
  }
  else
  {
    if (num2 >= num1 && num2 <= num3)
    {
      printf("El numero de enmedio es: %d", num2);
    }
    else
    {
      if (num3 >= num2 && num3 <= num1)
      {
        printf("El numero de enmedio es: %d", num3);
      }
    }
  }
  system("PAUSE");
}

void Numacen(void)
{
  int num1, num2, num3;
  system("CLS");

  printf("Digite los valores de 3 numeros distintos: ");
  scanf("%d%d%d", &num1, &num2, &num3);

  if (num1 < num2)
  {
    if (num1 < num3)
    {
      if (num2 < num3)
      {
        printf("Los numeros de forma ascendente: %d %d %d\n\n", num1, num2, num3);
      }
      else
      {
        printf("Los numeros de forma ascendente: %d %d %d\n\n", num1, num3, num2);
      }
    }
    else
    {
      printf("Los numeros de forma ascendente: %d %d %d\n\n", num3, num1, num2);
    }
  }
  system("PAUSE");
}

void Zodiaco(void)
{
  int dia, mes;

  system("CLS");

  printf("Digite su mes de nacimiento con numero: ");
  scanf("%d", &mes);
  printf("Digite su dia de nacimiento con numero: ");
  scanf("%d", &dia);

  if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 19))
  {
    printf("\nSu signo zodiacal es Aries ");
    printf("\n");
    printf("\nHoroscopo del dia: Bajo la influencia de Mercurio, su mente estaa aguda. En ese sentido, es un buen momento para resolver problemas y tomar decisiones informadas ");
    printf("\n");
  } 
  else
  {
    if ((mes == 4 && dia >= 20) || (mes == 5 && dia <= 20))
    {
      printf("\nSu signo zodiacal es Tauro   ");
      printf("\n");
      printf("\nHoroscopo del dia: Mercurio le brinda una mente practica y enfocada. Aproveche esta energia y utilicela para abordar tareas pendientes con eficiencia. ");
      printf("\n");
    }
    else
    {
      if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20))
      {
        printf("\nSu signo zodiacal es Geminis   ");
        printf("\n");
        printf("\nHoroscopo del dia: Mercurio es su regente, lo que significa que su mente estara especialmente activa y adaptableesta jornada ");
        printf("\n");
      }
      else
      {
        if ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 22))
        {
          printf("\nSu signo zodiacal es Cancer   ");
          printf("\n");
          printf("\nHoroscopo del dia: Te esperan algunos imprevistos en el plano social o profesional. En el terreno emocional, tambien tendras inestabilidad");
          printf("\n");
        }
        else
        {
          if ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 22))
          {
            printf("\nSu signo zodiacal es Leo   ");
            printf("\n");
            printf("\nHoroscopo del dia: Mercurio le brinda la capacidad de comunicarse con confianza y persuasion, asi que sus ideas seran bien recibidas por los demas. ");
            printf("\n");
          }
          else
          {
            if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22))
            {
              printf("\nSu signo zodiacal es Virgo   ");
              printf("\n");
              printf("\nHoroscopo del dia: Bajo la influencia de Mercurio, su mente analitica sera un activo. En esta jornada, resuelva problemas y organice su dia con eficiencia ");
              printf("\n");
            }
            else
            {
              if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22))
              {
                printf("\nSu signo zodiacal es Libra   ");
                printf("\n");
                printf("\nHoroscopo del dia: Podrias tener problemas en el terreno amoroso hoy; si tienes pareja, quiza se enfade por las atenciones que tienes con una de tus amistades. ");
                printf("\n");
              }
              else
              {
                if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21))
                {
                  printf("\nSu signo zodiacal es Escorpio   ");
                  printf("\n");
                  printf("\nHoroscopo del dia: Bajo la influencia de Mercurio, su intuicion y profundidad emocional se destacan, asi que escuche su voz interior y profundice en sus investigaciones. ");
                  printf("\n");
                }
                else
                {
                  if ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21))
                  {
                    printf("\nSu signo zodiacal es Sagitario   ");
                    printf("\n");
                    printf("\nHoroscopo del dia: Por fin te sientes bien en tu piel, Sagitario. Estás en una etapa genial en la que sabes apreciar lo que has conseguido a diario con tu trabajo y tu esfuerzo, no solo en el terreno labora. ");
                    printf("\n");
                  }
                  else
                  {
                    if ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 19))
                    {
                      printf("\nSu signo zodiacal es Capricornio   ");
                      printf("\n");
                      printf("\nHoroscopo del dia: No pienses en problemas hoy, y si te apetece salir fuera, no lo dudes mas; te sentiras fenomenal con la visita a lugares que no conocias ");
                      printf("\n");
                    }
                    else
                    {
                      if ((mes == 1 && dia >= 20) || (mes == 2 && dia <= 18))
                      {
                        printf("\nSu signo zodiacal es Acuario   ");
                        printf("\n");
                        printf("\nHoroscopo del dia: Puede que tu pareja haya hecho planes con alguien y te moleste; no discutas, que tampoco te vas a morir porque no este a tu lado. ");
                        printf("\n");
                      }
                      else
                      {
                        if ((mes == 2 && dia >= 19) || (mes == 3 && dia <= 20))
                        {
                          printf("\nSu signo zodiacal es Picis   ");
                          printf("\n");
                          printf("\nHoroscopo del dia: Bajo la influencia de Mercurio, su sensibilidad y compasion se magnifican, asi que brinde apoyo a quienes lo necesitan y escuche a su intuicion. ");
                          printf("\n");
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  system("PAUSE");
}