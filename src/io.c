#include "io.h"

void entradaInit(Entrada *entrada)
{
  entrada->aFlag = 0;
  entrada->bFlag = 0;
  entrada->cFlag = 0;
  entrada->dFlag = 0;
  entrada->eFlag = 0;
  entrada->fFlag = 0;

  entrada->totalDias = 0;
  entrada->diasAway = 0;

  entrada->dinheiro = 0.;
  entrada->precoKmCarro = 0.;
  entrada->precoKmAviao = 0.;

  entrada->algoritmo = NULL;
  entrada->cidadeInicio = NULL;
}

int entradaLe(int argc, char** argv, Entrada *entrada)
{
  entradaInit(entrada);
  int c;
  while ((c = getopt(argc, argv, "a:b:c:")) != -1)
  {
    switch (c)
    {
      case 'a':
        entrada->aFlag = 1;
        entrada->totalDias = atoi(optarg);
        break;
      case 'b':
        entrada->bFlag = 1;
        entrada->cidadeInicio = optarg;
        break;
      case 'c':
        entrada->cFlag = 1;
        entrada->dinheiro = atof(optarg);
        break;
      case 'd':
        entrada->dFlag = 1;
        entrada->diasAway = atoi(optarg);
        break;
      case 'e':
        entrada->eFlag = 1;
        entrada->precoKmCarro = atof(optarg);
        break;
      case 'f':
        entrada->fFlag = 1;
        entrada->precoKmAviao = atof(optarg);
        break;
      case 'g':
        entrada->gFlag = 1;
        entrada->algoritmo = optarg;
        break;
    }
  }
  if (entrada->aFlag != 1 || entrada->bFlag != 1 || entrada->cFlag != 1
      || entrada->dFlag != 1 || entrada->eFlag != 1 || entrada->fFlag != 1
      || entrada->gFlag != 1)
  {
    printf("Os parâmetros não foram passados corretamente na linha de comando:\n\t");
    printf("%s -a <Quantidade total de dias de viagem> \n-b <Cidade que começa a viagem> \n-c <Dinheiro que possuem para viajar>", argv[0]);
    printf("\n-d <Quantidade máxima de dias sem visitar alguma região do Brasil> \n-e <Preço por Km para viajar de carro> \n-f");
    printf("<Preço por Km para viajar de avião> -g [otima|heuristica]\n");
    return 0;
  }

  entrada->distancias = fopen("distancias", "r");
  if (!entrada->distancias)
  {
    printf("O arquivo de distâncias não está correto.\n");
    return 0;
  }
  return 1;
}

void entradaFree(Entrada *entrada)
{
  fclose(entrada->distancias);
}
