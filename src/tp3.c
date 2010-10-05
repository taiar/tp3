#include <stdio.h>
#include <stdlib.h>

#include "io.h"
#include "grafo.h"

int main(int argc, char **argv)
{
  Entrada entrada;

  entradaInit(&entrada);
  if(!entradaLe(argc, argv, &entrada))
    return EXIT_FAILURE;

  entradaVerifica(&entrada);

  return EXIT_SUCCESS;
}
