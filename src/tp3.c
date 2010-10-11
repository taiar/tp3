#include <stdio.h>
#include <stdlib.h>

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
  grafoImprime(&brasil);

  grafoFree(&brasil);
  entradaFree(&entrada);
  return EXIT_SUCCESS;
}
