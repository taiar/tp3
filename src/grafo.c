#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grafo.h"

void grafoInicia(int tamanho, grafo *g)
{
  int i, j;
  g->nNos = tamanho;

  g->distancias = malloc(sizeof(aresta*) * (g->nNos));
  for (i = 0; i < g->nNos; i += 1)
  {
    g->distancias[i] = malloc(sizeof(aresta) * (g->nNos));
    for (j = 0; j < g->nNos; ++j)
    {
      g->distancias[i][j].aerea = -1;
      g->distancias[i][j].rodoviaria = -1;
    }
  }
  return;
}

void grafoInsereAresta(int cX, int cY, int peso, grafo *g)
{
  g->matriz[cX][cY] = peso;
  return;
}

aresta grafoRemoveAresta(int cX, int cY, grafo *g)
{
  aresta buff = g->distancias[cX][cY];
  g->distancias[cX][cY].aerea = -1;
  g->distancias[cX][cY].rodoviaria = -1;
  return buff;
}

void grafoImprime(grafo *g)
{
  int i, j;
  for (i = 0; i < g->nNos; ++i)
  {
    for (j = 0; j < g->nNos; ++j)
      printf("%d\t", g->matriz[i][j]);
    printf("\n");
  }
  return;
}

void grafoFree(grafo *g)
{
  int i;
  for (i = 0; i < g->nNos; i += 1)
    free(g->distancias[i]);
  free(g->distancias);
}
