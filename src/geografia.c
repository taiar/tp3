/*
 * geografia.c
 *
 *  Created on: 06/10/2010
 *      Author: taiar
 */

#include <string.h>

#include "geografia.h"

int cidadeGetIndice(char *name)
{
  int i;
  for (i = 0; i < N_CIDADES; i += 1)
    if (strcmp(name, cidades[i]) == 0)
      return i;
  return -1;
}

int cidadeGetRegiao(int cidade)
{
  int i, j;
  for (i = 0; i < N_REGIOES; i += 1)
    for (j = 0; j < N_MAX_CIDADES_REGIAO; j += 1)
      if(regioes[i][j] >= 0 & regioes[i][j] == cidade)
        return i;
}
