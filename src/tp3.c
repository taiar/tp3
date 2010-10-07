#include <stdio.h>
#include <stdlib.h>

#include "geografia.h"
#include "io.h"
#include "grafo.h"

int main(int argc, char **argv)
{
  Entrada entrada;

  entradaInit(&entrada);
  if(!entradaLe(argc, argv, &entrada))
    return EXIT_FAILURE;

  entradaVerifica(&entrada);
  entradaFree(&entrada);

  printf("O indice de São Paulo é %d, Huuuuuummmmmnnn!!!\n", cidadeGetIndice("saopaulo"));
  printf("Sao paula é da regiao %d\n", cidadeGetRegiao(cidadeGetIndice("saopaulo")));

  return EXIT_SUCCESS;
}
