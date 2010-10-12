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

void geografiaLeDistancias(Entrada *entrada, grafo *grafo)
{
  int i;
  aresta buff;
  char buffCidadeA[20];
  char buffCidadeB[20];
  char buffDistAer[10];
  char buffDistRod[10];
  int n = (N_CIDADES * N_CIDADES) - N_CIDADES;

  grafoInicia(N_CIDADES, grafo);

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

void viagemInicia(Viagem *viagem, Entrada *entrada)
{
  int i;
  for (i = 0; i < N_CIDADES; i += 1)
    viagem->visitado[i] = 0;
  for (i = 0; i < N_CIDADES; i += 1)
    viagem->trajeto[i] = 0;
  for (i = 0; i < N_REGIOES; i += 1)
    viagem->diasSemVisitar[i] = 0;
  viagem->cidadeAtual = cidadeGetIndice(entrada->cidadeInicio);
  viagem->diasTotal = 1;
  viagem->distanciaTotal = 0;
  viagem->custoTotal = .0;
}

void viagemVizinhoMaisProximo(Viagem *viagem, grafo *grafo, Entrada *entrada)
{

}
