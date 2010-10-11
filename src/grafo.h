#ifndef __GRAFO_H_
#define __GRAFO_H_

typedef struct
{
  int rodoviaria;
  int aerea;
} aresta;

typedef struct
{
  int nNos;
  aresta **distancias;
} grafo;

void grafoInicia(int, grafo*);
void grafoInsereAresta(int, int, aresta, grafo*);
aresta grafoRemoveAresta(int, int, grafo*);
void grafoImprime(grafo*);
void grafoFree(grafo*);

#endif
