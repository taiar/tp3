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

char* cidadeGetNome(int indice)
{
  return cidades[indice];
}

int cidadeGetRegiao(int cidade)
{
  int i, j;
  for (i = 0; i < N_REGIOES; i += 1)
    for (j = 0; j < N_MAX_CIDADES_REGIAO; j += 1)
      if ((regioes[i][j] >= 0) & (regioes[i][j] == cidade)) return i;
  return -1;
}

int cidadeGetCidadeMaisProximaRodoviaria(Viagem *viagem, grafo *grafo,
    Entrada *entrada)
{
  int i;
  int indCidadeMaisProxima = -1;
  int distanciaMaisProxima = -1;

  for (i = 0; i < N_CIDADES; i += 1)
  {
    // verificar primeiro se existe alguma regiao que deve ser atendida e formar um conjunto com
    // as cidades que devem ser analisadas
    // deve calcular melhor como fazer para visitar as cidades em um tempo melhor e fazer a
    // previsao do tempo caso preciso

    if ((viagem->visitado[i] == 0 &&
         grafo->distancias[viagem->cidadeAtual][i].rodoviaria
            < distanciaMaisProxima &&
         grafo->distancias[viagem->cidadeAtual][i].rodoviaria > 0)
        || ((indCidadeMaisProxima < 0 || distanciaMaisProxima < 0) && viagem->visitado[i] == 0))
    {
      indCidadeMaisProxima = i;
      distanciaMaisProxima
          = grafo->distancias[viagem->cidadeAtual][i].rodoviaria;
    }
  }
  return indCidadeMaisProxima;
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

  viagem->cidadeAtual = cidadeGetIndice(entrada->cidadeInicio);

  for (i = 0; i < N_CIDADES; i += 1)
    viagem->visitado[i] = 0;
  viagem->visitado[viagem->cidadeAtual] = 1;

  for (i = 0; i < N_CIDADES; i += 1)
    viagem->trajeto[i] = 0;
  viagem->trajeto[0] = viagem->cidadeAtual;

  for (i = 0; i < N_REGIOES; i += 1)
    viagem->diasSemVisitar[i] = 1;
  viagem->diasSemVisitar[cidadeGetRegiao(viagem->cidadeAtual)] = 0;

  viagem->cidadesVisitadasTotal = 1;
  viagem->diasTotal = 1;
  viagem->distanciaTotal = 0;
  viagem->custoTotal = .0;
}

void viagemVizinhoMaisProximo(Viagem *viagem, grafo *grafo, Entrada *entrada)
{
  int i;
  int proxCid = -1;
  while (viagem->cidadesVisitadasTotal < N_CIDADES)
  {
    proxCid = cidadeGetCidadeMaisProximaRodoviaria(viagem, grafo, entrada);
    viagem->visitado[proxCid] = 1;
    viagem->trajeto[viagem->cidadesVisitadasTotal] = proxCid;
    for (i = 0; i < N_REGIOES; i += 1)
      viagem->diasSemVisitar[i] += 1;
    viagem->diasSemVisitar[cidadeGetRegiao(proxCid)] = 0;
    viagem->distanciaTotal
        += grafo->distancias[viagem->cidadeAtual][proxCid].rodoviaria;
    viagem->cidadeAtual = proxCid;
    viagem->diasTotal += 1;
    viagem->cidadesVisitadasTotal += 1;
    viagem->custoTotal
        += grafo->distancias[viagem->cidadeAtual][proxCid].rodoviaria
            * entrada->precoKmCarro;
    printf("%s\n", cidadeGetNome(proxCid));
  }
}
