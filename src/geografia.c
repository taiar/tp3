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
    if (strcmp(name, cidades[i]) == 0) return i;
  return -1;
}

int cidadeGetRegiao(int cidade)
{
  int i, j;
  for (i = 0; i < N_REGIOES; i += 1)
    for (j = 0; j < N_MAX_CIDADES_REGIAO; j += 1)
      if ((regioes[i][j] >= 0) & (regioes[i][j] == cidade)) return i;
  return -1;
}

void geografiaIniciaDistancias(grafo *grafo)
{
  grafoInicia(N_CIDADES, grafo);
}

void geografiaLeDistancias(Entrada *entrada, grafo *grafo)
{
  aresta buff;
  char buffCidadeA[20];
  char buffCidadeB[20];
  char buffDistAer[10];
  char buffDistRod[10];
  int n = (N_CIDADES * N_CIDADES) - N_CIDADES;
  int i;
  for (i = 0; i < n; i += 1)
  {
    fscanf(entrada->distancias, "%s %s %s %s", buffCidadeA, buffCidadeB,
        buffDistRod, buffDistAer);
    buff.rodoviaria = (strcmp(buffDistRod, "inf") == 0) ? -1
        : atoi(buffDistRod);
    buff.aerea = (strcmp(buffDistAer, "inf") == 0) ? -1 : atoi(buffDistAer);
    grafoInsereAresta(cidadeGetIndice(buffCidadeA),
        cidadeGetIndice(buffCidadeB), buff, grafo);
  }
}
