#ifndef __io__
#define __io__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * Armazena dados lidos da entrada.
 */
typedef struct
{
  int aFlag, bFlag, cFlag, dFlag, eFlag, fFlag, gFlag;
  int totalDias, diasAway;
  double dinheiro, precoKmCarro, precoKmAviao;
  char *cidadeInicio, *algoritmo;
  FILE *distancias;
} Entrada;

/**
 * Seta os valores iniciais da estrutura de entrada.
 */
void entradaInit(Entrada*);

/**
 * Faz leitura dos dados de entrada e os armazena.
 */
int entradaLe(int, char**, Entrada*);

/**
 * Libera dados utilizados na leitura da entrada.
 */
void entradaFree(Entrada*);

/**
 * Verifica dados passados na entrada.
 */
void entradaVerifica(Entrada*);

#endif
