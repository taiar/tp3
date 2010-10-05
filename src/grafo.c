#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grafo.h"

void grafoInicia(int tamanho, grafo *g)
{
  int i, j;
  g->nNos = tamanho;

  g->matriz = malloc(sizeof(int*) * (g->nNos));
  for (i = 0; i < g->nNos; i += 1)
  {
    g->matriz[i] = malloc(sizeof(int) * (g->nNos));
    for (j = 0; j < g->nNos; ++j)
    {
      g->matriz[i][j] = 0;
    }
  }
  return;
}

void grafoInsereAresta(int cX, int cY, int peso, grafo *g)
{
  g->matriz[cX][cY] = peso;
  return;
}

int grafoRemoveAresta(int cX, int cY, grafo *g)
{
  int buff = g->matriz[cX][cY];
  g->matriz[cX][cY] = 0;
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
    free(g->matriz[i]);
  free(g->matriz);
}
