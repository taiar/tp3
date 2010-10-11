#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "geografia.h"
#include "io.h"
#include "grafo.h"

int main(int argc, char **argv)
{
  Entrada entrada;
  grafo brasil;

  entradaInit(&entrada);
  if(!entradaLe(argc, argv, &entrada))
    return EXIT_FAILURE;

  iniciaDistancias(&brasil);
  leDistancias(&entrada, &brasil);

  // Calcula solução ótima do problema
  if(strcmp(entrada.algoritmo, "otima") == 0)
  {
    printf("otima\n");
  }

  // Calcula solução do problema utilizando heurística
  else if(strcmp(entrada.algoritmo, "heuristica") == 0)
  {
    printf("heuristica\n");
  }

  grafoFree(&brasil);
  entradaFree(&entrada);
  return EXIT_SUCCESS;
}
